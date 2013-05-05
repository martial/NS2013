//
//  NSDataManager.cpp
//  NS2013
//
//  Created by Martial on 10/04/13.
//
//

#include "NSDataManager.h"
#include "Globals.h"
NSDataManager::NSDataManager () {
     ofRegisterURLNotification(this);
    
    bSending = false;
}

void NSDataManager::setup() {
    
    this->startThread(false, true);
    
}

void NSDataManager::exit() {
    this->stopThread();
}

void NSDataManager::urlResponse(ofHttpResponse & response) {
    
    
    //printf("response %d", response.status);
    
    if(response.status !=200 && response.request.name != "load" ) {
        int tmp = 0;
        ofNotifyEvent(onError, tmp, this);
        return;

    }
           
    if(response.request.name == "load" ) {
    
    ofxXmlSettings xml;
        
    if(response.status ==200 ) {
        xml.loadFromBuffer(response.data);
        xml.saveFile("anims.xml");
        
    } else {
        xml.loadFile("anims.xml");

    }
    
    animations.clear();
        
    xml.pushTag("root");
    int numAnims = xml.getNumTags("anim");
    
    for (int i=0; i<numAnims; i++) {
        
        ofPtr<AnimData> animDataRef(new AnimData());
        
        // get num frames
        xml.pushTag("anim", i);
        
        animDataRef->name       = xml.getValue("config:name", "error");
        animDataRef->maxSpeed   = xml.getValue("config:speed", 1.0);
        animDataRef->id         = ofToString(xml.getValue("config:id", 0));
        
        vector<vector<int> > data;
        
        xml.pushTag("frames");
        int numFrames = xml.getNumTags("frame");
       // printf("nFrames %d\n", numFrames);
        
        
        for (int j=0; j<numFrames; j++) {
            
            
            
            xml.pushTag("frame", j);
            int numIds = xml.getNumTags("id");
            //printf("nIds %d\n", numIds);
            vector<int> ids;
            for (int k=0; k<numIds; k++) {
                
                //xml.pushTag("id", j);
                //printf("id %d\n", xml.getValue("id", 0, k));
                int val = xml.getValue("id", -1, k);
                if(val > -1 )
                ids.push_back(val);
                
                
            }
            
            data.push_back(ids);
            xml.popTag();
                        
            
        }
        
        animDataRef->data = data;
        xml.popTag();
        xml.popTag();
        
        animations.push_back(animDataRef);
        
    }
    
    int tmp = 0;
    printf("Yo mama send event from load \n");
    ofNotifyEvent(onLoadSuccess, tmp, this);
        
    }
    
    if(response.request.name == "delete") {
        
        
        int tmp = 0;
        
        ofNotifyEvent(onDeleteSuccess, tmp, this);
        
    }
    
}

vector<string> NSDataManager::getAnimationsLabels() {
    
    vector<string> labels;
    for (int i=0; i<animations.size(); i++) {
        labels.push_back(animations[i]->name);
        
    }
    return labels;    
}


void NSDataManager::load() {
    
    printf("Yo coco load xml \n");

    ofLoadURLAsync("http://www.forme-libre.com/ns2013/ns/getxml", "load");
    Globals::instance()->loadingScreen->show();
    
}

void NSDataManager::deleteAnim(int id) {
    
    ofLoadURLAsync("http://www.forme-libre.com/ns2013/ns/delete/"+ofToString(id), "delete");
    Globals::instance()->loadingScreen->show();
    
}

ofPtr<AnimData>  NSDataManager::getAnimation(int index) {
    
    return animations[index];
    
}

ofPtr<AnimData>  NSDataManager::getAnimation(string name) {
    
    for (int i=0; i<animations.size(); i++) {
        
        if (name == animations[i]->name)
            return animations[i];
        
    }
    
    return ofPtr<AnimData>();
    
}


int  NSDataManager::getAnimationId(string name) {
    
    for (int i=0; i<animations.size(); i++) {
        
        if (name == animations[i]->name)
            return i;
        
    }
    
    return -1;
    
}

void NSDataManager::threadedFunction() {
    
    while(isThreadRunning()){
        
        
        if(bSending) {
            lock();
            upload();
            bSending = false;
            unlock();
        }
        
        sleep(20);
    }
    
    
}

void NSDataManager::startUpload() {
    bSending = true;
}

void NSDataManager::upload() {
    
    ofxCurl curl;
    ofxCurlForm* form = curl.createForm("http://www.forme-libre.com/ns2013/ns/upload/");
    
    form->addFile("xml",ofToDataPath("anim.xml",true));
    
    // Perform the post.
    try {
        form->post();
    }
    catch(...) {
        cout << "OOPS.. something went wrong while posting" << endl;
        int a = 0;
        ofNotifyEvent(onError, a, this);
    }
    
    // Do something with the response from the post.
    vector<char> response_buf = form->getPostResponseAsBuffer();
    string response_str = form->getPostResponseAsString();
    cout << "Size of response buffer: " << response_buf.size() << endl << endl;
    cout << "Response string:" << endl;
    cout << "-----------------" << endl;
    cout << response_str <<endl;
    
    int id = 0;
    
    if(response_str.size() == 0 ) {
         ofNotifyEvent(onError, id, this);
        return;
    }
    
    if(response_str == "success" ) {
        
       // ofNotifyEvent(onUploadSuccess, id, this);
        
    } else {
        
        printf("Yo mama send event \n");
        int id = ofToInt(response_str);
        ofNotifyEvent(onUploadSuccess, id, this);
        
    }
        
    // Cleanup
    delete form;

    
    
}