//
//  NSSharpy.h
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//



#ifndef __NS2013__NSSharpy__
#define __NS2013__NSSharpy__

#include "ofMain.h"
#include "ofxTween.h"
#include "SharpyModel.h"

class NSSharpyTarget;
class NSSharpy : public ofNode {
    
    
public:
    
    NSSharpy();
    void        setup();
    void        update();
    void        draw(bool bDrawIds);

    void        transToTargetOrientation();
    void        setTargetOrientation(ofVec3f orientation);
    
    void        setBrightness(float brighntessPct);
    float       getBrightness();
    void        setGobo(float pct);
    float       getGobo();
    
    void        setFinePos(float x, float y);
    void        setFinePanTilt(float pan, float tilt);
    
    void        setID(int id);
    int         getID() {return this->id;}
    
    ofVec2f     calculatePanTilt();
    ofVec3f     getEulerDistance();
    int         getAngleDIstance(float a, float b);
    
    void        reset();
    
    ofVec3f     lookAtPnt;
    
    /* */
    void                        sendToDmx();
    ofEvent<vector<ofPoint> >   dmxEvent;
    
    NSSharpyTarget *    target;
    
    float               brightness;
    float               forcedBrightness;
    float               currentGoboPct, goboPct;
    
    bool                currentFrost, bFrost;
    
    float               rotationX, rotationY;
    float               decay;
    
    ofPoint             finePos;
    float               finePan, fineTilt;
    
    
    ofNode              tmpParentNode;
    ofNode              tmpChildNode;
    
    ofColor             color;
    string              colorName;
    
    
    
    
private:
    
    void                updateCylinder();
    int                 getColorAdressByName(string name);
    
    int                 id;
    float               maxRadius;
    ofMesh              cylinder;
    
    float               currentAlpha;
    
    float               alpha, beta;
    
    ofxTween            brtTween;
    ofxEasingLinear     linear;
    
    
    
    
};


#endif /* defined(__NS2013__NSSharpy__) */


/* ----------------------------------------------------------
**  NSSharpyTarget will be the values to update
 *  JS files are updating this object and NSSarpy will try to reach this
 *  As this we can have a better control on speed, and transitions
 *  Also It's ensure constant update for brightness and gobo
 *  
 */
 
#ifndef __NS2013__NSSharpyTarget__
#define __NS2013__NSSharpyTarget__

#include "ofxEasingLinear.h"
class NSSharpyTarget  : public ofNode {
    
public:
    
    NSSharpyTarget() {
        
        brt         = 1.0;
        goboPct     = 1.0;
        orientation = ofVec3f(0,0,0);
        slerpPct    = 0.0;
        
        
        for(int i=0; i<2; i++ ) {
            ofxTween  * tween = new ofxTween();
            tween->setParameters(linear, ofxTween::easeOut, 0, 0, 1, 0);
            tween->start();
            tweens.push_back(tween);
            
            }
        
    }
    
    
    
        ofVec2f         setTweenedOrientation (float rotationX, float rotationY ) {
            
            
     
            
        float xDist = fabs(this->rotationX - rotationX);
        float yDist = fabs(this->rotationY - rotationY);
               
        float maxDist = 0.0;
        maxDist = max(maxDist, xDist);
        maxDist = max(maxDist, yDist);
            
        maxDist = 1.0 - ofNormalize(maxDist, 0, 360);
               

        float time = 1 + (maxDist * 10);
                
        tweens[0]->setParameters(linear, ofxTween::easeOut, rotationX, this->rotationX,  time, 0);
        tweens[1]->setParameters(linear, ofxTween::easeOut, rotationY, this->rotationY,  time, 0);
       
        return ofVec2f(tweens[0]->update(), tweens[1]->update());
        
        
    }
    
  
    
    float   brt;
    float   goboPct;
    ofVec3f orientation;
    vector<ofxTween* >  tweens;
    ofxEasingLinear linear;
    float   slerpPct;
    
    float rotationX, rotationY;
        
};

#endif /* defined(__NS2013__NSSharpyTarget__) */





