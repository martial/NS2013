//
//  NSEditor.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__NSEditor__
#define __NS2013__NSEditor__

#include "ofMain.h"
#include "AnimationCanvas.h"
#include "SelectTool.h"
#include "NSDataManager.h"
#include "ofxUI.h"

class NSDataManager;

class NSEditor {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void createNew();
    void addFrame(bool bCopyCurrent = false);
    void deleteFrame();
    
    void clearFrame();
    
    void pushFrame();
    void popFrame();
    void setCurrentFrame(int index);
    
    void clone(AnimationCanvas * in, AnimationCanvas * out);
    
    void save();
    
    void play();
    void stop();
    
    void setAnim(int index);
    void setAnim(string name);
    void populateAnim();
    
    
    void onErrorHandler(int & e);
    void onLoadSuccessHandler(int & e);
    void onUploadSuccessHandler(int & e);
    void guiEvent(ofxUIEventArgs &e);
    
    void onKeyPressed (ofKeyEventArgs & e);
    
    
    //void load(int id);
    
    
    
    void onSelectedHandler(ofRectangle & e);
    
    float                       playVel;

    
private:
    
    
    // the current we're going to edit
    AnimationCanvas       *     editableCanvas;
    
    // a way to visualize frames
    vector<AnimationCanvas*>    previewCanvas;
    
    ofPtr<AnimData>             currentAnimData;
    
    int                         currentFrame;
    
    
    SelectTool                  selectTool;
    
    float                       currentFrameCnt;
    bool                        bIsPlaying;
    
    
};

#endif /* defined(__NS2013__NSEditor__) */
