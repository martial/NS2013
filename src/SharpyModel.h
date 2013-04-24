//
//  SharpyModel.h
//  NS2013
//
//  Created by Martial on 16/04/13.
//
//

#ifndef __NS2013__SharpyModel__
#define __NS2013__SharpyModel__

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include "ofxAssimpModelLoader.h"

class SharpyModel {
  
public:
    
    void setup ();
    void update();
    
    void drawBlocks(ofVec3f pos, float pan, float tilt);
    void draw(ofVec3f pos, float pan, float tilt);
    
    ofxAssimpModelLoader baseModel, panModel, tiltModel;
      
};

#endif /* defined(__NS2013__SharpyModel__) */
