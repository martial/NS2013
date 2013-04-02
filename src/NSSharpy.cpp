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
    
    target = new NSSharpyTarget();
    
    reset();
    
}

void NSSharpy::reset(){
    
    this->goboPct   = 1.0;
    //this->pan       =
    
    
}

//--------------------------------------------------------------


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
    
    // update props
    
    this->goboPct       = this->target->goboPct;
    this->brightness    = this->target->brt;
    
        
    //currentQuat *= targetQuat;
    //this->setOrientation( this->target->getOrientationQuat());
    //ofVec3f o = this->target->getOrientationEuler();
    
    transToTargetOrientation();
    
    
    
}

void NSSharpy::transToTargetOrientation () {
    
    float blurRate = 0.99;
    
    ofQuaternion currentQuat = this->getOrientationQuat();
    ofVec4f      currentQuatVec = currentQuat.asVec4();
    
    
    //this->target->setTweenedOrientation(currentQuat);
    this->setOrientation(ofQuaternion(this->target->setTweenedOrientation(currentQuat)));

    
}

//--------------------------------------------------------------


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

//--------------------------------------------------------------

void NSSharpy::setID(int id){
    
}

void NSSharpy::setTargetOrientation(ofVec3f orientation) {
    this->target->setOrientation(orientation);
}


void NSSharpy::setBrightness(float brighntessPct){
    //this->brightness = brighntessPct;
    this->target->brt = brighntessPct;
}

float NSSharpy::getBrightness(){
    return this->brightness;    
}

void NSSharpy::setGobo(float pct){
     this->target->goboPct = pct;
    //this->goboPct = pct;
}

float NSSharpy::getGobo(){
    return this->goboPct;
}