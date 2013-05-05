//
//  NSDataManager.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxCurl.h"

#ifndef __NS2013__NSANimData
#define __NS2013__NSANimData

class AnimData {
    
public:
    
    string     id;
    string  name;
    float   maxSpeed;
    vector<vector<int> > data;
        
    AnimData() {
        id = "";
    }
    ofxXmlSettings  toXML() {
        
        ofxXmlSettings xml;
        xml.setVerbose(true);
        xml.addTag("root");
        xml.pushTag("root");
        xml.addTag("config");
        xml.setValue("config:id", id);
        xml.setValue("config:name", name);
        xml.setValue("config:speed", maxSpeed);
        
        xml.addTag("frames");
        xml.pushTag("frames");
        
        for (int i=0; i<data.size(); i++) {
            
            xml.addTag("frame");
            xml.pushTag("frame", i);
            
            for (int j=0; j<data[i].size(); j++) {
                xml.setValue("id", data[i][j], j);
            }
            
            xml.popTag();
            
        }
        xml.saveFile("anim.xml");
        
        return xml;
        
    }
    
    
};

#endif

#ifndef __NS2013__NSDataManager__
#define __NS2013__NSDataManager__



class NSDataManager : public ofThread {
  
public:
    
    NSDataManager();
    
    void setup();
    void exit();
    void load();
    
    void startUpload();
    void upload();
    void deleteAnim(int id);
    void urlResponse(ofHttpResponse & response);
    
    
    void threadedFunction();
    
    ofPtr<AnimData>         getAnimation(int index);
    ofPtr<AnimData>         getAnimation(string name);
    int                     getAnimationId(string name);
    
    
    vector<string>          getAnimationsLabels();
    
    ofEvent<int>            onError;
    ofEvent<int>            onUploadSuccess;
    ofEvent<int>            onLoadSuccess;
    ofEvent<int>            onDeleteSuccess;
    
    vector<ofPtr<AnimData> >   animations;
    
    bool                    bSending;
    
};

#endif /* defined(__NS2013__NSDataManager__) */

