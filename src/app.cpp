#include "app.h"
#include "Globals.h"

//--------------------------------------------------------------
void app::setup(){
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    
    ofxJSInitialize();
    
    Globals::instance()->app                = this;
    Globals::instance()->nsSceneManager     = &sceneManager;
    Globals::instance()->eq                 = &eq;
    Globals::instance()->screenLog          = &screenLog;
    Globals::instance()->animationManager   = &animationManager;
    Globals::instance()->editor             = &editor;
    Globals::instance()->gui                = &guiManager;
    Globals::instance()->dataManager        = &dataManager;
    Globals::instance()->loadingScreen      = &loadingScreen;
    
    ofSoundStreamSetup(0,2,this, 44100, 512, 4);
    eq.setup();
    eq.setRange(16);
        
    sceneManager.setup();
    sceneManager.createScene(ofGetWidth(), ofGetHeight());
    
#ifndef animationManager_MODE
    sceneManager.createScene(320, 240);
    sceneManager.getScene(1)->bEnableDof    = false;
    sceneManager.getScene(1)->bEnableFFSA   = false;
    sceneManager.getScene(1)->setCameraMode(1);
#endif
    guiManager.setup();
    animationManager.setup();
    animationManager.setAnimation(0, 0);
    guiManager.populateAnimations();
#ifndef animationManager_MODE
    animationManager.setAnimation(0, 1);
    animationManager.nextAnimation(1);
#endif
    eq.smooth = .2;
    //eq.setFilterRange(-1);
    
    
    // editor
    
    
    editor.setup();
    
    dataManager.setup();
    dataManager.load();
    
    mode = 1;
    
    dmxManager.setup(&sceneManager.getScene(0)->sharpies);
    
    
    
}

//--------------------------------------------------------------
void app::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    if(mode == 0 ) {
        
        
        animationManager.update(sceneManager.getNumScenes());
        sceneManager.update();
        dmxManager.update();
        
        
    } else {
        
        editor.update();
        
    }
    
    guiManager.update();
   
}

//--------------------------------------------------------------
void app::draw(){
    
    ofDisableSmoothing();
    
    ofBackground(25);
    
    
    if(mode == 0 ) {
        
        sceneManager.draw();
        ofSetColor(255);
        screenLog.draw();
        
    } else {
        
        editor.draw();
        
    }
    
    loadingScreen.draw();

}


//--------------------------------------------------------------
void app::audioReceived (float * input, int bufferSize, int nChannels){
	
	eq.audioReceived(input, bufferSize);
    
}

//--------------------------------------------------------------
void app::keyPressed(int key){
    
    if(guiManager.isBusy())
        return;
    
    if (key == ' ') {
        animationManager.nextAnimation(0);
    }
      
    if (key == 'f') {
        ofToggleFullscreen();
    }
    
#ifndef animationManager_MODE
    if (key == 'p') {
        animationManager.nextAnimation(1);        
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
    dataManager.exit();
}


