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
#include "ofxUI.h"
#include "ofxJavascript.h"
#include "JSBinder.h"

#include "NSAnimation.h"

class NSEditor {
    
public:
    
    NSEditor();
    void setup();
    void listAnimations();
    void update(int numScenes);
    
    
    void callMainSetup();
    void callMainUpdate();
    void setAnimation(int index, int scene);
    void nextAnimation(int scene);
    
    
    /* */
    
    void loadScripts();
    void setScript(int index);
    
    void onScriptChanged(ofEventArgs & e);
    
    
private :
    
    
    ofPtr<NSAnimation>              currentAnimation;
    vector<ofPtr<NSAnimation> >     animations;
    
    int                             currentIndex;
    int                             currentPreviewIndex;
    

    
};

#endif /* defined(__NS2013__NSEditor__) */
