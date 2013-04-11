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
#include "NSAnimationManager.h"
#include "NSEditor.h"
#include "NSGuiManager.h"
#include "NSDataManager.h"

class Globals
{
public:
    
    Globals					();
    static Globals*			instance();
    
    
    NSSceneManager *            nsSceneManager;
    ofxEQ       *               eq;
    ofxScreenLog *              screenLog;
    NSAnimationManager    *     animationManager;
    
    NSEditor *                  editor;
    
    NSGuiManager *              gui;
    NSDataManager   *           dataManager;
    
	    
private:
    static Globals*			inst;
};
