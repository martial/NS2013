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
   // guiLeft->setRetinaResolution();
    
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
    guiLeft->addToggle("LOOKAT", &mainScene->bdrawLookAt);
    guiLeft->addToggle("DRAW GRID", &mainScene->bDrawGrid);
    guiLeft->addToggle("DRAW MODEL", &mainScene->bdrawModels);
    
    guiLeft->addLabelButton("TOGGLE CAMERA", false);
    guiLeft->addSpacer();
    guiLeft->addLabel("SOUND", OFX_UI_FONT_MEDIUM);
    guiLeft->addLabel("SPECTRUM", OFX_UI_FONT_SMALL);
    //guiLeft->addWaveform("SPECTRUMF", Globals::instance()->eq->rawInput, 512, 0.0, .1);
    ofxUISpectrum* leftSpectrum     = guiLeft->addSpectrum("SPECTRUML", Globals::instance()->eq->leftPreview, 512, 0.0, 1.0);
    ofxUISpectrum* rightSpectrum    = guiLeft->addSpectrum("SPECTRUMR", Globals::instance()->eq->rightPreview, 512, 0.0, 1.0);
    
    leftSpectrum->setSteps(&Globals::instance()->eq->range);
    leftSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    rightSpectrum->setSteps(&Globals::instance()->eq->range);
    rightSpectrum->setFilterRange(&Globals::instance()->eq->filterRange);
    
    
    guiLeft->addSlider("RANGE", 1, 16, 8);
    overrideSlider = guiLeft->addSlider("OVERRIDE", -1, 16, 8);
    
    guiLeft->addSlider("ALPHA", 0.0, 1.0,  &Globals::instance()->nsSceneManager->getScene(0)->globalAlpha);
    guiLeft->addSlider("GOBO", 0.0, 1.0,  &Globals::instance()->nsSceneManager->getScene(0)->globalGobo);
    guiLeft->addToggle("MAP ANIMS",   &mainScene->bmapAnims);
    guiLeft->addToggle("SOUND ALPHA", &mainScene->bSndAlpha);
    guiLeft->addToggle("FROST",  &Globals::instance()->nsSceneManager->getScene(0)->bGlobalFrost);
    guiLeft->addToggle("TAP TEMPO",   &Globals::instance()->editor->bTapTempoMode );

   // guiLeft->addToggle("SOUND GOBO",  &mainScene->bSndGobo);
    
    guiLeft->addSlider("SPEED", -1.0, 1.0,  &Globals::instance()->editor->playVel);
    guiLeft->addSlider("DECAY", 1.0, 10.0,  &Globals::instance()->nsSceneManager->getScene(0)->globalDecay);
    
    guiLeft->addSpacer();
    
    //guiLeft->addImageButton("BLANC", "imgs/red.png", true, 20, 20);
    guiLeft->addImageButton("BLANC", "imgs/blanc.png", true, 20, 20);
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/rouge.png", "ROUGE"), "BLANC");;
    
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/orange.png", "ORANGE"), "ROUGE");;
      
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/cyan.png", "CYAN"), "ORANGE");;
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/vert.png", "VERT"), "CYAN");;
  
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/vertclair.png", "VERT CLAIR"), "VERT");;
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/lila.png", "LILA"), "VERT CLAIR");;
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/rose.png", "ROSE"), "LILA");;
    guiLeft->addWidgetSouthOf(new ofxUIImageButton( 20, 20,  true, "imgs/jaune.png", "JAUNE"), "BLANC");;
    
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/Magenta.png", "MAGENTA"), "JAUNE");;
    guiLeft->addWidgetEastOf(new ofxUIImageButton( 20, 20,  true, "imgs/bleu.png", "BLEU"), "MAGENTA");;
    
    guiLeft->addSpacer();
    
    guiLeft->addSlider("VAR", 0.0, 1.0,  &Globals::instance()->animationManager->speedPct);
    guiLeft->addToggle("RELOAD JS", false);

    guiLeft->autoSizeToFitWidgets();
    
    
    
    //guiRight = new ofxUICanvas(220, ofGetHeight());
    //guiRight->setDrawBack(true);
    //animationsDropDown = guiRight->addDropDownList("ANIMATIONS", Globals::instance()->animationManager->getAnimations());
    
    guiLeft->loadSettings("gui.xml");
    
    ofAddListener(guiLeft->newGUIEvent,this,&NSGuiManager::guiEvent);
    //ofAddListener(guiRight->newGUIEvent,this,&NSGuiManager::guiEvent);
    
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
    guiEditorLeft->addSlider("MAX SPEED", 0.0, 1.0,  &Globals::instance()->editor->playVel);
    guiEditorLeft->addSpacer();
    guiEditorLeft->addLabelButton("NEW", false, true);
    guiEditorLeft->addLabelButton("DELETE", false, true);
    guiEditorRight = new ofxUICanvas(220, ofGetHeight());
    animationsEditorDropDown  = guiEditorRight->addDropDownList("ANIMS", Globals::instance()->dataManager->getAnimationsLabels());

    
    ofAddListener(guiEditorLeft->newGUIEvent,this,&NSGuiManager::guiEvent);
    
    setMode(0);
    
}

void NSGuiManager::setMode(int mode) {
    
    if(mode == 0) {
        
        guiLeft->enable();
        //guiRight->enable();
        
        guiEditorLeft->disable();
        guiEditorRight->disable();
        
        for (int i=rightCanvases.size() -1 ;  i>=0; i--) {
            rightCanvases[i]->enable();
        }
        
        
    } else {
        
        guiEditorLeft->enable();
        guiEditorRight->enable();
        //guiRight->disable();
        guiLeft->disable();
        
        for (int i=rightCanvases.size() -1 ;  i>=0; i--) {
            rightCanvases[i]->disable();
        }
        
    }
    
    this->mode = mode;
    
}

void NSGuiManager::populateAnimations() {
    
    // let's say 32
    vector<string> anims = Globals::instance()->animationManager->getAnimations();

    int numOfDropDowns = ceil(anims.size() / 52) +1;
    
   // printf("num drops %d", numOfDropDowns);
    
    
    
    for (int i = rightCanvases.size(); i<numOfDropDowns; i++) {
                
        rightCanvases.push_back(new ofxUICanvas(180));
        ofAddListener(rightCanvases[i]->newGUIEvent,this,&NSGuiManager::guiEvent);
        
        
        animationsDropDownList.push_back( rightCanvases[i]->addDropDownList("BANK"+ofToString(i+1), Globals::instance()->animationManager->getAnimations()) );
       
        animationsDropDownList[i]->setAllowMultiple(false);
        animationsDropDownList[i]->clearToggles();
        
    }
    
    for ( int i=0; i<numOfDropDowns; i++) {
        animationsDropDownList[i]->clearToggles();
    }
    
    for ( int i=0; i<anims.size(); i++) {
        
        int step = floor( i / 52);
        animationsDropDownList[step]->addToggle(anims[i]);
    
    }

    
}


void NSGuiManager::populateEditorAnimations() {
    
    animationsEditorDropDown->setAllowMultiple(false);
    animationsEditorDropDown->clearToggles();
    
    vector<string> anims = Globals::instance()->dataManager->getAnimationsLabels();
    for ( int i=0; i<anims.size(); i++)
        animationsEditorDropDown->addToggle(anims[i]);
    
}

void NSGuiManager::update() {
    //guiRight->getRect()->x              = ofGetWidth() - guiRight->getRect()->getWidth();
    
    guiEditorRight->getRect()->x            = ofGetWidth() - guiEditorRight->getRect()->getWidth();
    
    // translate drop downs
    
    
    for (int i=rightCanvases.size() -1 ;  i>=0; i--) {
        
        float x = rightCanvases.size() * rightCanvases[i]->getRect()->getWidth();
        x = ofGetWidth() -x;
        rightCanvases[i]->getRect()->x      = x + ( (i ) * rightCanvases[i]->getRect()->getWidth() );
        rightCanvases[i]->getRect()->height = ofGetHeight();
        
    }
     
     
    
    guiLeft->getRect()->height  = ofGetHeight();
    
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
    
    if(name == "BANK1") {
        
        vector<ofxUIWidget *> &selected = animationsDropDownList[0]->getSelected();
        for(int i = 0; i < selected.size(); i++){
            Globals::instance()->animationManager->setAnimation(selected[i]->getName(),0);
        }
         if(animationsDropDownList.size() > 1 ) animationsDropDownList[1]->clearSelected();
        
    }
    
    
    if(name == "BANK2") {
        
        vector<ofxUIWidget *> &selected = animationsDropDownList[1]->getSelected();
        for(int i = 0; i < selected.size(); i++){
            Globals::instance()->animationManager->setAnimation(selected[i]->getName(),0);
        }
        animationsDropDownList[0]->clearSelected();
        
    }
    
    if(name == "TOGGLE EDITOR") {
        
        ofxUIButton *button = (ofxUIButton *) e.widget;
        
        if(button->getValue() == 0) {

        
        int mode = ( this->mode == 0 ) ? 1 : 0;
        
                Globals::instance()->app->setMode(mode);
            
        }
        
    }
    
    if(name == "DELETE") {
        
        Globals::instance()->editor->deleteAnim();
        
    }
    
    if(name == "NEW") {
        
        Globals::instance()->editor->createNew();
        
    }
    
    if(name == "BLANC")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,255,255), name);
    
    if(name == "ROUGE")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,0,0), name);
    
    if(name == "ORANGE")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,90,0), name);
    
    if(name == "CYAN")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,255,255), name);
    
    if(name == "VERT")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,255,0), name);
    
    if(name == "VERT CLAIR")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(161,255,161), name);
    
    if(name == "LILA")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,144,255), name);
    
    if(name == "ROSE")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,150,255), name);
    
    if(name == "JAUNE")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,255,0), name);
    
    if(name == "MAGENTA")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,0,255), name);
    
    if(name == "BLEU")
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,0,255), name);
    
    
    
    
}

void NSGuiManager::setColorByIndex(int index) {
    
    
    
    
}

bool NSGuiManager::isBusy() {
    
    return (nameInput->clicked);
}

void NSGuiManager::exit () {
    
    guiLeft->saveSettings("gui.xml");
    
}

