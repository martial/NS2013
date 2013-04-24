//
//  NSEditor.cpp
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "NSEditor.h"
#include "Globals.h"
#include "ofxModifierKeys.h"

void NSEditor::setup() {
    
    bIsPlaying = false;
    currentFrame        = 0;
    playVel             = 0.1;
    currentFrameCnt     = 0.0;
    currentAnimation    = -1;
   
    createNew();
    
    ofAddListener( Globals::instance()->dataManager->onUploadSuccess, this, &NSEditor::onUploadSuccessHandler );
    ofAddListener( Globals::instance()->dataManager->onLoadSuccess, this, &NSEditor::onLoadSuccessHandler );
    ofAddListener( Globals::instance()->dataManager->onDeleteSuccess, this, &NSEditor::onDeleteSuccessHandler );
    ofAddListener( Globals::instance()->dataManager->onError, this, &NSEditor::onErrorHandler );

    
}

void NSEditor::init() {
    
    ofAddListener( selectTool.onReleaseEvent, this, &NSEditor::onSelectedHandler );
    ofAddListener( ofEvents().keyPressed, this,    &NSEditor::onKeyPressed );
    

    
    ofAddListener( Globals::instance()->gui->guiEditorRight->newGUIEvent, this, &NSEditor::guiEvent );
    
    
}

void NSEditor::exit() {
    
    // 
    
    ofRemoveListener( selectTool.onReleaseEvent, this, &NSEditor::onSelectedHandler );
    ofRemoveListener( ofEvents().keyPressed, this,    &NSEditor::onKeyPressed );
    ofRemoveListener( Globals::instance()->gui->guiEditorRight->newGUIEvent, this, &NSEditor::guiEvent );
    
}

void NSEditor::update() {
    
    if(editableCanvas)
        if( Globals::instance()->app->mode != editableCanvas->bEditable )
             editableCanvas->setEditable(Globals::instance()->app->mode );
        
    if(bIsPlaying) {
        currentFrameCnt += playVel * 2.0f;
        setCurrentFrame(floor(currentFrameCnt));
        if(currentFrameCnt > previewCanvas.size() )
            currentFrameCnt = 0.0;
        
        if(currentFrameCnt < 0 )
            currentFrameCnt = previewCanvas.size() -1;
        
    }
    
    for (int i=0; i<previewCanvas.size(); i++) {
        previewCanvas[i]->update();
    }
    
}


void NSEditor::draw() {
    
    ofEnableAlphaBlending();
    ofPushMatrix();
    
    float xPadding  = 40.f;
       for (int i=0; i<previewCanvas.size(); i++) {
        
        float xStart   = ofGetWidth() * .5 - currentFrame * (xPadding + previewCanvas[i]->getWidth());
        float alpha = ( i == currentFrame ) ? 255 : (bIsPlaying) ? 0 : 25;
           
        previewCanvas[i]->alpha = alpha;
        previewCanvas[i]->bounds.setPosition(xStart - previewCanvas[i]->getWidth() * .5 + i * (xPadding + previewCanvas[i]->getWidth()), ofGetHeight() * .5 - previewCanvas[i]->getHeight() * .5);
        previewCanvas[i]->draw();
    }
    
    ofPopMatrix();
    
    selectTool.draw();
}

void NSEditor::drawAsPreview(float x, float y, float w, bool horizontal) {
    
    // scale to
    float scale  = 1.0f;
    
    if(horizontal)
        scale = w / editableCanvas->getWidth();
    else
        scale = w / editableCanvas->getHeight();
    
    float h = editableCanvas->getHeight() * scale;
    
    ofEnableAlphaBlending();
    ofPushMatrix();
    
    
    
    ofTranslate(x, y + w);
    
    if(currentAnimData) {
        float stringWidth = currentAnimData->name.size() * 8;
        ofDrawBitmapString(currentAnimData->name, ofPoint(-stringWidth * .5, -6));
        
    }
    ofTranslate(h * .5, 0);
    ofRotateZ(90);
    ofScale(scale, scale);
    editableCanvas->alpha = 255;
    editableCanvas->bounds.setPosition(0, 0);
    editableCanvas->draw();
    
    ofPopMatrix();
    
    
    
    
}

//-----------------------------

vector<int>  NSEditor::getActualFrameData() {
    
    return editableCanvas->getSelecteds();
    
}



void NSEditor::createNew () {
    
    
    currentAnimData = ofPtr<AnimData>( new AnimData());
    
    editableCanvas = ofPtr<AnimationCanvas> (new AnimationCanvas());
    
    previewCanvas.clear();
    editableCanvas->setup();
    previewCanvas.push_back(editableCanvas);
    
    currentFrame = 0;
    
    Globals::instance()->gui->nameInput->setTextString("");
    
    
}

void NSEditor::addFrame(bool bCopyCurrent) {
    
    
    
    ofPtr<AnimationCanvas> canvas =  ofPtr<AnimationCanvas> (new AnimationCanvas());
    canvas->setup();
    
    if(bCopyCurrent)
        clone(editableCanvas, canvas);
    
    previewCanvas.insert(previewCanvas.begin() + currentFrame +1, canvas);
    pushFrame();
    

}

void NSEditor::deleteFrame() {
    
    previewCanvas.erase(previewCanvas.begin() + currentFrame);
    
}

void NSEditor::setCurrentFrame(int index) {
    
    index = ofClamp(index, 0, previewCanvas.size()-1);
    currentFrame = index;
    editableCanvas = previewCanvas[currentFrame];
}

void NSEditor::pushFrame() {
    
    currentFrame ++;
    if(currentFrame > previewCanvas.size() -1 )
        currentFrame = 0;
    
    editableCanvas = previewCanvas[currentFrame];
    
}

void NSEditor::popFrame() {
    
    currentFrame --;
    if(currentFrame <0 )
        currentFrame =  previewCanvas.size() -1;
    
    editableCanvas = previewCanvas[currentFrame];
    
}

void NSEditor::clone(ofPtr<AnimationCanvas>  in, ofPtr<AnimationCanvas>  out) {
    
    vector<int> selecteds = in->getSelecteds();
    
    for (int i=0; i<selecteds.size(); i++) {
        out->selectOnIndex(selecteds[i]);
    }
        
}

void NSEditor::pushAnim(bool bAutoPlay) {
    
    currentAnimation++;
    if (currentAnimation >Globals::instance()->dataManager->animations.size() -1  ) {
        currentAnimation = 0;
    }
    setAnim(currentAnimation);
    
    if(bAutoPlay)
        play();
}

void NSEditor::popAnim(bool bAutoPlay) {
    
    currentAnimation--;
    if (currentAnimation < 0  ) {
        currentAnimation = Globals::instance()->dataManager->animations.size() -1;
    }
    setAnim(currentAnimation);
    
    if(bAutoPlay)
        play();
    
}

void NSEditor::setAnim(int index) {
    
    currentFrame = 0;
    
    currentAnimData = Globals::instance()->dataManager->getAnimation(index);
    
    previewCanvas = animations[index];
    setCurrentFrame(0);
    currentAnimation = index;
    
    stop();
    Globals::instance()->gui->nameInput->setTextString(currentAnimData->name);
    
    
    /*
    populateAnim();
    setCurrentFrame(0);
    
    currentAnimation = index;
     
     */
    
}

void NSEditor::setAnim(string name) {
    
    

    int id = Globals::instance()->dataManager->getAnimationId(name);
    if(id > -1) {
        setAnim(id);
        
    }
  
}

void NSEditor::populateAnim() {
    
        // set gui text
    
    stop();
    Globals::instance()->gui->nameInput->setTextString(currentAnimData->name);
    
    /*
    previewCanvas.clear();
    
    for ( int i=0; i<currentAnimData->data.size(); i++ ) {
        
        AnimationCanvas  * canvas = new AnimationCanvas();
        canvas->setup();
        canvas->setSelecteds(currentAnimData->data[i]);
        
        previewCanvas.push_back(canvas);
        
    }
     
     */
    
}

void NSEditor::loadAll () {
    
    for (int i=0; i<animations.size(); i++ ) {
        vector<ofPtr<AnimationCanvas> > vec  = animations[i];
        vec.clear();
    }
    
    animations.clear();
    
    
    
    for ( int j =0; j<Globals::instance()->dataManager->animations.size(); j++) {
    
        ofPtr<AnimData> animRef = Globals::instance()->dataManager->getAnimation(j);        
        vector<ofPtr<AnimationCanvas> > animation;
        for ( int i=0; i<animRef->data.size(); i++ ) {
            
            
            ofPtr<AnimationCanvas> canvas = ofPtr<AnimationCanvas>(new AnimationCanvas());
            canvas->setup();
            canvas->setSelecteds(animRef->data[i]);
        
            animation.push_back(canvas);
        
        }
        
        animations.push_back(animation);
    
    }
    
    
    printf("load all : animations.size %d", animations.size());
    
    
}


void NSEditor::play() {
    
    bIsPlaying = true;
}

void NSEditor::stop() {
    bIsPlaying = false;
}

void NSEditor::save () {
    
    stop();
    
    vector<vector<int> > data;
    for (int i=0; i<previewCanvas.size(); i++) {        
        data.push_back(previewCanvas[i]->getSelecteds());
    }
    
    Globals::instance()->loadingScreen->show();
    currentAnimData->data = data;
    currentAnimData->name = Globals::instance()->gui->nameInput->getLabel()->getLabel();
    currentAnimData->toXML();
    
    
    Globals::instance()->dataManager->startUpload();
    

    
}

void NSEditor::deleteAnim() {
    
    if(currentAnimData && currentAnimData->id.size() > 0) {
        Globals::instance()->loadingScreen->show();
        Globals::instance()->dataManager->deleteAnim(ofToInt(currentAnimData->id));
    }
    
}

void NSEditor::onErrorHandler(int &e) {
    
    Globals::instance()->loadingScreen->error();
}

void NSEditor::onLoadSuccessHandler(int & e) {
    
    
    // we should reload the current animation right?
    
    loadAll();
    
    Globals::instance()->gui->populateEditorAnimations();
    Globals::instance()->loadingScreen->hide();
    
       
    if(currentAnimData)
        setAnim(currentAnimData->name);
    else
        setAnim(0);

}

void NSEditor::onUploadSuccessHandler(int & e) {
    
    
    currentAnimData->id = ofToString(e);
    Globals::instance()->dataManager->load();
}

void NSEditor::onDeleteSuccessHandler(int & e) {
    
    createNew();
    Globals::instance()->dataManager->load();
    
}

void NSEditor::onKeyPressed (ofKeyEventArgs & e) {
    
    if(Globals::instance()->gui->isBusy())
        return;
    
    string key = ofToString(e.key);
    
    if ( e.key == OF_KEY_RIGHT)
        pushFrame();
    
    if ( e.key == OF_KEY_LEFT)
        popFrame();
    
    if ( key == "32")
        bIsPlaying = !bIsPlaying;
    
    if ( e.key == 'a')
        addFrame(ofGetModifierPressed(OF_KEY_ALT));
    
    if ( e.key == 'd')
        deleteFrame();
    
    if ( e.key == 's')
        save();
    
    
}

void NSEditor::guiEvent(ofxUIEventArgs &e) {
    
     string name = e.widget->getName();
    
    if (name == "ANIMS") {
        
        ofxUIDropDownList* dropDown = (ofxUIDropDownList *)e.widget;
        vector<ofxUIWidget *> &selected = dropDown->getSelected();
        
        for(int i = 0; i < selected.size(); i++){
            setAnim(selected[i]->getName());
        }
        
    }
       
    
}

void NSEditor::onSelectedHandler(ofRectangle & e) {
    
    if(editableCanvas)
        editableCanvas->selectOnRect(e, !ofGetModifierPressed(OF_KEY_SHIFT));
        
}