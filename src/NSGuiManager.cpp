//
//  NSGuiManager.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSGuiManager.h"
#include "Globals.h"

NSGuiManager::NSGuiManager() {
    
}

void NSGuiManager::setup() {
    
    guiLeft = new ofxUICanvas(220, ofGetHeight());
    guiLeft->setDrawBack(true);
    guiLeft->addLabel("NS 2013 BITCH");
    
    guiLeft->addValuePlotter("FPS", 126, 0.0, 120, &fps );
    guiLeft->addSpacer();
    
    guiLeft->addLabel("POST PROCESSING", OFX_UI_FONT_SMALL);
    guiLeft->addSpacer();
    guiLeft->addToggle("CAMERA MOUSE", &Globals::instance()->nsScene->bCamMouseInput);
    guiLeft->addToggle("FFSA", &Globals::instance()->nsScene->bEnableFFSA);
    guiLeft->addToggle("BLOOM", &Globals::instance()->nsScene->bEnableBloom);
    guiLeft->addToggle("DOF", &Globals::instance()->nsScene->bEnableDof);
    guiLeft->addSlider("DOF APERTURE", 0.0, 2.0, &Globals::instance()->nsScene->dofAperture);
    guiLeft->addSlider("DOF FOCUS", 0.0, 5.0, &Globals::instance()->nsScene->dofFocus);
    guiLeft->addToggle("DRAW GRID", &Globals::instance()->nsScene->bDrawGrid);
    
    guiLeft->addLabelButton("TOGGLE CAMERA", false);
    guiLeft->addSpacer();
    guiLeft->addLabel("SOUND", OFX_UI_FONT_MEDIUM);
    guiLeft->addLabel("SPECTRUM", OFX_UI_FONT_SMALL);
    ofxUISpectrum* leftSpectrum     = guiLeft->addSpectrum("SPECTRUM", Globals::instance()->eq->leftPreview, 512, 0.0, 1.0);
    ofxUISpectrum* rightSpectrum    = guiLeft->addSpectrum("SPECTRUM", Globals::instance()->eq->rightPreview, 512, 0.0, 1.0);
    
    leftSpectrum->setSteps(&Globals::instance()->eq->range);
    leftSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    rightSpectrum->setSteps(&Globals::instance()->eq->range);
    rightSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    
    
    guiLeft->addSlider("RANGE", 1, 16, 8);
    overrideSlider = guiLeft->addSlider("OVERRIDE", -1, 16, 8);
    guiLeft->addToggle("SOUND ALPHA", &Globals::instance()->nsScene->bSndAlpha);
    guiLeft->addToggle("SOUND GOBO", &Globals::instance()->nsScene->bSndGobo);
    
    ofAddListener(guiLeft->newGUIEvent,this,&NSGuiManager::guiEvent);
    //guiLeft->addSpacer();
    
    //guiRight = new ofxUICanvas();
    /*
    guiRight->setDrawBack(true);
    guiRight->addLabel("INSPECTOR");
     */
    
    
}

void NSGuiManager::update() {
    //guiRight->getRect()->x = ofGetWidth() - guiRight->getRect()->getWidth();
    fps = ofGetFrameRate();

}

void NSGuiManager::guiEvent(ofxUIEventArgs &e) {
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
	
    
    
	if(name == "TOGGLE CAMERA") {
        ofxUIButton *button = (ofxUIButton *) e.widget;
        cout << name << "\t value: " << button->getValue() << endl;
        if(button->getValue() == 0)
            //printf("BUTTON \n");
        Globals::instance()->nsScene->toggleCamera();
    }
    
    
	if(name == "RANGE") {
        ofxUISlider * slider = (ofxUISlider *) e.widget;
        cout << name << "\t value: " << slider->getValue() << endl;
        Globals::instance()->eq->setRange((int)slider->getScaledValue());
        if(Globals::instance()->eq->filterRange > slider->getScaledValue() ) {
            Globals::instance()->eq->setFilterRange(slider->getScaledValue() - 1);
        }
        
        overrideSlider->setMax(slider->getScaledValue());
    }
    
    if(name == "OVERRIDE") {
        ofxUISlider * slider = (ofxUISlider *) e.widget;
        Globals::instance()->eq->setFilterRange((int)slider->getScaledValue());
    }
}

