//
//  NSSharpy.h
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#ifndef __NS2013__NSSharpy__
#define __NS2013__NSSharpy__

#include "ofMain.h"

class NSSharpy : public ofNode {
    
    
public:
    
    NSSharpy();
    void setup();
    void update();
    void draw();
    
    void setBrightness(int brighntess);
    void setGobo(float pct);
    
    void setID(int id);
    void getID(int id);
    
    void reset();
    
    /* */
    void sendToDmx();
    
private:
    
    int         id;
    float       maxRadius;
    float       brightness;
    float       goboPct;
    
    ofMesh      cylinder;
    
    
    
};

#endif /* defined(__NS2013__NSSharpy__) */
