//
//  NSDMXManager.cpp
//  NS2013
//
//  Created by Martial on 12/04/13.
//
//

#include "NSDMXManager.h"

void NSDMXManager::setup(vector<ofPtr<NSSharpy> > * sharpies) {
    
    dmx.connect(0);
    
    this->sharpies = sharpies;
    
    for (int i=0; i<this->sharpies->size(); i++) {
        
        ofPtr<NSSharpy>  sharpy = sharpies->at(i);
        
        if(i==8)
            ofAddListener(sharpy->dmxEvent, this, &NSDMXManager::onSharpyEvent);
        
        
    }
    
}

void NSDMXManager::onSharpyEvent(vector<ofPoint> & data) {
    
    for (int i=0; i<data.size(); i++) {
        dmx.setLevel((int)data[i].x, (int)data[i].y);
    }
    
}


void NSDMXManager::update() {
    dmx.update();
    
}
void NSDMXManager::draw() {
    
    
}


void NSDMXManager::resetAll() {
    
    
}