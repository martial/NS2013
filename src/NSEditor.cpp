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
    currentFrame    = 0;
    playVel         = 0.1;
    currentFrameCnt = 0.0;
   
    createNew();
    
    ofAddListener( selectTool.onReleaseEvent, this, &NSEditor::onSelectedHandler );
    ofAddListener( ofEvents().keyPressed, this,    &NSEditor::onKeyPressed );
    
}
void NSEditor::update() {
    
    if(bIsPlaying) {
        currentFrameCnt += playVel;
        setCurrentFrame(floor(currentFrameCnt));
        if(currentFrameCnt > previewCanvas.size() )
            currentFrameCnt = 0.0;
        
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
        previewCanvas[i]->setPosition(xStart - previewCanvas[i]->getWidth() * .5 + i * (xPadding + previewCanvas[i]->getWidth()), ofGetHeight() * .5 - previewCanvas[i]->getHeight() * .5);
        previewCanvas[i]->draw();
    }
    
    ofPopMatrix();
    
    selectTool.draw();
}

//-----------------------------


void NSEditor::createNew () {
    
    editableCanvas = new AnimationCanvas();
    editableCanvas->setup();
    previewCanvas.push_back(editableCanvas);
    
}

void NSEditor::addFrame(bool bCopyCurrent) {
    
    
    
    AnimationCanvas  * canvas = new AnimationCanvas();
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

void NSEditor::clone(AnimationCanvas * in, AnimationCanvas * out) {
    
    vector<int> selecteds = in->getSelecteds();
    
    for (int i=0; i<selecteds.size(); i++) {
        out->selectOnIndex(selecteds[i]);
    }
        
}

void NSEditor::play() {
    bIsPlaying = true;
}

void NSEditor::stop() {
    bIsPlaying = false;
}

void NSEditor::save () {
    
    vector<vector<int> > data;
    for (int i=0; i<previewCanvas.size(); i++) {
        
        
        data.push_back(previewCanvas[i]->getSelecteds());
        
    }
    
    AnimData anim;
    anim.data = data;
    anim.name = Globals::instance()->gui->nameInput->getLabel()->getLabel();
    
    anim.toXML();
    
    
    
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

void NSEditor::onSelectedHandler(ofRectangle & e) {
    
    if(editableCanvas)
        editableCanvas->selectOnRect(e, !ofGetModifierPressed(OF_KEY_SHIFT));
    
    
    
}