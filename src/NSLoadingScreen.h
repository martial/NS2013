//
//  NSLoadingScreen.h
//  NS2013
//
//  Created by Martial on 11/04/13.
//
//

#ifndef __NS2013__NSLoadingScreen__
#define __NS2013__NSLoadingScreen__

#include "ofMain.h"
#include "ofxTween.h"
#include "ofxEasingQuint.h"

class NSLoadingScreen {
    
public:
    
    NSLoadingScreen();
    void draw();
    
    void show();
    void hide();
    void error();
    
private:
    
    ofxTween        tween;
    ofxEasingQuint  quint;
    float           pct;
    
    string          messageStr;
    
};

#endif /* defined(__NS2013__NSLoadingScreen__) */
