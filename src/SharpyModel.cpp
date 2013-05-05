//
//  SharpyModel.cpp
//  NS2013
//
//  Created by Martial on 16/04/13.
//
//

#include "SharpyModel.h"

void SharpyModel::setup () {
    
    baseModel.loadModel("model/base.3ds", true);
    panModel.loadModel("model/pan.3ds", true);
    tiltModel.loadModel("model/tilt.3ds", true);
    
    baseModel.setScale(.3, .3, .3);
    panModel.setScale(.3, .3, .3);
    tiltModel.setScale(.3, .3, .3);
    
    tiltModel.enableNormals();
    tiltModel.enableMaterials();
    tiltModel.enableTextures();
    
    /*
    baseModel.createLightsFromAiModel();
    panModel.createLightsFromAiModel();
    tiltModel.createLightsFromAiModel();
    
    
    
    tiltModel.optimizeScene();
    baseModel.optimizeScene();
    tiltModel.optimizeScene();
    
    
    panModel.disableTextures();
    panModel.disableColors();
    panModel.disableMaterials();
    
    tiltModel.disableTextures();
    tiltModel.disableColors();
    tiltModel.disableMaterials();
    
    baseModel.disableTextures();
    baseModel.disableColors();
    baseModel.disableMaterials();
     
      */
    
    
}

void SharpyModel::update() {
    
}

void SharpyModel::drawBlocks(ofVec3f pos, float pan, float tilt) {
    
    ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(90);


    ofRotateY(pan);
    ofBox(0, 0, 0, 20);
    
    ofPopMatrix();
    
}

void SharpyModel::draw(ofVec3f pos, float pan, float tilt) {
    
   
    //printf("x %d", ofGetMouseX());
 
    
    pos.z += 25;
    ofPushMatrix();
    ofTranslate(pos);
    ofScale(.2, .2, .2);
    ofTranslate(80, -60);
    ofRotateX(90);
    baseModel.draw(OF_MESH_FILL);
    
    
    ofTranslate(10, 0, 0);
    
    ofTranslate(-90, 0, -55);
    ofRotateY(180 + pan);
    //ofSphere(0, 0, 0, 10);
    ofTranslate(90, 0, 65);
    //panModel.setRotation(1, 360-pan, 0, 1, 0);
    panModel.draw(OF_MESH_FILL);
    
    
    float x = -90;
    float y = -140;
    float z = -60;
    
   
    
    ofTranslate(x, y, z);
    ofSphere(0, 0, 0, 10);
    ofRotateX( + 275 + tilt );
    ofTranslate(-x, -y, z);
    
    ofTranslate(10, 50, 110);
    tiltModel.draw(OF_MESH_FILL);
    
     
     
    ofPopMatrix();
    
}