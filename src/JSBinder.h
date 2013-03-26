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

bool initJS();

ofxJSDeclareFunctionCpp(setOrientation);
ofxJSDeclareFunctionCpp(setBrightness);
ofxJSDeclareFunctionCpp(setGobo);

ofxJSDeclareFunctionCpp(setName);