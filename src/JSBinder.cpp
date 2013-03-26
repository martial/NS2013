//
//  JSBinder.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "JSBinder.h"
#include "Globals.h"

//--------------------------------------------------------------
bool initJS()
{
	// Some functions
	//
    ofxJSDefineFunctionGlobal("setOrientation",					&setOrientation,					4); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setBrightness",					&setBrightness,                     2); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setGobo",                        &setGobo,                           2); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setName",                        &setName,                           0); // name, function pointer, args number
    
	// Load globals
	ofxJSScript * pScript = ofxJSLoadFromData("app.js", "app"); 
	if (pScript){
		bool evalOk = ofxJSEval(pScript);
		if (evalOk){
			printf("Loaded \"app.js\"\n");
		} else {
            printf("Loaded badly \"app.js\"\n");
        }
	} 
	
	return true; // TODO err checking
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setName){
    
	if (argc == 0){
        
		int indexSharpy		= ofxJSValue_TO_int(argv[0]);
		float pan	= ofxJSValue_TO_float(argv[1]);
        float tilt	= ofxJSValue_TO_float(argv[2]);
        float roll	= ofxJSValue_TO_float(argv[3]);
        
        //Globals::instance()->nsScene->setOrientation(indexSharpy, ofVec3f(pan, tilt, roll));
        
		//float val = Globals::instance()->M_getClientBass(indexClient,indexChannel);
		//*retVal = float_TO_ofxJSValue(val);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setOrientation){
    
	if (argc == 4){
        
		int indexSharpy		= ofxJSValue_TO_int(argv[0]);
		float pan	= ofxJSValue_TO_float(argv[1]);
        float tilt	= ofxJSValue_TO_float(argv[2]);
        float roll	= ofxJSValue_TO_float(argv[3]);
        
        Globals::instance()->nsScene->setOrientation(indexSharpy, ofVec3f(pan, tilt, roll));
        
		//float val = Globals::instance()->M_getClientBass(indexClient,indexChannel);
		//*retVal = float_TO_ofxJSValue(val);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setBrightness){
    
	if (argc == 2){
        
		int indexSharpy		= ofxJSValue_TO_int(argv[0]);
		float pct           = ofxJSValue_TO_float(argv[1]);

        Globals::instance()->nsScene->setBrightness(indexSharpy, pct);
        
		//float val = Globals::instance()->M_getClientBass(indexClient,indexChannel);
		//*retVal = float_TO_ofxJSValue(val);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setGobo){
    
	if (argc == 2){
        
		int indexSharpy		= ofxJSValue_TO_int(argv[0]);
		float pct           = ofxJSValue_TO_float(argv[1]);
        
        Globals::instance()->nsScene->setGobo(indexSharpy, pct);
        
		//float val = Globals::instance()->M_getClientBass(indexClient,indexChannel);
		//*retVal = float_TO_ofxJSValue(val);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}