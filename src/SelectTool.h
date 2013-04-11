//
//  SelectTool.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__SelectTool__
#define __NS2013__SelectTool__

#include "ofMain.h"

class SelectTool : public ofRectangle {
    
public:
    
    SelectTool();
    void mousePressed(ofMouseEventArgs &e);
    void mouseReleased(ofMouseEventArgs &e);
    void mouseMoved(ofMouseEventArgs &e);
    void draw();
    
    ofEvent<ofRectangle> onReleaseEvent;
    
private:
    
    
    
    
    
    bool                bIsEnabled;
};

#endif /* defined(__NS2013__SelectTool__) */
