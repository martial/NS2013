//
//  NSDMXManager.h
//  NS2013
//
//  Created by Martial on 12/04/13.
//
//

#ifndef __NS2013__NSDMXManager__
#define __NS2013__NSDMXManager__

#include "ofMain.h"
#include "NSSharpy.h"
#include "ofxDmx.h"

class NSDMXManager {
    
  
public:
    
    void setup(vector<ofPtr<NSSharpy> >  * sharpies);
    void update();
    void draw();
    
    
    void onSharpyEvent(vector<ofPoint> & data);
    void resetAll();
    
private:
    
    ofxDmx dmx;
    vector<ofPtr<NSSharpy> >  * sharpies;
    
};

#endif /* defined(__NS2013__NSDMXManager__) */
