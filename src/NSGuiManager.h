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
    
    void setMode(int mode);
    
    void populateAnimations();
    void guiEvent(ofxUIEventArgs &e);
    
    bool isBusy();
    
    ofxUITextInput *     nameInput;

    
private:
    
    ofxUICanvas     *    guiLeft;
    ofxUICanvas     *    guiRight;
    
    ofxUICanvas     *    guiEditorLeft;
    ofxUICanvas     *    guiEditorRight;
    
    ofxUISlider     *    overrideSlider;
    ofxUIDropDownList*   animationsDropDown;
    
    float                fps;
    
};

#endif /* defined(__NS2013__NSGuiManager__) */
