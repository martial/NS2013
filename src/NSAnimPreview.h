//
//  NSAnimPreview.h
//  NS2013
//
//  Created by Martial on 19/04/13.
//
//

#ifndef __NS2013__NSAnimPreview__
#define __NS2013__NSAnimPreview__

#include "ofMain.h"
#include "AnimationCanvas.h"

class NSAnimPreview {
    
  
public:
    
    void setup();
    void update();
    void draw();
    
    
    
private:
    
    AnimationCanvas canvas;
    
};

#endif /* defined(__NS2013__NSAnimPreview__) */
