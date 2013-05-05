//
//  JSBinder.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#pragma once
#include "ofMain.h"
#include "ofxJavascript.h"

ofxJSScript * initJS();

ofxJSDeclareFunctionCpp(getPosX);
ofxJSDeclareFunctionCpp(getPosY);
ofxJSDeclareFunctionCpp(getPosZ);

ofxJSDeclareFunctionCpp(lookAt);
ofxJSDeclareFunctionCpp(setRotation);
ofxJSDeclareFunctionCpp(setOrientation);
ofxJSDeclareFunctionCpp(forceLight);
ofxJSDeclareFunctionCpp(setGobo);

ofxJSDeclareFunctionCpp(setFinePanTilt);

ofxJSDeclareFunctionCpp(setName);


ofxJSDeclareFunctionCpp(getMouseX);
ofxJSDeclareFunctionCpp(getMouseY);

ofxJSDeclareFunctionCpp(getPos);

ofxJSDeclareFunctionCpp(getWidth);
ofxJSDeclareFunctionCpp(getHeight);
ofxJSDeclareFunctionCpp(getDepth);

ofxJSDeclareFunctionCpp(getCurrentTotalFrames);
ofxJSDeclareFunctionCpp(getCurrentAnimFrame);

ofxJSDeclareFunctionCpp(lookAtSvg);

