//
//  NSAnimation.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#ifndef __NS2013__NSAnimation__
#define __NS2013__NSAnimation__

#include "ofMain.h"
#include "ofxJavascript.h"

class NSAnimation  {
    
public:
    NSAnimation(){};
    
    void setup(string scriptPath);
    void loadScript();
    void update();
    void render();
    
    
    string                      name;
    
private:
    
    string                      scriptPath;
    ofxJSScript *               script;
    
    float                       checkTimer;
    int                         time;

    Poco::Timestamp             fileTimeStamp;
    
};

#endif /* defined(__NS2013__NSAnimation__) */
