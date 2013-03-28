
//
//  NSAnimation.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "NSAnimation.h"

//--------------------------------------------------------------


void NSAnimation::setup(string scriptPath) {
    
    checkTimer  = 0.f;
    time        = 0;
    
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
				ofxJSValue retVal;
                
                // Call setup
                ofxJSValue args[1];
                args[0] = float_TO_ofxJSValue(checkTimer);
                ofxJSCallFunctionNameGlobal_IfExists("setup", args,1,retVal);
                time        = 0;
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

//--------------------------------------------------------------


void NSAnimation::update() {
    
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
				}
			}
		
		// Call update
		ofxJSValue retVal;
		ofxJSValue args[1];
		args[0] = int_TO_ofxJSValue(time);
		ofxJSCallFunctionNameGlobal_IfExists("update", args,1,retVal);
        time++;
	}
    
}

//--------------------------------------------------------------


void NSAnimation::render() {
    
    
    
}