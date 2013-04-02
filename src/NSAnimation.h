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
#include "ofxJSScript.h"

class NSAnimation  {
    
public:
    NSAnimation(){};
    
    void setup(string scriptPath, int id);
    bool loadScript();
    void init(int scene);
    void update(int scene);
    void render();
    
    int                         id;
    string                      name;
    string                      scriptPath;
    
    ofxJSScript *               script;
    
    ofEvent<ofEventArgs>        needReload;
    
private:
    
    

    
    float                       checkTimer;
    int                         time;

    Poco::Timestamp             fileTimeStamp;
    
};

#endif /* defined(__NS2013__NSAnimation__) */
