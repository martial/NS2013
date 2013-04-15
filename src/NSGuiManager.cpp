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
    
    mode = 0;
    
}

void NSGuiManager::setup() {
    
    
    ofPtr<NSScene> mainScene = Globals::instance()->nsSceneManager->getScene(0);
    
    guiLeft = new ofxUICanvas(220, ofGetHeight());
    guiLeft->setDrawBack(true);
    guiLeft->addLabel("NS 2013 BITCH");
    guiLeft->addSpacer();
    guiLeft->addLabelButton("TOGGLE EDITOR", false, true);
    
    guiLeft->addValuePlotter("FPS", 512, 0.0, 60, &fps );
    guiLeft->addFPS();
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
    
    
    guiRight = new ofxUICanvas(220, ofGetHeight());
    guiRight->setDrawBack(true);
    guiRight->addLabel("GLOBALS");
    guiRight->addToggle("RELOAD JS", false);
    guiRight->addSlider("SPEED", 0.0, 1.0,  &Globals::instance()->animationManager->speedPct);
    animationsDropDown = guiRight->addDropDownList("ANIMATIONS", Globals::instance()->animationManager->getAnimations());
    
    guiLeft->loadSettings("gui.xml");
    
    ofAddListener(guiLeft->newGUIEvent,this,&NSGuiManager::guiEvent);
    ofAddListener(guiRight->newGUIEvent,this,&NSGuiManager::guiEvent);
    
    guiLeft->disable();
    
    guiEditorLeft = new ofxUICanvas(220, ofGetHeight());
    guiEditorLeft->setDrawBack(true);
    guiEditorLeft->addLabel("NS 2013 EDITOR BITCH");
    guiEditorLeft->addSpacer();
    guiEditorLeft->addLabelButton("TOGGLE EDITOR", false, true);

    guiEditorLeft->addLabel("INSPECTOR GADGET");
    guiEditorLeft->addSpacer();
    guiEditorLeft->addLabel("NAME");
    nameInput = guiEditorLeft->addTextInput("NAME", "...");
    guiEditorLeft->addSpacer();
    guiEditorLeft->addSlider("speed", 0.0, 1.0,  &Globals::instance()->editor->playVel);
    guiEditorLeft->addSpacer();
    guiEditorLeft->addLabelButton("NEW ANIM", false, true);
    guiEditorLeft->addLabelButton("NEW FRAME", false, true);
    guiEditorLeft->addLabelButton("DELETE", false, true);
    guiEditorRight = new ofxUICanvas(220, ofGetHeight());
    animationsEditorDropDown  = guiEditorRight->addDropDownList("ANIMS", Globals::instance()->dataManager->getAnimationsLabels());

    
    ofAddListener(guiEditorLeft->newGUIEvent,this,&NSGuiManager::guiEvent);
    //guiEditorLeft->
    
    setMode(1);
    
}

void NSGuiManager::setMode(int mode) {
    
    if(mode == 0) {
        
        guiLeft->enable();
        guiRight->enable();
        
        guiEditorLeft->disable();
        guiEditorRight->disable();
        
        
    } else {
        
        guiEditorLeft->enable();
        guiEditorRight->enable();
        guiRight->disable();
        guiLeft->disable();
        
    }
    
    this->mode = mode;
    
}

void NSGuiManager::populateAnimations() {
    
    animationsDropDown->setAllowMultiple(false);
    animationsDropDown->clearToggles();
    
    vector<string> anims = Globals::instance()->animationManager->getAnimations();
    for ( int i=0; i<anims.size(); i++)
        animationsDropDown->addToggle(anims[i]);
    
}


void NSGuiManager::populateEditorAnimations() {
    
    animationsEditorDropDown->setAllowMultiple(false);
    animationsEditorDropDown->clearToggles();
    
    vector<string> anims = Globals::instance()->dataManager->getAnimationsLabels();
    for ( int i=0; i<anims.size(); i++)
        animationsEditorDropDown->addToggle(anims[i]);
    
}

void NSGuiManager::update() {
    guiRight->getRect()->x      = ofGetWidth() - guiRight->getRect()->getWidth();
    guiEditorRight->getRect()->x      = ofGetWidth() - guiEditorRight->getRect()->getWidth();
    
    guiLeft->getRect()->height  = ofGetHeight();
    guiRight->getRect()->height = ofGetHeight();
    
    guiEditorLeft->getRect()->height  = ofGetHeight();
    guiEditorRight->getRect()->height = ofGetHeight();
    
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
    
    if(name == "RELOAD JS") {
        Globals::instance()->animationManager->listAnimations();
        populateAnimations();
    }
    
    if(name == "ANIMATIONS") {
        
        vector<ofxUIWidget *> &selected = animationsDropDown->getSelected();
        for(int i = 0; i < selected.size(); i++){
            Globals::instance()->animationManager->setAnimation(selected[i]->getName(),0);
        }
        
    }
    
    if(name == "TOGGLE EDITOR") {
        
        ofxUIButton *button = (ofxUIButton *) e.widget;
        
        if(button->getValue() == 0) {

        
        int mode = ( this->mode == 0 ) ? 1 : 0;
        
        printf("mode %d", mode);
        
        setMode(mode);
        Globals::instance()->app->mode = mode;
            
        }
        
    }
}

bool NSGuiManager::isBusy() {
    
    return (nameInput->clicked);
}

void NSGuiManager::exit () {
    
    guiLeft->saveSettings("gui.xml");
    
}

