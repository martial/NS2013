//
//  AnimationCanvas.cpp
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "AnimationCanvas.h"

AnimationCanvas::AnimationCanvas() {
    
    xPadding    = 20.0;
    yPadding    = 20.0;
    rectSize    = 20.0;
    alpha       = 255;
    
    bounds.set(0, 0, getWidth(), getHeight());
    
    
    
}
void AnimationCanvas::setup() {
    
    
    for (int i=0; i<32; i++) {
        AnimationBlock  * block = new AnimationBlock();
        block->set(0,0,rectSize, rectSize);
        blocks.push_back(block);
    }
    
    bounds.set(0, 0, getWidth(), getHeight());
    
    //disableMouseEvents();

    
}


void AnimationCanvas::update() {
    
}

void AnimationCanvas::draw() {
    
    
    // It's just about a simple grid man
    
    ofSetColor(255, alpha);
    
    ofPushMatrix();
    ofTranslate(bounds.x, bounds.y);
    
    ofNoFill();
    
    ofRect(0, 0, getWidth(), getHeight());
    
    ofFill();
    
    for (int i=0; i<2; i++ ) {
        
        for (int j=0; j<16; j++) {
            
            int index = i * 16 + j;
            
            float xBlockPos = xPadding + i * (rectSize + xPadding);
            float yBlockPos = yPadding + j * (rectSize + yPadding);
            
            ofPushMatrix();
            ofTranslate(xBlockPos, yBlockPos);
            blocks[index]->alpha = alpha;
            
            blocks[index]->setPosition(bounds.x + xBlockPos, bounds.y + yBlockPos);
            blocks[index]->draw();
            
            ofPopMatrix();
            
        }
        
    }
    
    ofPopMatrix();
    
}


void AnimationCanvas::setEditable(bool b) {
    
    this->bEditable = b;
    
    for (int i=0; i<32; i++) {
        blocks[i]->setEditable(b);
    }
    
}

float AnimationCanvas::getWidth() {
    
    return 2 * (rectSize + xPadding) + xPadding;
    
}


float AnimationCanvas::getHeight() {
    
    return 16 * (rectSize + yPadding) + yPadding;
    
}

void AnimationCanvas::selectOnIndex(int index) {
    
    
    blocks[index]->setSelected(true);
    
}


void AnimationCanvas::selectOnRect(ofRectangle r, bool select) {
    
    
    for (int i=0; i<blocks.size(); i++) {
       
        
        if ( r.inside(*blocks[i])) {
            blocks[i]->setSelected(select);
        }
        
    }
    
       
}

void AnimationCanvas::setSelecteds(vector<int> data) {
    
    for (int i=0; i<data.size(); i++)
        blocks[data[i]]->setSelected(true);
}

vector<int> AnimationCanvas::getSelecteds() {
    
    
    vector<int> selecteds;
    
    for (int i=0; i<32; i++) {
        if(blocks[i]->isSelected())
            selecteds.push_back(i);
    }
    
    return selecteds;
    
}



// --------------------------------------------- events

void AnimationCanvas::onRollOver(int x, int y) {
    printf("MyTestObject::onRollOver(x: %i, y: %i)\n", x, y);
}

void AnimationCanvas::onRollOut() {
    printf("MyTestObject::onRollOut()\n");
}

void AnimationCanvas::onMouseMove(int x, int y){
    printf("MyTestObject::onMouseMove(x: %i, y: %i)\n", x, y);
}

void AnimationCanvas::onDragOver(int x, int y, int button) {
    printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
}

void AnimationCanvas::onDragOutside(int x, int y, int button) {
    printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
}

void AnimationCanvas::onPress(int x, int y, int button) {
    printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
}

void AnimationCanvas::onRelease(int x, int y, int button) {
    printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
}

void AnimationCanvas::onReleaseOutside(int x, int y, int button) {
    printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
}

void AnimationCanvas::keyPressed(int key) {
    printf("MyTestObject::keyPressed(key: %i)\n", key);
}

void AnimationCanvas::keyReleased(int key) {
    printf("MyTestObject::keyReleased(key: %i)\n", key);
}