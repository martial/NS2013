//
//  SvgHelper.h
//  NS2013
//
//  Created by Martial on 25/04/13.
//
//

#ifndef __NS2013__SvgHelper__
#define __NS2013__SvgHelper__

#include "ofMain.h"
#include "ofxXmlSettings.h"

class SvgHelper {
  
public:
    void            setup();
    void            load(string name);
    vector<ofVec3f> getPositions(string name);
    
    ofxXmlSettings  xml;
    string current;
    
};

#endif /* defined(__NS2013__SvgHelper__) */
