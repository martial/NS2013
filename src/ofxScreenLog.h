//
//  ofxScreenLog.h
//  NS2013
//
//  Created by Martial on 02/04/13.
//
//
#define NUM_MSG_STRINGS 8
#ifndef __NS2013__ofxScreenLog__
#define __NS2013__ofxScreenLog__

#include "ofMain.h"

class ofxScreenLog {
    
public:
    ofxScreenLog() {
    }
        
    void log(string str) {
        messages.push_back(str);
    }
    
    void draw() {
        
        int max = ( (messages.size()) > NUM_MSG_STRINGS ) ? messages.size()-1 - NUM_MSG_STRINGS  : 0;
        int cnt = 0;
        ofDrawBitmapString("JS LOGGER", 228, 15);
        for(int i = messages.size()-1; i > max; i--){
            //ofSetColor(255 - ofMap(cnt, 0, NUM_MSG_STRINGS, 0, 255));
            
            string m = messages[i];
            if(cnt == 0 )
                m = "> " + m;
            else
                m = "  " + m;
            ofDrawBitmapString(m, 228, 30 + 15 * cnt);
            cnt++;
        }
         
    }
    
    vector<string> messages;
};

#endif /* defined(__NS2013__ofxScreenLog__) */
