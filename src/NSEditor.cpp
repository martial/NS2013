//
//  NSEditor.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSEditor.h"
#include "Globals.h"

NSEditor::NSEditor () {
    
}

void NSEditor::setup() {
    
    initJS();
    
    currentIndex        = 0;
    
    listAnimations();
    //(0, 0);
    
    
    
}

void NSEditor::listAnimations() {
    
    // Scripts
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
                 ofAddListener(animationRef->needReload, this, &NSEditor::onScriptChanged);
                 animations.push_back(animationRef);
                 i++;

			}
		}
	}
	dirScripts.close();
    
}

void NSEditor::setAnimation(int index, int scene) {
    
    //currentIndex = ofClamp(index, 0, animations.size()-1);
    
    // set animation to scene
    
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef.reset();
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef = animations[index];
        
    Globals::instance()->nsSceneManager->getScene(scene)->animationRef->init(scene);
    
    // Call main setup
    ofxJSValue retVal;
    ofxJSValue args[1];
    args[0] = int_TO_ofxJSValue(0);
    ofxJSCallFunctionNameGlobal_IfExists("setup", args,1,retVal);
    
    
}

void NSEditor::nextAnimation(int scene) {
    
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
        
        
        // Call main setup
        args[0] = int_TO_ofxJSValue(0);
        ofxJSCallFunctionNameGlobal_IfExists("setup", args,1,retVal);
        
        
    }
    
    
     
}

void NSEditor::update (int numScenes) {
    
    // update main JS update
    
    
    // Call main update
    ofxJSValue retVal;
    ofxJSValue args[0];
    ofxJSCallFunctionNameGlobal_IfExists("update", args,1,retVal);
    
    for( int i =0; i<2; i++) {
        
        ofPtr<NSAnimation> animationRef = Globals::instance()->nsSceneManager->getScene(i)->animationRef;
        if(animationRef)
            animationRef->update(i);
        
    }
}

void NSEditor::onScriptChanged(ofEventArgs & e) {
    
    // Call main setup
    // Call main setup
    
    printf("ahou");
    ofxJSValue retVal;
    ofxJSValue args[1];

    args[0] = int_TO_ofxJSValue(0);
    ofxJSCallFunctionNameGlobal_IfExists("setup", args,1,retVal);
    
}
