//
//  ofxSelectableObject.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__ofxSelectableObject__
#define __NS2013__ofxSelectableObject__

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

class ofxSelectableObject : public ofxMSAInteractiveObject {
  
public:
    
    ofxSelectableObject() {
        bSelected = false;
    }
    void setSelected(bool b);
    bool isSelected();
    
    
private:
    
    bool bSelected;

    // key events
    virtual void onRollOver(int x, int y);
    virtual void onRollOut();
    virtual void onMouseMove(int x, int y);
    virtual void onDragOver(int x, int y, int button);
    virtual void onDragOutside(int x, int y, int button);
    virtual void onPress(int x, int y, int button);
    virtual void onRelease(int x, int y, int button);
    virtual void onReleaseOutside(int x, int y, int button);
    virtual void keyPressed(int key);
    virtual void keyReleased(int key);
    
    
};

#endif /* defined(__NS2013__ofxSelectableObject__) */
