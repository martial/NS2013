#include "app.h"
#include "Globals.h"

//--------------------------------------------------------------
void app::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(25);
    
    
    ofxJSInitialize();
    
    //Globals::instance()->nsScene    = &scene;
    
    Globals::instance()->nsSceneManager = &sceneManager;
    Globals::instance()->eq             = &eq;
    
    ofSoundStreamSetup(0,2,this, 44100, 512, 4);
    eq.setup();
    eq.setRange(16);

    
    
    sceneManager.setup();
    sceneManager.createScene(ofGetWidth(), ofGetHeight());
    sceneManager.createScene(320, 240);
    sceneManager.getScene(1)->setCameraMode(1);
    guiManager.setup();
    editor.setup();
    editor.setAnimation(0, 0);
    //editor.setAnimation(0, 1);
    eq.smooth = .2;
    
   
        
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
    
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void app::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind    = e.widget->getKind();
	
	if(name == "DOF FOCUS")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
        Globals::instance()->nsSceneManager->getScene(0)->dofFocus = slider->getScaledValue();
		//scene.dofFocus = slider->getScaledValue();
	}
	else if(name == "DOF APERTURE")
	{
		ofxUIMinimalSlider *slider = (ofxUIMinimalSlider *) e.widget;
        Globals::instance()->nsSceneManager->getScene(0)->dofAperture = slider->getScaledValue();
		//scene.dofAperture = slider->getScaledValue();
	}
}

//--------------------------------------------------------------
void app::audioReceived (float * input, int bufferSize, int nChannels){
	
	eq.audioReceived(input, bufferSize);
    
}

//--------------------------------------------------------------
void app::keyPressed(int key){
    
    if (key == ' ') {
        
        editor.nextAnimation(0);
        //editor.nextAnimation(1);
        
    }
    
    if (key == 'p') {
        
        editor.nextAnimation(1);
        //editor.nextAnimation(1);
        
    }
    
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
}


