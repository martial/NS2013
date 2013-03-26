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
    
private:
    
    ofxUICanvas     *    guiLeft;
    ofxUICanvas     *    guiRight;
    
    float                fps;
    
};

#endif /* defined(__NS2013__NSGuiManager__) */
