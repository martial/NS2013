
//
//  NSAnimation.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSAnimation.h"

//--------------------------------------------------------------


void NSAnimation::setup(string scriptPath, int id) {
    
    checkTimer  = 0.f;
    time        = 0;
    this->id    = id;
    
    this->scriptPath = scriptPath;
    loadScript();
        
}

//--------------------------------------------------------------


void NSAnimation::loadScript() {
        
    
	if (scriptPath != "")
	{
		script = ofxJSLoad(ofToDataPath(scriptPath),"___tmpScript___");
               
		if (script){
			if (ofxJSEval(script))
			{
                return true;

			}
			else{
				ofLog(OF_LOG_ERROR, "ERROR > cannot eval script ");
			}
		}
		else{
			ofLog(OF_LOG_ERROR, "ERROR > cannot load script");
		}
	}
	else
		ofLog(OF_LOG_ERROR, "ERROR > path for script is empty...");
  
    
	return false;
    
}

void NSAnimation::init (int scene) {
    ofLog(OF_LOG_NOTICE, "INIT FROM OF -------------------------------------------");
    
    
    loadScript();
    
    
    
}

//--------------------------------------------------------------


void NSAnimation::update(int scene) {
    
    if (script)
	{
		// Reload
            checkTimer += .1;
			if (checkTimer>=1.0f){
                
                checkTimer = 0.0f;
				ofFile fileScript(ofToDataPath(scriptPath, true));
				Poco::File& pocoFileScript = fileScript.getPocoFile();
				Poco::Timestamp timestamp = pocoFileScript.getLastModified();
				if (timestamp > fileTimeStamp){
					fileTimeStamp = timestamp;
					loadScript();
                    init(scene);
                    
                    ofEventArgs e;
                    ofNotifyEvent(needReload, e, this);
                    
                    
				}
			}
        time++;
	}
    
}

//--------------------------------------------------------------


void NSAnimation::render() {
    
    
    
}