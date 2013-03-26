#include "app.h"
#include "Globals.h"

//--------------------------------------------------------------
void app::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(25);
    
    
    ofxJSInitialize();
    
    Globals::instance()->nsScene = &scene;
    
    guiManager.setup();
    scene.setup();
    editor.setup(&guiManager, &scene);
    
   
        
}

//--------------------------------------------------------------
void app::update(){
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    scene.update();
    
    
}

//--------------------------------------------------------------
void app::draw(){
    
    ofDisableSmoothing();
    //ofBackground(90);
    
    
    editor.update();
    
    guiManager.update();
    scene.draw();
    
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void app::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName();
	int kind = e.widget->getKind();
	
	if(name == "DOF FOCUS")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		scene.dofFocus = slider->getScaledValue();
	}
	else if(name == "DOF APERTURE")
	{
		ofxUIMinimalSlider *slider = (ofxUIMinimalSlider *) e.widget;
		scene.dofAperture = slider->getScaledValue();
	}
}

//--------------------------------------------------------------
void app::keyPressed(int key){
    
    if (key == ' ') {
        
        editor.nextAnimation();
        
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


