#pragma once

#include "ofMain.h"
#include "NSSceneManager.h"
#include "NSGuiManager.h"
#include "NSAnimationManager.h"
#include "ofxEQ.h"
#include "ofxScreenLog.h"
#include "NSEditor.h"
#include "NSDataManager.h"
#include "NSLoadingScreen.h"
#include "NSDMXManager.h"

#define animationManager_MODE

class app : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void audioReceived (float * input, int bufferSize, int nChannels);

    
    
        void exit();
    
        NSSceneManager          sceneManager;
        NSGuiManager            guiManager;
        NSAnimationManager      animationManager;
        NSDataManager           dataManager;
        NSLoadingScreen         loadingScreen;
        NSDMXManager            dmxManager;
        NSEditor                editor;
    
        ofxEQ                   eq;
    
        ofxScreenLog            screenLog;
    
    
    
        int                     mode;
		
};
