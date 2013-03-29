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
    ofxJSDefineFunctionGlobal("lookAt",                         &lookAt,                            5);
    ofxJSDefineFunctionGlobal("getPosX",                        &getPosX,                           2);
    ofxJSDefineFunctionGlobal("getPosY",                        &getPosY,                           2);
    ofxJSDefineFunctionGlobal("getPosZ",                        &getPosZ,                           2);
    ofxJSDefineFunctionGlobal("setOrientation",					&setOrientation,					5); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setBrightness",					&setBrightness,                     3); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setGobo",                        &setGobo,                           3); // name, function pointer, args number
    ofxJSDefineFunctionGlobal("setName",                        &setName,                           0); // name, function pointer, args number
    
    ofxJSDefineFunctionGlobal("getMouseX",                      &getMouseX,                           0);
    ofxJSDefineFunctionGlobal("getMouseY",                      &getMouseY,                           0);
    
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
ofxJSDefineFunctionCpp(getMouseX){
    
	if (argc == 0){
        
		*retVal = int_TO_ofxJSValue(ofGetMouseX());
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getMouseY){
    
	if (argc == 0){
        
		*retVal = int_TO_ofxJSValue(ofGetMouseY());
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(lookAt){
    
	if (argc == 5){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
        float x             = ofxJSValue_TO_float(argv[2]);
        float y             = ofxJSValue_TO_float(argv[3]);
        float z             = ofxJSValue_TO_float(argv[4]);
        
        Globals::instance()->nsSceneManager->getScene(scene)->sharpyLookAt(indexSharpy, ofVec3f(x,y,z));

		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getPosX){
    
	if (argc == 2){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);

        ofVec3f pos = Globals::instance()->nsSceneManager->getScene(scene)->getSharpyPos(indexSharpy);
		*retVal = float_TO_ofxJSValue(pos.x);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getPosY){
    
	if (argc == 2){
        
		int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
        
        ofVec3f pos = Globals::instance()->nsSceneManager->getScene(scene)->getSharpyPos(indexSharpy);
		*retVal = float_TO_ofxJSValue(pos.y);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getPosZ){
    
    if (argc == 2){
        
		int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
        
        ofVec3f pos = Globals::instance()->nsSceneManager->getScene(scene)->getSharpyPos(indexSharpy);
		*retVal = float_TO_ofxJSValue(pos.z);
        
		return JS_TRUE;
	}
	return JS_FALSE;
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
    
	if (argc == 5){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
		float pan           = ofxJSValue_TO_float(argv[2]);
        float tilt          = ofxJSValue_TO_float(argv[3]);
        float roll          = ofxJSValue_TO_float(argv[4]);
        
        Globals::instance()->nsSceneManager->getScene(scene)->setOrientation(indexSharpy, ofVec3f(pan, tilt, roll));
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setBrightness){
    
	if (argc == 3){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
		float pct           = ofxJSValue_TO_float(argv[2]);

        Globals::instance()->nsSceneManager->getScene(scene)->setBrightness(indexSharpy, pct);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(setGobo){
    
	if (argc == 3){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
		float pct           = ofxJSValue_TO_float(argv[2]);
        
        Globals::instance()->nsSceneManager->getScene(scene)->setGobo(indexSharpy, pct);
        
		//float val = Globals::instance()->M_getClientBass(indexClient,indexChannel);
		//*retVal = float_TO_ofxJSValue(val);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}