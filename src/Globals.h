//
//  Globals.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#pragma once
#include "NSSceneManager.h"
#include "NSScene.h"
#include "ofxEQ.h"
#include "ofxScreenLog.h"

class Globals
{
public:
    
    Globals					();
    static Globals*			instance();
    
    
    NSSceneManager *        nsSceneManager;
    ofxEQ       *           eq;
    ofxScreenLog *          screenLog;
	    
private:
    static Globals*			inst;
};
