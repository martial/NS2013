
//
//  NSLoadingScreen.cpp
//  NS2013
//
//  Created by Martial on 11/04/13.
//
//

#include "NSLoadingScreen.h"

 NSLoadingScreen::NSLoadingScreen() {
     
     pct = 0.0;
     tween.setFrameBasedAnimation(false);
     tween.setParameters(quint, ofxTween::easeInOut, pct, 0.0, 400, 0);
     tween.start();
    
}
void NSLoadingScreen::draw() {
    
    //printf("pct %f\n", pct);
    
    if(!tween.isCompleted())
        pct = tween.update();
    
    ofRectangle rect(ofGetWidth()  * pct, 0, -ofGetWidth(), ofGetHeight());
    
    float strSize = messageStr.size() * 8;
    float xPos = pct * (ofGetWidth() * .5 - strSize * .5);
    
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0, pct * 200);
    ofRect(rect);
    ofSetColor(255* pct);
    ofDrawBitmapString(messageStr, xPos, ofGetHeight() * .5);
    
    
    
}

void NSLoadingScreen::error() {
    
    messageStr = "ERROR";
    tween.setParameters(quint, ofxTween::easeInOut, pct, 0.0, 400, 1000);
    tween.start();
}

void NSLoadingScreen::show() {
    
    messageStr = "PLEASE WAIT";
    //tween.setParameters(quint, ofxTween::easeInOut, pct, 1.0, 400, 0);
    //tween.start();
    
    
}
void NSLoadingScreen::hide() {
    
    tween.setParameters(quint, ofxTween::easeInOut, pct, 0.0, 400, 0);
    tween.start();
    
}
