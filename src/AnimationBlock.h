//
//  AnimationBlock.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__AnimationBlock__
#define __NS2013__AnimationBlock__

#include "ofMain.h"
#include "ofxSelectableObject.h"

class AnimationBlock : public ofxSelectableObject {
  
public:
    
    AnimationBlock() {
        
        //enableMouseEvents();
        alpha = 255;

    }
    
    void setEditable ( bool b) {
        
        if(b) {
            enableMouseEvents();
        } else {
            disableMouseEvents();
        }
        
    }
    
    
    void draw() {
        
        ofPushMatrix();
        //ofTranslate(x,y);
        isSelected() ? ofSetColor(255, alpha) : ofSetColor(50, alpha);
        //ofSetColor(col);
        
        ofRect(0,0, width, height);
        
        ofPopMatrix();
    }
    
    float alpha;
    
};

#endif /* defined(__NS2013__AnimationBlock__) */
