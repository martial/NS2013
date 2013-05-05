//
//  NSMidiMiniManager.h
//  NS2013
//
//  Created by Martial on 03/05/13.
//
//

#ifndef __NS2013__NSMidiMiniManager__
#define __NS2013__NSMidiMiniManager__

#include "ofMain.h"
#include "ofxMidi.h"

class NSMidiMiniManager : public ofxMidiListener  {
    
public:
    
    void setup();
    void update();
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
    private :
    
    
    ofxMidiIn midiIn;
    ofxMidiOut midiOut;
    bool        bIsFrameNew;
    
    
};



#endif /* defined(__NS2013__NSMidiManager__) */
