//
//  NSSharpy.cpp
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#include "NSSharpy.h"

NSSharpy::NSSharpy() {
    
    maxRadius = 4.f;
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
    float length = 1024*2, radius = maxRadius * this->goboPct;
    
    
    for(int i = 0; i < rings; i++) {
        
        ofVec3f offset(0, 0, ofMap(i, 0, rings, 0, -length) );
        //offset.z -= length;
        for(int j = 0; j < resolution; j++) {
            float theta = ofMap(j, 0, resolution, 0, 360);
            ofVec2f cur(radius, 0);
            cur.rotate(theta);
            cylinder.addVertex(offset + cur);
           
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
    
    //getEulerDistance();
    transToTargetOrientation();
    
    sendToDmx();
    
    //ofNotifyEvent(dmxEvent, <#ArgumentsType &args#>, <#SenderType *sender#>)
    
    
    
}

void NSSharpy::transToTargetOrientation () {
    
    float blurRate = 0.99;
    
    ofQuaternion currentQuat = this->getOrientationQuat();
    ofVec4f      currentQuatVec = currentQuat.asVec4();
    
    
        
    this->setOrientation(ofQuaternion(this->target->setTweenedOrientation(currentQuat)));

    
}

void NSSharpy::sendToDmx() {
    
    // positions events
    
    vector<ofPoint> dmxData;
    
    // color
    dmxData.push_back(ofPoint(1, 8));
    
    // shutter    
    dmxData.push_back(ofPoint(2, 255));
    
    // dimmer
    dmxData.push_back(ofPoint(3, (int)(brightness * 255)));
    
    // Gobo
    dmxData.push_back(ofPoint(4, 0));
    
    // Prism
    dmxData.push_back(ofPoint(5, 0));
    
    // frost
    dmxData.push_back(ofPoint(8, 0));
    
    // pan
    ofVec3f orientation                 = this->getOrientationEuler();
    ofVec3f childOrientation            = this->childNode.getOrientationEuler();
    ofVec3f globalOrientation           = this->getGlobalOrientation().getEuler();
    ofQuaternion q                      = this->getOrientationQuat();
    
    
    int pan = (int)( (270 + orientation.x) * 255 / 540);
    dmxData.push_back(ofPoint(10, pan));
    
    int tilt = (int)( (135 + childOrientation.y) * 255 / 270);
    dmxData.push_back(ofPoint(12, tilt));
    
    if(id==8) {
        
        ofLog(OF_LOG_NOTICE, "real pan : %f, real titl : %f, real z : %f", orientation.x, orientation.y, orientation.z);
        ofLog(OF_LOG_NOTICE, "gl pan : %f, gl titl : %f, gl z : %f", globalOrientation.x, globalOrientation.y, globalOrientation.z);
        ofLog(OF_LOG_NOTICE, "dmxPan x : %d, dmxTilt : %d", pan, tilt);
    
    }
    
    ofNotifyEvent(dmxEvent, dmxData, this);

    
}

//--------------------------------------------------------------


void NSSharpy::draw(){
    
   
    transformGL();
    ofPushMatrix();
    //ofRotate(180);
    
    ofSetColor(255, 255);
    //ofCone(0, 0, 0, maxRadius*2, maxRadius*2);
    
    ofBox(0,0,0,40);
    
    // then child node
    
    ofSetColor(255, 0, 0);
    
    ofPushMatrix();
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    ofDrawBitmapString(ofToString(id), 0,0);
    ofPopMatrix();
    
    childNode.transformGL();
    
    ofPushMatrix();
    //ofTranslate(0, 0, -1024);
    ofSetColor(255, brightness * 255.f);
    cylinder.draw();
    ofPopMatrix();
    
    childNode.restoreTransformGL();

    ofPopMatrix();
    restoreTransformGL();
    
    
}

//--------------------------------------------------------------

ofVec3f NSSharpy::getEulerDistance() {
    
    ofVec3f currentEuler    = this->getOrientationEuler();
    ofVec3f targetEuler     = this->target->getOrientationEuler();
    
    if(id == 0) {
        
        // pan, tilt, roll
        
        ofVec3f distance = targetEuler - currentEuler;
        distance.x = abs(distance.x);
        distance.y = abs(distance.y);
        distance.z = abs(distance.z);
        
        ofLog(OF_LOG_NOTICE, "Distance x : %f, y : %f, z : %f", distance.x, distance.y, distance.z);
                
    }
    
    
}

//--------------------------------------------------------------

void NSSharpy::setID(int id){
    
    this->id = id;
    
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