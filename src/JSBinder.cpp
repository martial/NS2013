//
//  JSBinder.cpp
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#include "JSBinder.h"
#include "Globals.h"
#include "ofxJSUtils.h"
#include "jspubtd.h"

//class JSObject;
//--------------------------------------------------------------
bool initJS()
{ 
	// Some functions
	//
    ofxJSDefineFunctionGlobal("lookAt",                         &lookAt,                            5);
    ofxJSDefineFunctionGlobal("getPosX",                        &getPosX,                           2);
    ofxJSDefineFunctionGlobal("getPosY",                        &getPosY,                           2);
    ofxJSDefineFunctionGlobal("getPosZ",                        &getPosZ,                           2);
    ofxJSDefineFunctionGlobal("setRotation",                    &setRotation,                       4);
    ofxJSDefineFunctionGlobal("setOrientation",					&setOrientation,					5); 
    ofxJSDefineFunctionGlobal("forceLight",                     &forceLight,                        3); 
    ofxJSDefineFunctionGlobal("setGobo",                        &setGobo,                           3); 
    ofxJSDefineFunctionGlobal("setName",                        &setName,                           0); 
    
    ofxJSDefineFunctionGlobal("getMouseX",                      &getMouseX,                         0);
    ofxJSDefineFunctionGlobal("getMouseY",                      &getMouseY,                         0);

    ofxJSDefineFunctionGlobal("getPos",                         &getPos,                            1);
    
    ofxJSDefineFunctionGlobal("getCurrentTotalFrames",          &getCurrentTotalFrames,             0);
    ofxJSDefineFunctionGlobal("getCurrentAnimFrame",            &getCurrentAnimFrame,               0);
    
    
    ofxJSDefineFunctionGlobal("getWidth",                       &getWidth,                          0);
    ofxJSDefineFunctionGlobal("getHeight",                      &getHeight,                         0);
    ofxJSDefineFunctionGlobal("getDepth",                       &getDepth,                          0);
    
	// Load globals
	ofxJSScript * pScript = ofxJSLoadFromData("app.js", "app"); 
	if (pScript){
		bool evalOk = ofxJSEval(pScript);
		if (evalOk){
			printf("Loaded \"app.js\"\n");
		} else {
            ofGetAppPtr()->exit();
        }
	} 
	
	return true; // TODO err checking
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getWidth){
    
	if (argc == 0){
        
        //array_TO
		*retVal = float_TO_ofxJSValue(Globals::instance()->nsSceneManager->getScene(0)->width);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getHeight){
    
	if (argc == 0){
        
        //array_TO
		*retVal = float_TO_ofxJSValue(Globals::instance()->nsSceneManager->getScene(0)->height);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getDepth){
    
	if (argc == 0){
        
        //array_TO
		*retVal = float_TO_ofxJSValue(Globals::instance()->nsSceneManager->getScene(0)->depth);
        
		return JS_TRUE;
	}
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getCurrentTotalFrames){
    
	if (argc == 0){
        
        //array_TO
		*retVal = int_TO_ofxJSValue(Globals::instance()->editor->getTotalFrames());
        
		return JS_TRUE;
	}
    
	return JS_FALSE;
}

//--------------------------------------------------------------
ofxJSDefineFunctionCpp(getCurrentAnimFrame){
    
	if (argc == 0){
        
        //array_TO
		*retVal = int_TO_ofxJSValue(Globals::instance()->editor->currentFrame);
        
		return JS_TRUE;
	}
	return JS_FALSE;
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
ofxJSDefineFunctionCpp(getPos){
    
	if (argc == 1){
        
        int indexSharpy		= ofxJSValue_TO_int(argv[1]);
        
        ofVec3f pos = Globals::instance()->nsSceneManager->getScene(0)->getSharpyPos(indexSharpy);

                
        // Création d'un array[] côté javascript
		ofxJSObject* jsVec3f = JS_NewArrayObject(ofxJavascript::smp_instance->getContext(), 0, NULL);
        
		// Créé la propriété [0] de l'objet en READ_ONLY
		ofxJSValue	jsX = float_TO_ofxJSValue(pos.x);
		JS_DefineElement(ofxJavascript::smp_instance->getContext(), jsVec3f, 0, jsX, NULL, NULL, JSPROP_READONLY);
        
		// Créé la propriété [1] de l'objet en READ_ONLY
		ofxJSValue	jsY = float_TO_ofxJSValue(pos.y);
		JS_DefineElement(ofxJavascript::smp_instance->getContext(), jsVec3f, 1, jsY, NULL, NULL, JSPROP_READONLY);
        
		// Créé la propriété [2] de l'objet en READ_ONLY
		ofxJSValue	jsZ = float_TO_ofxJSValue(pos.z);
		JS_DefineElement(ofxJavascript::smp_instance->getContext(), jsVec3f, 2, jsZ, NULL, NULL, JSPROP_READONLY);
        
        //ofxJSObject * ahou =  OBJECT_TO_JSVAL((jsVec3f)->getJSObject(ofxJavascript::smp_instance->getContext()));
		//*retVal = objectp_TO_ofxJSValue(jsVec3f);
        
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
ofxJSDefineFunctionCpp(setRotation){
    
	if (argc == 4){
        
        int scene           = ofxJSValue_TO_int(argv[0]);
		int indexSharpy		= ofxJSValue_TO_int(argv[1]);
		float pan           = ofxJSValue_TO_float(argv[2]);
        float tilt          = ofxJSValue_TO_float(argv[3]);
        
        Globals::instance()->nsSceneManager->getScene(scene)->setRotation(indexSharpy, ofVec2f(pan, tilt));
        
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
ofxJSDefineFunctionCpp(forceLight){
    
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