#include "app.h"
#include "Globals.h"

//--------------------------------------------------------------
void app::setup(){
    
    ofSetFrameRate(120);
    //ofSetVerticalSync(true);
    ofBackground(25);
    
    
    ofxJSInitialize();
        
    Globals::instance()->nsSceneManager = &sceneManager;
    Globals::instance()->eq             = &eq;
    Globals::instance()->screenLog     = &screenLog;
    
    ofSoundStreamSetup(0,2,this, 44100, 512, 4);
    eq.setup();
    eq.setRange(16);
        
    sceneManager.setup();
    sceneManager.createScene(ofGetWidth(), ofGetHeight());
    
#ifndef EDITOR_MODE
    sceneManager.createScene(320, 240);
    sceneManager.getScene(1)->bEnableDof    = false;
    sceneManager.getScene(1)->bEnableFFSA   = false;
    sceneManager.getScene(1)->setCameraMode(1);
#endif
    guiManager.setup();
    editor.setup();
    editor.setAnimation(0, 0);
#ifndef EDITOR_MODE
    editor.setAnimation(0, 1);
    editor.nextAnimation(1);
#endif
    eq.smooth = .2;
    //eq.setFilterRange(-1);
    
    
}

//--------------------------------------------------------------
void app::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    editor.update(sceneManager.getNumScenes());
    sceneManager.update();
    
   
}

//--------------------------------------------------------------
void app::draw(){
    
    ofDisableSmoothing();
    
    guiManager.update();
    sceneManager.draw();
    
    //ofEnableSmoothing();
    
    ofSetColor(255);
    screenLog.draw();

}


//--------------------------------------------------------------
void app::audioReceived (float * input, int bufferSize, int nChannels){
	
	eq.audioReceived(input, bufferSize);
    
}

//--------------------------------------------------------------
void app::keyPressed(int key){
    
    if (key == ' ') {
        editor.nextAnimation(0);
    }
    
    if (key == 'f') {
        ofToggleFullscreen();
    }
    
#ifndef EDITOR_MODE
    if (key == 'p') {
        editor.nextAnimation(1);        
    }
#endif
    
    if (key == 'e') {
        eq.setup();
    }

}

//--------------------------------------------------------------
void app::keyReleased(int key){

}

//--------------------------------------------------------------
void app::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void app::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void app::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void app::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void app::windowResized(int w, int h){
    Globals::instance()->nsSceneManager->getScene(0)->onResize(w, h);
}

//--------------------------------------------------------------
void app::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void app::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void app::exit(){
    ofxJSFinalize();
    guiManager.exit();
}


