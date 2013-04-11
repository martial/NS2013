//
//  AnimationCanvas.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__AnimationCanvas__
#define __NS2013__AnimationCanvas__

#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"
#include "AnimationBlock.h"

class AnimationCanvas : public ofxMSAInteractiveObject {
    
public:
    
    AnimationCanvas();
    void setup();
    void update();
    void draw();
    
    void setEditable(bool b);
    
    float getWidth();
    float getHeight();
    
    void selectOnIndex(int index);
    void selectOnRect(ofRectangle r, bool select);
    
    float alpha;
    
    vector<int> getSelecteds();
    
    
    vector<vector<int> > serialize();

    
private:
    
    float xPadding;
    float yPadding;
    float rectSize;
    
    bool bEditable;
    
    vector<AnimationBlock*>  blocks;
    
    
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

#endif /* defined(__NS2013__AnimationCanvas__) */
