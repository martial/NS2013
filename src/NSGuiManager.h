//
//  NSGuiManager.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#ifndef __NS2013__NSGuiManager__
#define __NS2013__NSGuiManager__

#include "ofMain.h"
#include "ofxUI.h"

class NSGuiManager {
    
    
public:
    NSGuiManager();
    void setup();
    void update();
    void exit();
    
    void guiEvent(ofxUIEventArgs &e);
    
private:
    
    ofxUICanvas     *    guiLeft;
    ofxUICanvas     *    guiRight;
    
    ofxUISlider     *    overrideSlider;
    
    float                fps;
    
};

#endif /* defined(__NS2013__NSGuiManager__) */
