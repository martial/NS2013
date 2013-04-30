//
//  NSMidiManager.h
//  NS2013
//
//  Created by Martial on 29/04/13.
//
//

#ifndef __NS2013__NSMidiManager__
#define __NS2013__NSMidiManager__

#include "ofMain.h"
#include "ofxMidi.h"

class NSMidiManager : public ofxMidiListener  {
  
public:
    
    void setup();
    void update();
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
private :
    
    
    ofxMidiIn midiIn;
    bool        bIsFrameNew;
    
};



#endif /* defined(__NS2013__NSMidiManager__) */
