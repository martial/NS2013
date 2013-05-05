//
//  NSMidiMiniManager.cpp
//  NS2013
//
//  Created by Martial on 03/05/13.
//
//

#include "NSMidiMiniManager.h"

#include "Globals.h"

void NSMidiMiniManager::setup() {
    
    // print input ports to console
	midiIn.listPorts(); // via instance
	//ofxMidiIn::listPorts(); // via static as well
    
	// open port by number (you may need to change this)
	midiIn.openPort(3);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
    
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(true, false, false);
    
	// add testApp as a listener
	midiIn.addListener(this);
    
    
    
}

void NSMidiMiniManager::update() {
    
    bIsFrameNew = true;
    
    
}

void NSMidiMiniManager::newMidiMessage(ofxMidiMessage& msg) {
    
    
    
    
    // if(msg.control > 0 )
    printf("channel received %d, pitch %d,note %d, velocity %d, control %d \n", msg.channel, msg.pitch, msg.value, msg.velocity, msg.control);
    float normalized = ofNormalize((float)msg.value, 0, 127);
    float val;
    
    
    switch (msg.control) {
            
        case 8:
            
            Globals::instance()->nsSceneManager->getScene(0)->globalAlpha = normalized;

            
            break;
            
        case 9:
            
            
            Globals::instance()->nsSceneManager->getScene(0)->globalGobo = normalized;

            break;
            
        
        case 10:
            
            
            Globals::instance()->editor->playVel                = normalized;
            Globals::instance()->app->editorPreview.playVel     = normalized;
            
            
            
            break;
            
        case 11:
            
            
            Globals::instance()->nsSceneManager->getScene(0)->globalDecay = 1 + (normalized * 9.0);
            break;
            
            
            
            
        default:
            break;
            
    }
    
    
    
    switch (msg.pitch) {
            
        case 0:
            
            if(msg.velocity != 127) {
                Globals::instance()->editor->pushFrame();
            }
                        
        break;
            
        case 4:
            
                
            printf("gogogo");
            Globals::instance()->editor->bTapTempoMode = !Globals::instance()->editor->bTapTempoMode;
                            
        break;
            
        case 14:
            
            
            printf("gogogo");
            Globals::instance()->editor->bTapTempoMode = !Globals::instance()->editor->bTapTempoMode;
            
            break;

            
            
        
            
        default:
            break;
            
    }
    
      
    if(msg.pitch == 14)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,255,255), "BLANC");
    
    if(msg.pitch == 15)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,0,0), "ROUGE");
    
    if(msg.pitch == 16)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,90,0), "ORANGE");
    
    if(msg.pitch == 17)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,255,255), "CYAN");
    
    if(msg.pitch == 18)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,255,0), "VERT");
    
    if(msg.pitch == 19)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(161,255,161), "VERT CLAIR");
    
    if(msg.pitch == 20)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,144,255), "LILA");
    
    if(msg.pitch == 21)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,150,255), "ROSE");
    
    if(msg.pitch == 22)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,255,0), "JAUNE");
    
    if(msg.pitch == 23)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(255,0,255), "MAGENTA");
    
    if(msg.pitch == 24)
        Globals::instance()->nsSceneManager->getScene(0)->setSharpyColor(ofColor(0,0,255), "BLEU");
    
    
}
