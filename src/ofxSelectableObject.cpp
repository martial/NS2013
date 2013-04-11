//
//  ofxSelectableObject.cpp
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "ofxSelectableObject.h"

void ofxSelectableObject::setSelected(bool b) {
    
    printf("selected \n");
    this->bSelected = b;
    
}


bool ofxSelectableObject::isSelected() {
    return bSelected;
}



// --------------------------------------------- events

void ofxSelectableObject::onRollOver(int x, int y) {
    printf("MyTestObject::onRollOver(x: %i, y: %i)\n", x, y);
}

void ofxSelectableObject::onRollOut() {
    printf("MyTestObject::onRollOut()\n");
}

void ofxSelectableObject::onMouseMove(int x, int y){
    printf("MyTestObject::onMouseMove(x: %i, y: %i)\n", x, y);
}

void ofxSelectableObject::onDragOver(int x, int y, int button) {
    printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
}

void ofxSelectableObject::onDragOutside(int x, int y, int button) {
    printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
}

void ofxSelectableObject::onPress(int x, int y, int button) {
    printf("selectable::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);

    this->bSelected = !this->bSelected;
}

void ofxSelectableObject::onRelease(int x, int y, int button) {
    printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
}

void ofxSelectableObject::onReleaseOutside(int x, int y, int button) {
    printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
}

void ofxSelectableObject::keyPressed(int key) {
    printf("MyTestObject::keyPressed(key: %i)\n", key);
}

void ofxSelectableObject::keyReleased(int key) {
    printf("MyTestObject::keyReleased(key: %i)\n", key);
}