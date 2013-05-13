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
#include "NSLoadingScreen.h"
#include "NSDMXManager.h"
#include "app.h"

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
    NSDMXManager    *           dmxManager;
    
    NSLoadingScreen *           loadingScreen;
    app         *               app;
    
    
    int                         DMX1_PORT, DMX2_PORT, USB1_PORT, USB2_PORT;
    
	    
private:
    static Globals*			inst;
};
