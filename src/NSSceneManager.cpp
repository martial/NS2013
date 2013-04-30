//
//  NSSceneManager.cpp
//  NS2013
//
//  Created by Martial on 29/03/13.
//
//

#include "NSSceneManager.h"

NSSceneManager::NSSceneManager() {
    
}

void NSSceneManager::setup() {
    
    
}

void NSSceneManager::update() {
    
    for (int i=0; i<scenes.size(); i++)
        scenes[i]->update();
    
}


void NSSceneManager::draw() {
    
    //ofDisableAlphaBlending();
    ofSetColor(255, 255, 255);
    for (int i=0; i<scenes.size(); i++) {
        
        scenes[i]->draw();
        
        ofTexture tex = scenes[i]->post.getProcessedTextureReference();

        glPushMatrix();
        glTranslatef(0, 0 + scenes[i]->post.height, 0);
        glScalef(1, -1, 1);
        
        
        int padding = 1;
        int x = ( i == 0) ? 0 : ofGetWidth() / 2 - scenes[i]->post.width /2 - padding;
        int y = ( i == 0) ? 0 : -padding - 55;
        
        if(i > 0) {
            ofRect(ofGetWidth()  / 2 - scenes[i]->post.width / 2 - padding*2, -padding*2 - 55 , scenes[i]->post.width + padding*2, scenes[i]->post.height + padding*2);
        }
        
        tex.draw(x,y, scenes[i]->post.width, scenes[i]->post.height);
        glPopMatrix();
     }
    
    
 }



void NSSceneManager::createScene(int width, int height) {
    
    ofPtr<NSScene> scene(new NSScene());
    scene->setup(width, height);
    scenes.push_back(scene);
    
}


ofPtr<NSScene>  NSSceneManager::getScene(int index) {
    
    return scenes[index];
    
}