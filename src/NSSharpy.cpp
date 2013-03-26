//
//  NSSharpy.cpp
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#include "NSSharpy.h"

NSSharpy::NSSharpy() {
    
    maxRadius = 8.f;
    brightness = 1.0;
      
}



void NSSharpy::setup(){
    
    reset();
}

void NSSharpy::reset(){
    
    this->goboPct   = 1.0;
    //this->pan       =
    
    
}

void NSSharpy::update(){
    
    // update mesh
    
    cylinder.clear();
    
    int rings = 32, resolution = 32;
    float length = 1024, radius = maxRadius * this->goboPct;
    
    
    for(int i = 0; i < rings; i++) {
        
        ofVec3f offset(0, 0, maxRadius - length *.5 + ofMap(i, 0, rings, -length, length) / 2);
        for(int j = 0; j < resolution; j++) {
            float theta = ofMap(j, 0, resolution, 0, 360);
            ofVec2f cur(radius, 0);
            cur.rotate(theta);
            cylinder.addVertex(offset + cur);
            // mesh.addColor(ofColor((i * j) % 2 == 0 ? 255 : 0));
            //cylinder.addColor(ofColor(255,255,255, brightness));
        }
    }
    
    for(int i = 0; i < rings - 1; i++) {
        for(int j = 0; j < resolution; j++) {
            int sw = i * resolution + j, se = sw + 1;
            if(j + 1 == resolution) {
                se -= resolution;
            }
            int nw = sw + resolution, ne = se + resolution;
            cylinder.addTriangle(sw, se, nw);
            cylinder.addTriangle(nw, se, ne);
        }
    }
    
    cylinder.setMode(OF_PRIMITIVE_TRIANGLES);

    
    
}
void NSSharpy::draw(){
    
   
    transformGL();
    ofPushMatrix();
    ofSetColor(255, 255);
    ofCone(0, 0, 0, maxRadius, maxRadius);
    ofSetColor(255, brightness * 255.f);
    cylinder.draw();
    ofPopMatrix();
    restoreTransformGL();
    
    
}



void NSSharpy::setID(int id){
    
}


void NSSharpy::setBrightness(float brighntessPct){
    this->brightness = brighntessPct;
    
    
}
void NSSharpy::setGobo(float pct){
    
    this->goboPct = pct;
    
    
}