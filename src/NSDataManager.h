//
//  NSDataManager.h
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#ifndef __NS2013__NSDataManager__
#define __NS2013__NSDataManager__

#include "ofMain.h"
#include "ofxXmlSettings.h"

class NSDataManager {
  
public:
    
    void upload();
    
    
};

#endif /* defined(__NS2013__NSDataManager__) */

#ifndef __NS2013__NSANimData
#define __NS2013__NSANimData

class AnimData {
  
public:
    
    string name;
    vector<vector<int> > data;
    
    ofxXmlSettings  toXML() {
        
        ofxXmlSettings xml;
        xml.setVerbose(true);
        xml.addTag("root");
        xml.pushTag("root");
        xml.addTag("config");
        xml.setValue("config:name", name);
        
        xml.addTag("frames");
        xml.pushTag("frames");
        
        for (int i=0; i<data.size(); i++) {
            
            xml.addTag("frame");
            //xml.pushTag("frame", i);
            
            for (int j=0; j<data[i].size(); j++) {
                xml.setValue("frame:id", data[i][j], j);
            }
            
           xml.popTag();
            
        }
        xml.saveFile("AHOU.XML");
        
        return xml;
        
    }
    
    
};

#endif