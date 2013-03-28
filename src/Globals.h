//
//  Globals.h
//  NS2013
//
//  Created by Martial on 26/03/13.
//
//

#pragma once
#include "NSScene.h"
#include "ofxEQ.h"

class Globals
{
public:
    
    Globals					();
    static Globals*			instance();
    
    NSScene     *           nsScene;
    ofxEQ       *           eq;
	    
private:
    static Globals*			inst;
};
