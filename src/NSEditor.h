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
    
    void setup(bool enableEvents);
    void update();
    void draw();
    void drawAsPreview(float x, float y, float w, bool horizontal);
    
    void createNew();
    void addFrame(bool bCopyCurrent = false);
    void deleteFrame();
    
    void clearFrame();
    
    void pushFrame();
    void popFrame();
    void setCurrentFrame(int index);
    
    void clone(ofPtr<AnimationCanvas>  in, ofPtr<AnimationCanvas>  out);
    
    void save();
    void deleteAnim();
    
    void play();
    void stop();
    
    void pushAnim(bool bAutoPlay = false);
    void popAnim(bool bAutoPlay = false);
    void setAnim(int index);
    void setAnim(string name);
    void populateAnim();
    void loadAll();
    
    vector<int> getActualFrameData();
    
    
    void onErrorHandler(int & e);
    void onLoadSuccessHandler(int & e);
    void onUploadSuccessHandler(int & e);
    void onDeleteSuccessHandler(int & e);
    void guiEvent(ofxUIEventArgs &e);
    
    void onKeyPressed (ofKeyEventArgs & e);
    void onSelectedHandler(ofRectangle & e);
    
    float                       playVel;
    
    int                         currentFrame;
    int                         currentAnimation;
    
    int getTotalFrames() {return previewCanvas.size ();}
    
    bool    bTapTempoMode;
    
    
    void init();
    void exit();
    
    
    bool bIsMain;

    
private:
    
    
    // the current we're going to edit
    ofPtr<AnimationCanvas>                      editableCanvas;
    
    // a way to visualize frames
    vector<ofPtr<AnimationCanvas> >            previewCanvas;
    
    // cache
    vector<vector<ofPtr<AnimationCanvas> > >   animations;
    
    ofPtr<AnimData>                             currentAnimData;
    

    
    
    SelectTool                                  selectTool;
    
    float                                       currentFrameCnt;
    bool                                        bIsPlaying;
    bool                                        bDrawIds;
    
    
};

#endif /* defined(__NS2013__NSEditor__) */
