//
//  SvgHelper.cpp
//  NS2013
//
//  Created by Martial on 25/04/13.
//
//

#include "SvgHelper.h"

void SvgHelper::load(string name) {
    
    xml.clear();
    xml.loadFile("svg/"+name);
    
    
    //xml.
    
    xml.pushTag("svg");
    
    int numNodes = xml.getNumTags("g");
    
    for (int i=0; i<numNodes; i++) {
        
        xml.pushTag("g", i);
        
        int id  = xml.getValue("text", 0);
        float x = xml.getAttribute("circle", "cx", 0.0);
        float y = xml.getAttribute("circle", "cy", 0.0);
        
        //ofLog(OF_LOG_NOTICE, "id %d x %f y %f", id, x, y);
        
        xml.popTag();
        
        
        
    }
    
    xml.popTag();
    
}

vector<ofVec3f> SvgHelper::getPositions (string name) {
    
    if(name != current)
        load(name);
    
    vector<ofVec3f> positions;
    
    xml.pushTag("svg");
    
    int numNodes = xml.getNumTags("g");
    
    for (int i=0; i<numNodes; i++) {
        
        xml.pushTag("g", i);
        
        int id  = xml.getValue("text", 0);
        float x = xml.getAttribute("circle", "cx", 0.0);
        float y = xml.getAttribute("circle", "cy", 0.0);
                
        positions.push_back(ofVec3f(x,y, id));
                
        xml.popTag();
                
    }
    
    xml.popTag();

    
    current = name;
    
    return positions;
}