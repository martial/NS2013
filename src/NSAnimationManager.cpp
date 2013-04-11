//
//  NSAnimationManager.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSAnimationManager.h"
#include "Globals.h"

NSAnimationManager::NSAnimationManager () {
    
}

void NSAnimationManager::setup() {
    
    initJS();
    
    currentIndex        = 0;
    speedPct            = 1.0;
    globalCount         = 0;
    globalSpeed         = 100;
    
    listAnimations();
    //(0, 0);
    
    
    
}

void NSAnimationManager::listAnimations() {
    
    // Scripts
    
    animations.clear();
    currentIndex        = 0;
    
    // store value to reload in case
    string oldScriptName = "";
    if(Globals::instance()->nsSceneManager->getScene(0)->animationRef)
        oldScriptName = Globals::instance()->nsSceneManager->getScene(0)->animationRef->scriptName;
    
    for (int i=0; i<  Globals::instance()->nsSceneManager->getNumScenes(); i++) {
        if(Globals::instance()->nsSceneManager->getScene(i)->animationRef)
            Globals::instance()->nsSceneManager->getScene(i)->animationRef.reset();
    }
    
    
    
	ofDirectory dirScripts("js");
	if (dirScripts.exists())
	{
		dirScripts.listDir();
        
		printf("DIR %s [%d file(s)]\n", dirScripts.path().c_str(),dirScripts.size());
        
		vector<ofFile> files = dirScripts.getFiles();
		vector<ofFile>::iterator it;
        int i=0;
		for (it = files.begin(); it != files.end(); ++it){
			if ((*it).getExtension() == "js")
			{
				 printf("- [%s] path=%s\n", (*it).getFileName().c_str(), (*it).getAbsolutePath().c_str());
                                
                 ofPtr<NSAnimation> animationRef(new NSAnimation());
                 animationRef->setup(ofToDataPath((*it).getAbsolutePath()), i);
                 ofAddListener(animationRef->needReload, this, &NSAnimationManager::onScriptChanged);
                 animations.push_back(animationRef);
                 i++;

			}
		}
	}
	dirScripts.close();
    
    if(oldScriptName.size() == 0) {
        setAnimation(0, 0);
    } else {
        setAnimation(oldScriptName, 0);
    }
    //setAnimation(0, 1);
    
}

vector<string> NSAnimationManager::getAnimations() {
    
    vector<string> result;
    for (int i=0; i<animations.size(); i++) {
        result.push_back(animations[i]->scriptName);
    }
    
    return result;
    
}

void NSAnimationManager::setAnimation(int index, int scene) {
    
    //currentIndex = ofClamp(index, 0, animations.size()-1);
    
    // set animation to scene
    
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef.reset();
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef = animations[index];
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef->init(scene);
    
    callMainSetup();
    
    
}

void NSAnimationManager::setAnimation(string scriptPathName, int scene) {
    
    // search anim
    for (int i=0; i<animations.size(); i++) {
        
        ofLog(OF_LOG_NOTICE, scriptPathName + " " + animations[i]->scriptName);

        
        if(scriptPathName == animations[i]->scriptName) {
            setAnimation(i, scene);
        break;
        }
    }
    
}

void NSAnimationManager::nextAnimation(int scene) {
    
    if(scene==0) {
    
        int index = Globals::instance()->nsSceneManager->getScene(scene)->animationRef->id + 1;
        if(index > animations.size() -1 ) {
            index = 0;
        }
        setAnimation(index, scene);
        
        
    } else {
        
        currentPreviewIndex ++;
        if(currentPreviewIndex > animations.size() -1 ) {
            currentPreviewIndex = 0;
        }
        
        // Call main setup
        ofxJSValue retVal;
        ofxJSValue args[1];
        args[0] = int_TO_ofxJSValue(currentPreviewIndex);
        ofxJSCallFunctionNameGlobal_IfExists("nextPreviewAnim", args,1,retVal);
        
        callMainSetup();
        
        
    }
    
    
     
}

void NSAnimationManager::update (int numScenes) {
    
    // update main JS update
        
    // Call main update
    ofxJSValue retVal;
    ofxJSValue args[2];
    args[0] = float_TO_ofxJSValue(speedPct);
    args[1] = int_TO_ofxJSValue(globalCount);

    ofxJSCallFunctionNameGlobal_IfExists("update", args,2,retVal);
    
    for( int i =0; i<Globals::instance()->nsSceneManager->getNumScenes(); i++) {
        
        ofPtr<NSAnimation> animationRef = Globals::instance()->nsSceneManager->getScene(i)->animationRef;
        if(animationRef)
            animationRef->update(i);
        
    }
    
    globalCount += globalSpeed * speedPct;
}

void NSAnimationManager::callMainSetup() {
    
    ofxJSValue retVal;
    ofxJSValue args[1];
    
    args[0] = int_TO_ofxJSValue(0);
    ofxJSCallFunctionNameGlobal_IfExists("setup", args,1,retVal);
    
    
}

void NSAnimationManager::onScriptChanged(ofEventArgs & e) {
    
    // Call main setup
    callMainSetup();
   
    
}

void NSAnimationManager::setGlobalSpeed(float pct) {
    
    this->speedPct = ofClamp(pct, 0.0, 1.0);
    
}
