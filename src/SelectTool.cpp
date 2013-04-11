//
//  SelectTool.cpp
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "SelectTool.h"

SelectTool::SelectTool() {
    
    ofAddListener(  ofEvents().mousePressed, this,    &SelectTool::mousePressed);
    ofAddListener(  ofEvents().mouseReleased, this,   &SelectTool::mouseReleased);
    
    
}

void SelectTool::mousePressed(ofMouseEventArgs &e) {
    

    bIsEnabled = true;
    
    this->setPosition(e.x, e.y);
    
     ofAddListener(  ofEvents().mouseDragged, this,   &SelectTool::mouseMoved);
    
}

void SelectTool::mouseReleased(ofMouseEventArgs &e) {
    bIsEnabled = false;
    
    ofNotifyEvent(onReleaseEvent, *this, this);
    
    this->set(0,0,0,0);
    ofRemoveListener(  ofEvents().mouseDragged, this,   &SelectTool::mouseMoved);
    
    
    
}

void SelectTool::mouseMoved(ofMouseEventArgs &e) {
    bIsEnabled = false;
    
    this->setWidth  (e.x - x);
    this->setHeight (e.y - y);
        
}

void SelectTool::draw() {
    
    ofNoFill();
    ofSetColor(255);
    ofRect(*this);
    
}