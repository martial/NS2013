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
    
    
    void setGobo(int sharpyIndex, float pct);
    void setBrightness(int sharpyIndex, float pct);
    void setOrientation(int sharpyIndex, ofVec3f eulerAngles);
    
    float                       dofFocus;
    float                       dofAperture;
    
    bool                        bEnableFFSA;
    bool                        bEnableBloom;
    bool                        bEnableDof;
    bool                        bCamMouseInput;

    
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
