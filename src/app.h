#pragma once

#include "ofMain.h"
#include "NSScene.h"
#include "NSGuiManager.h"
#include "NSEditor.h"
#include "ofxEQ.h"

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

    
        void guiEvent(ofxUIEventArgs &e);
    
        void exit();
    
        NSScene             scene;
        NSGuiManager        guiManager;
        NSEditor            editor;
    
        ofxEQ               eq;
		
};
