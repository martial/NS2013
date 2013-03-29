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
#include "NSAnimation.h"

class NSScene : public ofNode{
    
public:
    
    NSScene();
    void setup(int width, int height);
    void update();
    void draw();
    
    void setCameraMode(int camMode);
    void toggleCamera();
    
    ofVec3f getSharpyPos(int sharpyIndex);
    
    void sharpyLookAt(int sharpyIndex, ofVec3f pos);
    void setGobo(int sharpyIndex, float pct);
    void setBrightness(int sharpyIndex, float pct);
    void setOrientation(int sharpyIndex, ofVec3f eulerAngles);
    
    float                       dofFocus;
    float                       dofAperture;
    
    bool                        bEnableFFSA;
    bool                        bEnableBloom;
    bool                        bEnableDof;
    bool                        bCamMouseInput;
    bool                        bDrawGrid;
    bool                        bToggleCamera;
    bool                        bSndAlpha;
    bool                        bSndGobo;
    
    // not sur if that would be there
    ofPtr<NSAnimation>          animationRef;
    ofxPostProcessing           post;
    
private:
    
    
    RenderPass::Ptr             dof;
    
    ofxPostProcessing           postDof;
    ofEasyCam                   cam;
    ofLight                     light;
    ofLight                     lightUp;
    
    int                         camMode;
    
    int                         numSharpies;
    ofVec3f                     sharpiesCenter;
    
    vector<ofPtr<NSSharpy> >    sharpies;
    vector<ofLight*>            lights;
    
   
};


#endif /* defined(__NS2013__NSScene_) */
