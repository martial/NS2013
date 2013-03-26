//
//  NSEditor.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#ifndef __NS2013__NSEditor__
#define __NS2013__NSEditor__

#include "ofMain.h"
#include "NSGuiManager.h"
#include "ofxUI.h"
#include "ofxJavascript.h"
#include "JSBinder.h"
#include "NSScene.h"
#include "NSAnimation.h"

class NSEditor {
    
public:
    
    NSEditor();
    void setup(NSGuiManager * guiManager, NSScene * nsScene);
    void listAnimations();
    void update();
    
    void setAnimation(int index);
    void nextAnimation();
    
    /* */
    
    void loadScripts();
    void setScript(int index);
    
    
private :
    
    NSGuiManager                * guiManager;
    NSScene                     * NSScene;
    
    ofPtr<NSAnimation>          currentAnimation;
    
    vector<ofPtr<NSAnimation> >    animations;
    
    int                         currentIndex;
    
};

#endif /* defined(__NS2013__NSEditor__) */
