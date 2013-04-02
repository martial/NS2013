#pragma once

#include "ofMain.h"
#include "NSSceneManager.h"
#include "NSGuiManager.h"
#include "NSEditor.h"
#include "ofxEQ.h"
#include "ofxScreenLog.h"


#define EDITOR_MODE

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
    
        NSSceneManager      sceneManager;
        NSGuiManager        guiManager;
        NSEditor            editor;
    
        ofxEQ               eq;
    
        ofxScreenLog        screenLog;
		
};
