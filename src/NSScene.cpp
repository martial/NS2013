//
//  NSScene
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#include "NSScene.h"

NSScene::NSScene () {
    
    bEnableFFSA     = true;
    bEnableBloom    = true;
    bEnableDof      = false;
    bCamMouseInput  = false;
    
    
}

void NSScene::setup () {
    
    // init sharpies
    
    numSharpies = 32;
    
    for (int i=0; i<numSharpies; i++) {
        
        ofPtr<NSSharpy> sharpyRef(new NSSharpy());
        
        sharpyRef->setParent(*this);
        sharpyRef->setup();
        sharpyRef->setID(i);
        
        sharpies.push_back(sharpyRef);
      
    }
    
    
    light.setPosition(sharpiesCenter);
    light.setAmbientColor(255);
    
    
    
    post.init(ofGetWidth() , ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(bEnableFFSA);
    post.createPass<BloomPass>()->setEnabled(bEnableBloom);
    post.createPass<DofPass>()->setEnabled(bEnableDof);

    dof = post.getPasses()[2];
    
    
    cam.setOrientation(ofVec3f(90, 90, 0));
    cam.setDistance(2000.f);
    
    dofAperture = 0.92;
    dofFocus = 0.4;
    
}

void NSScene::update () {
    
    
    // lock cam position
    ofVec3f position = cam.getPosition();
    
    if ( position.z < -180.0) {
        position.z = -180.0;
        cam.setPosition(position);
        
    }
    
    /* update shaders */
    
    post.getPasses()[0]->setEnabled(bEnableFFSA);
    post.getPasses()[1]->setEnabled(bEnableBloom);
    post.getPasses()[2]->setEnabled(bEnableDof);
    
    shared_ptr<DofPass> pass = static_pointer_cast<DofPass>(dof);
    pass->setFocus(dofAperture);
    pass->setAperture(dofFocus);
    pass->setMaxBlur(.3);
    
    resetTransform();
    
    ofVec3f screenCenter;
    screenCenter.set(ofGetWidth() * .5, ofGetHeight() * .5 , 0.f);
    setPosition(screenCenter);
    
    
    ofVec3f pos;
    float xDistance = 120.f;
    float yDistance = 120.f;
    
    sharpiesCenter.set(ofVec3f( ( (float)numSharpies *.25  * xDistance) - xDistance*.5, yDistance * .5));
    
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->setPosition(-getPosition() + pos - sharpiesCenter);
        sharpyRef->update();
        pos.x += xDistance;
        if( i == (floor)((float)numSharpies *.5) -1) {
            pos.x = 0.F;
            pos.y += yDistance;
        }

    }
    
}

void NSScene::draw() {
    
    
        
    // copy enable part of gl state
    glPushAttrib(GL_ENABLE_BIT);

    light.enable();
    
    // begin scene to post process
    post.begin(cam);
    glEnable(GL_CULL_FACE);

    ofSetColor(255);
    //ofDrawGrid(1000, 2, true);
    
    
    float width = sharpiesCenter.x * 2.f;
    float height = 300;
    
    ofDisableAlphaBlending();
    
    light.setAmbientColor(0);
    light.setDiffuseColor(.3);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);

    // sol
    float zPos = -300.0;
    ofVec3f floorSize = sharpiesCenter;
    floorSize.y *= 6;
    floorSize.x *= 2;
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, -floorSize.y* 100, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x, -floorSize.y* 100, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x, floorSize.y* 100, zPos);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, floorSize.y* 100, zPos);
    
    // right
   
    glColor3f(.85, 0.85, 0.85);            glVertex3f(-floorSize.x, -floorSize.y, 0);
     glColor3f(0.95, 0.95, 0.95);        glVertex3f(floorSize.x, -floorSize.y, 0);
     glColor3f(1, 1, 1);        glVertex3f(floorSize.x, -floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, floorSize.y, 0);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(-floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, -floorSize.y, 0);
    
    glEnd();
    
        
    // walls
    int groundWidth = 4000, groundHeight = 1000;
    
    //ofRect(0, 0, groundWidth, groundHeight);
    
    light.setAmbientColor(1.0);
    ofSetColor(255);
    ofSphere (light.getPosition(), 10);
    
    ofSetColor(255, 0, 0);
    ofSphere(0, 0, 0, 10);
    
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(255);
    ofEnableAlphaBlending();
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->draw();
        
    }
    ofDisableAlphaBlending();
    //ofDisableBlendMode();
    //cam.end();
    post.end();
    //restoreTransformGL();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glPopAttrib();
    
    //post.draw();
   
}

/*
 
 */

void NSScene::setGobo(int sharpyIndex, float pct) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    sharpyRef->setGobo(pct);
    
}

void NSScene::setBrightness(int sharpyIndex, float pct) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    sharpyRef->setBrightness(pct);
    
}

void NSScene::setOrientation(int sharpyIndex, ofVec3f eulerAngles) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    sharpyRef->setOrientation(eulerAngles);
    
    
}


