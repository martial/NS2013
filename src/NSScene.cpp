//
//  NSScene
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#include "NSScene.h"

NSScene::NSScene () {
    
    
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
    
    //tests
    
    //ofSetCoordHandedness(OF_RIGHT_HANDED);
    
    light.setPosition(sharpiesCenter);
    light.setAmbientColor(255);
    
    
    
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<FxaaPass>()->setEnabled(true);
    post.createPass<BloomPass>()->setEnabled(true);
    post.createPass<DofPass>()->setEnabled(true);

    
    dof = post.getPasses()[2];
    
    
    
}

void NSScene::update () {
    
    /* update shaders */
    
    shared_ptr<DofPass> pass = static_pointer_cast<DofPass>(dof);
    pass->setFocus(dofAperture);
    pass->setAperture(dofFocus);
    pass->setMaxBlur(1.3);
    
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
        
        sharpyRef->resetTransform();
        sharpyRef->setPosition(-getPosition() + pos - sharpiesCenter);
        sharpyRef->setOrientation(ofVec3f(ofGetElapsedTimef()*i, ofGetElapsedTimef()*i));
        sharpyRef->setGobo(.5 + cos(ofGetElapsedTimef()) * .5);
        sharpyRef->update();
        
        
        pos.x += xDistance;
        if( i == (floor)((float)numSharpies *.5) -1) {
            pos.x = 0.F;
            pos.y += yDistance;
        }

    }
    
    cam.setDistance(ofGetMouseX());
    
    //DofPass pass = dof.get();
    
}

void NSScene::draw() {
    
    // copy enable part of gl state
    glPushAttrib(GL_ENABLE_BIT);
    
    // setup gl state
    
    
    //transformGL();
    
    light.enable();
    
    // begin scene to post process
    post.begin(cam);
    
    ofSetColor(255);
    //ofDrawGrid(1000, 2, true);
    
    
    float width = sharpiesCenter.x * 2.f;
    float height = 300;
    
    ofDisableAlphaBlending();
    
    light.setAmbientColor(0);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);
    
    /*
    // draw right wall
    glColor3f(.9, 0.9, 0.9);        glVertex3f(width/2, height+1, width/2);
    glColor3f(1, 1, 1);             glVertex3f(width/2, -height, width/2);
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(width/2, -height, -width/2);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(width/2, height+1, -width/2);
    
    // back wall
    glColor3f(.9, 0.9, 0.9);        glVertex3f(width/2, height+1, -width/2);
    glColor3f(1, 1, 1);             glVertex3f(width/2, -height, -width/2);
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-width/2, -height, -width/2);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-width/2, height+1, -width/2);
    
    // left wall
    glColor3f(.9, 0.9, 0.9);        glVertex3f(-width/2, height+1, -width/2);
    glColor3f(1, 1, 1);             glVertex3f(-width/2, -height, -width/2);
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-width/2, -height, width/2);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-width/2, height+1, width/2);
     
     */
    
    // sol
    float zPos = -300.0;
    ofVec3f floorSize = sharpiesCenter;
    floorSize.y *= 6;
    floorSize.x *= 2;
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x, -floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x, floorSize.y, zPos);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, floorSize.y, zPos);
    
    // right
    
    glColor3f(.9, 0.9, 0.9);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    glColor3f(1, 1, 1);        glVertex3f(floorSize.x, -floorSize.y, zPos);
    glColor3f(0.95, 0.95, 0.95);        glVertex3f(floorSize.x, -floorSize.y, 0);
    glColor3f(.85, 0.85, 0.85);            glVertex3f(-floorSize.x, -floorSize.y, 0);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, floorSize.y, 0);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(-floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, -floorSize.y, 0);

  
    
    
    glEnd();
    
    
   
    glEnable(GL_CULL_FACE);
    
    // walls
    int groundWidth = 4000, groundHeight = 1000;
    
    //ofRect(0, 0, groundWidth, groundHeight);
    
    light.setAmbientColor(255);
    ofSetColor(255);
    ofSphere (light.getPosition(), 10);
    
    ofSetColor(255, 0, 0);
    ofSphere(0, 0, 0, 10);
    
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(255, 175);

    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->draw();
        
    }
    
    //cam.end();
    post.end();
    //restoreTransformGL();
    
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glPopAttrib();
    
    //post.draw();
   
    
    
    
    
}