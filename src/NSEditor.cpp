//
//  NSEditor.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSEditor.h"

NSEditor::NSEditor () {
    
}

void NSEditor::setup(NSGuiManager *guiManager, class NSScene * nsScene) {
    
    initJS();
    
    currentIndex        = 0;
    
    this->guiManager    = guiManager;
    listAnimations();
    setAnimation(0);
    
    //test = new NSAnimation();
    //test->setup("test.js");
    
    
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
		for (it = files.begin(); it != files.end(); ++it){
			if ((*it).getExtension() == "js")
			{
				printf("- [%s] path=%s\n", (*it).getFileName().c_str(), (*it).getAbsolutePath().c_str());
                                
                 ofPtr<NSAnimation> animationRef(new NSAnimation());
                 animationRef->setup(ofToDataPath((*it).getAbsolutePath()));
                 animations.push_back(animationRef);

			}
		}
	}
	dirScripts.close();
    
}

void NSEditor::setAnimation(int index) {
    
    currentIndex = ofClamp(index, 0, animations.size()-1);
    currentAnimation = animations[currentIndex];
    
}

void NSEditor::nextAnimation() {
    
    currentIndex++;
    if(currentIndex > animations.size() -1 ) {
        currentIndex = 0;
    }
    
    //printf("current %d", currentIndex);
    
    currentAnimation = animations[currentIndex];
    currentAnimation->loadScript();
    
}

void NSEditor::update () {
    
    if(currentAnimation)
        currentAnimation->update();
    
}
