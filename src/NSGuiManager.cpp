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
    
    
    ofPtr<NSScene> mainScene = Globals::instance()->nsSceneManager->getScene(0);
    
    guiLeft = new ofxUICanvas(220, ofGetHeight());
    guiLeft->setDrawBack(true);
    guiLeft->addLabel("NS 2013 BITCH");
    
    guiLeft->addValuePlotter("FPS", 126, 0.0, 120, &fps );
    guiLeft->addSpacer();
    
    guiLeft->addLabel("POST PROCESSING", OFX_UI_FONT_SMALL);
    guiLeft->addSpacer();
    guiLeft->addToggle("CAMERA MOUSE", &mainScene->bCamMouseInput);
    guiLeft->addToggle("FFSA", &mainScene->bEnableFFSA);
    guiLeft->addToggle("BLOOM", &mainScene->bEnableBloom);
    guiLeft->addToggle("DOF", &mainScene->bEnableDof);
    guiLeft->addSlider("DOF APERTURE", 0.0, 2.0, &mainScene->dofAperture);
    guiLeft->addSlider("DOF FOCUS", 0.0, 5.0, &mainScene->dofFocus);
    guiLeft->addToggle("DRAW GRID", &mainScene->bDrawGrid);
    
    guiLeft->addLabelButton("TOGGLE CAMERA", false);
    guiLeft->addSpacer();
    guiLeft->addLabel("SOUND", OFX_UI_FONT_MEDIUM);
    guiLeft->addLabel("SPECTRUM", OFX_UI_FONT_SMALL);
    guiLeft->addWaveform("SPECTRUMF", Globals::instance()->eq->rawInput, 512, 0.0, .1);
    ofxUISpectrum* leftSpectrum     = guiLeft->addSpectrum("SPECTRUML", Globals::instance()->eq->leftPreview, 512, 0.0, 1.0);
    ofxUISpectrum* rightSpectrum    = guiLeft->addSpectrum("SPECTRUMR", Globals::instance()->eq->rightPreview, 512, 0.0, 1.0);
    
    leftSpectrum->setSteps(&Globals::instance()->eq->range);
    leftSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    rightSpectrum->setSteps(&Globals::instance()->eq->range);
    rightSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    
    
    guiLeft->addSlider("RANGE", 1, 16, 8);
    overrideSlider = guiLeft->addSlider("OVERRIDE", -1, 16, 8);
    guiLeft->addToggle("SOUND ALPHA", &mainScene->bSndAlpha);
    guiLeft->addToggle("SOUND GOBO", &mainScene->bSndGobo);
    
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
	
     ofPtr<NSScene> mainScene = Globals::instance()->nsSceneManager->getScene(0);
    
	if(name == "TOGGLE CAMERA") {
        ofxUIButton *button = (ofxUIButton *) e.widget;
        
        if(button->getValue() == 0)
            mainScene->toggleCamera();
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

