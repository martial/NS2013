
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
        
    if(!tween.isCompleted())
        pct = tween.update();
    
    ofRectangle rect(ofGetWidth()  * pct, 0, -ofGetWidth(), ofGetHeight());
    
    float strSize = messageStr.size() * 8;
    float xPos = pct * (ofGetWidth() * .5 - strSize * .5);
    
    ofEnableAlphaBlending();
    ofFill();
    ofSetColor(0, pct * 200);
    ofRect(rect);
    
    if(messageStr == "ERREUR DE L'INTERNET ! " || messageStr ==  "SUCCESS") {
        float blink = ( ofGetFrameNum() % 4 == 0 ) ? 0.0 : 1.0;
        ofSetColor(255* pct * blink);
        
    } else
        ofSetColor(255* pct);
    
    ofDrawBitmapString(messageStr, xPos, ofGetHeight() * .5);
    
    
    
}

void NSLoadingScreen::error() {
    
    pct = 1.0;
    messageStr = "ERREUR DE L'INTERNET ! ";
    tween.setParameters(quint, ofxTween::easeInOut, pct, 0.0, 400, 5000);
    tween.start();
}

void NSLoadingScreen::show() {
    
    messageStr = "PLEASE WAIT";
    tween.setParameters(quint, ofxTween::easeInOut, pct, 1.0, 400, 0);
    tween.start();
    
    
}
void NSLoadingScreen::hide() {
    
    messageStr = "SUCCESS";
    tween.setParameters(quint, ofxTween::easeInOut, pct, 0.0, 400, 800);
    tween.start();
    
    string voice = "Bruce";
    string cmd = "say  -v "+voice+" "+messageStr +" &";
    system(cmd.c_str());
    
}
