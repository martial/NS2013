//
//  NSPreview.h
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#ifndef __NS2013__NSScene__
#define __NS2013__NSScene__

#include "ofMain.h"
#include "NSSharpy.h"
#include "ofxPostProcessing.h"

class NSScene : public ofNode{
    
public:
    
    NSScene();
    void setup();
    void update();
    void draw();
    
    float                       dofFocus;
    float                       dofAperture;
    
private:
    
    
    RenderPass::Ptr             dof;
    ofxPostProcessing           post;
    ofxPostProcessing           postDof;
    ofEasyCam                   cam;
    ofLight                     light;
    
    int                         numSharpies;
    ofVec3f                     sharpiesCenter;
    
    vector<ofPtr<NSSharpy> >    sharpies;
    vector<ofLight*>            lights;

};


#endif /* defined(__NS2013__NSScene_) */
