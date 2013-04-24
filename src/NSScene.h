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
#include "ofx3DModelLoader.h"
#include "SharpyModel.h"


class NSScene : public ofNode{
    
public:
    
    NSScene();
    void setup(int width, int height);
    void update();
    void draw();
    
    
    void drawBox();
    void drawModels();
    
    
    void setCameraMode(int camMode);
    void toggleCamera();
    
    ofVec3f getSharpyPos(int sharpyIndex);
    
    void reset();
    void setSharpyDecay(float decay);
    void sharpyLookAt(int sharpyIndex, ofVec3f pos);
    void setGobo(int sharpyIndex, float pct);
    void setBrightness(int sharpyIndex, float pct);
    
    void setPanTilt(int sharpyIndex, ofVec2f angles);
    void setRotation(int sharpyIndex, ofVec2f angles);
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
    
    bool                        bdrawLookAt;
    bool                        bdrawArrows;
    bool                        bdrawModels;
    
    bool                        bmapAnims;
    
    // not sur if that would be there
    ofPtr<NSAnimation>          animationRef;
    ofxPostProcessing           post;
    
    vector<ofPtr<NSSharpy> >    sharpies;
    
    float                       globalDecay;
    float                       globalAlpha;
    
    float                       width, height;
    float                       depth;
    
    
    void onResize(int width, int height);
    
    ofMesh                     sceneBox;
    
    
private:
    
    ofVec3f screenCenter;
    
    ofMesh box( float width, float height, float depth, int resX, int resY, int resZ );
    
    
    RenderPass::Ptr             dof;
    
    ofxPostProcessing           postDof;
    ofEasyCam                   cam;
    ofLight                     light;
    ofLight                     lightUp;
    
    int                         camMode;
    
    int                         numSharpies;
    ofVec3f                     sharpiesCenter;
    
    
    vector<ofLight*>            lights;
    
    ofx3DModelLoader            flash;
    SharpyModel                 sharpyModel;
    
    ofVec3f                     floorSize;
    //ofMesh                      box;
    
   
};


#endif /* defined(__NS2013__NSScene_) */
