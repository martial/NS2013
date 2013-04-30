//
//  NSMidiManager.cpp
//  NS2013
//
//  Created by Martial on 29/04/13.
//
//

#include "NSMidiManager.h"
#include "Globals.h"

void NSMidiManager::setup() {
    
    // print input ports to console
	midiIn.listPorts(); // via instance
	//ofxMidiIn::listPorts(); // via static as well
    
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input");	// open a virtual port
    
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
    
	// add testApp as a listener
	midiIn.addListener(this);
    
    
    
}

void NSMidiManager::update() {
    
    bIsFrameNew = true;
    
}

void NSMidiManager::newMidiMessage(ofxMidiMessage& msg) {
    
    
    
    
   // if(msg.control > 0 )
    printf("channel received %d, pitch %d,note %d, velocity %d, control %d \n", msg.channel, msg.pitch, msg.value, msg.velocity, msg.control);
    
    float normalized = ofNormalize((float)msg.value, 0, 127);
    float val;
    
    switch (msg.control) {
        case 20:
            Globals::instance()->nsSceneManager->getScene(0)->globalAlpha = normalized;
            break;
            
        case 21:
            Globals::instance()->nsSceneManager->getScene(0)->globalGobo = normalized;
            break;
            
        case 26:
            Globals::instance()->nsSceneManager->getScene(0)->globalStrob = normalized;
            break;

            
        case 27:
            Globals::instance()->nsSceneManager->getScene(0)->globalFullStrob = normalized;
            break;
            
        case 9:
            Globals::instance()->nsSceneManager->getScene(0)->globalDecay = 1 + (normalized * 9.0);
            break;
            
        case 3:
            Globals::instance()->editor->playVel                = - 1 + normalized * 2.0;
            Globals::instance()->app->editorPreview.playVel     = - 1 + normalized * 2.0;
            break;
            
            
        case 14:
            
            val = normalized * 16.0;
            Globals::instance()->eq->setRange(val);
            if(Globals::instance()->eq->filterRange > val )
                Globals::instance()->eq->setFilterRange(val - 1);
            
            break;
            
        case 15:
            
            val = -1 + normalized * 16.0;
            Globals::instance()->eq->setFilterRange(val);
            break;
            
      
            
        case 96:
            
            if(msg.channel == 1) {
                Globals::instance()->editor->popAnim(true);
            }
             
            else {
                
                if(msg.channel == 1) {
                    Globals::instance()->app->editorPreview.popAnim(true);

                } else {
                        Globals::instance()->animationManager->bNeedsPopPreview = true;
                        
                }
                
            }
            
        break;

        case 97:
        if(msg.channel == 1)
            Globals::instance()->app->editorPreview.pushAnim(true);
        else
             Globals::instance()->animationManager->bNeedsPushPreview = true;

            
            break;

            
        default:
            break;
    }
    
    switch (msg.pitch) {
            
        case 48:
            
            Globals::instance()->nsSceneManager->getScene(0)->bmapAnims = !Globals::instance()->nsSceneManager->getScene(0)->bmapAnims;
            
            break;

            
        case 49:
            
            Globals::instance()->nsSceneManager->getScene(0)->bSndAlpha = !Globals::instance()->nsSceneManager->getScene(0)->bSndAlpha;
            
            break;
            
        case 50:
            
            Globals::instance()->nsSceneManager->getScene(0)->bGlobalFrost = !Globals::instance()->nsSceneManager->getScene(0)->bGlobalFrost;
            
            break;

            
        case 36:
            
            Globals::instance()->animationManager->setAnimation( Globals::instance()->animationManager->currentPreviewIndex, 0);
            
            break;
            
        case 37:
            
            Globals::instance()->editor->setAnim(Globals::instance()->app->editorPreview.currentAnimation);
            Globals::instance()->editor->play();
            break;
            
        default:
            break;
            
    }
    
    	
}
