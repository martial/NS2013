//
//  NSDMXManager.cpp
//  NS2013
//
//  Created by Martial on 12/04/13.
//
//

#include "NSDMXManager.h"
#include "Globals.h"

void NSDMXManager::setup(vector<ofPtr<NSSharpy> > * sharpies) {
    
    connect();
    
    this->sharpies = sharpies;
    
    for (int i=0; i<this->sharpies->size(); i++) {
        
        ofPtr<NSSharpy>  sharpy = sharpies->at(i);
        ofAddListener(sharpy->dmxEvent, this, &NSDMXManager::onSharpyEvent);
        
        
    }
    
}

void NSDMXManager::connect()  {
    
   
    dmx.disconnect();
    dmx2.disconnect();
    
    if(!dmx.isConnected())
        dmx.connect(Globals::instance()->DMX1_PORT, 512);
    
    if(!dmx.isConnected())
        dmx2.connect(Globals::instance()->DMX2_PORT, 512);

    
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
    
    
    for (int i=0; i<this->sharpies->size(); i++) {
        
        ofPtr<NSSharpy>  sharpy = sharpies->at(i);
        
        int id = i * 16;
        dmx.setLevel(id + 15, 128);
        
    }
    

    
    
}