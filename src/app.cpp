#include "app.h"

//--------------------------------------------------------------
void app::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(25);
    
    scene.setup();
    
    gui1 = new ofxUICanvas(0, 0, 300, ofGetHeight());
    gui1->setDrawBack(true);
    gui1->addSlider("DOF FOCUS", 0.0, 1.0, 0.92f);
    gui1->addSlider("DOF APERTURE", 0.0, 1.0, 0.99);
    ofAddListener(gui1->newGUIEvent,this,&app::guiEvent);
}

//--------------------------------------------------------------
void app::update(){
    
    scene.update();

}

//--------------------------------------------------------------
void app::draw(){
    
    //ofBackground(90);
    scene.draw();

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
        cout << "value: " << slider->getScaledValue() << endl;
	}
	else if(name == "DOF APERTURE")
	{
		ofxUIMinimalSlider *slider = (ofxUIMinimalSlider *) e.widget;
		scene.dofAperture = slider->getScaledValue();
        cout << "value: " << slider->getScaledValue() << endl;
	}
}

//--------------------------------------------------------------
void app::keyPressed(int key){

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