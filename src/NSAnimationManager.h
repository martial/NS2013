//
//  NSAnimationManager.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#ifndef __NS2013__NSAnimationManager__
#define __NS2013__NSAnimationManager__

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxJavascript.h"
#include "JSBinder.h"

#include "NSAnimation.h"

class NSAnimationManager {
    
public:
    
    NSAnimationManager();
    void setup();
    void listAnimations();
    vector<string> getAnimations();
    void update(int numScenes);
    
    
    void callMainSetup();
    void callMainUpdate();
    void setAnimation(int index, int scene);
    void setAnimation(string scriptPathName, int scene);
    
    void prevAnimation(int scene);
    void nextAnimation(int scene);
    
        
    
    void setGlobalSpeed(float pct);
    
    
    /* */
    
    void loadScripts();
    void setScript(int index);
    
    void onScriptChanged(ofEventArgs & e);
    
    float                           speedPct;
    
    bool                            bNeedsPushPreview, bNeedsPopPreview;
    
    int                             currentPreviewIndex;
    
    bool                            bNeedsSetAnimation;
    bool                            bNeedsAnimFromPreview;
    int                             animToGo, sceneToGo;
    
    
private :
    
    
    ofPtr<NSAnimation>              currentAnimation;
    vector<ofPtr<NSAnimation> >     animations;
    
    int                             currentIndex;
    
    long                            globalCount;
    int                             globalSpeed;
   
    bool                            bNeedsUpdate;
    bool                            bFrameHasChanged;
    
    NSAnimation *                   configScript;
    
    
    

    
};

#endif /* defined(__NS2013__NSAnimationManager__) */
