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
    guiLeft->addSlider("DOF APERTURE", 0.0, 1.0, &Globals::instance()->nsScene->dofAperture);
    guiLeft->addSlider("DOF FOCUS", 0.0, 5.0, &Globals::instance()->nsScene->dofFocus);
    guiLeft->addSpacer();
    
    //guiLeft->addLabel("POST AHOU", OFX_UI_FONT_SMALL);
    
    //guiLeft->addSpacer();
    //guiLeft->addSlider("DOF FOCUS", 0.0, 1.0, 0.92f);
    //guiLeft->addSlider("DOF APERTURE", 0.0, 1.0, 0.99);
    
    guiRight = new ofxUICanvas();
    
    /*
    guiRight->setDrawBack(true);
    guiRight->addLabel("INSPECTOR");
     
     */
    
    
}

void NSGuiManager::update() {
    guiRight->getRect()->x = ofGetWidth() - guiRight->getRect()->getWidth();
    fps = ofGetFrameRate();

}

