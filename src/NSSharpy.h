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

class NSSharpyTarget;
class NSSharpy : public ofNode {
    
    
public:
    
    NSSharpy();
    void    setup();
    void    update();
    void    draw();

    
    void    transToTargetOrientation();
    void    setTargetOrientation(ofVec3f orientation);
    
    void    setBrightness(float brighntessPct);
    float   getBrightness();
    void    setGobo(float pct);
    float   getGobo();
    
    void    setID(int id);
    int     getID() {return this->id;}
    
    ofVec3f   getEulerDistance();
    
    void    reset();
    
    /* */
    void    sendToDmx();
    
    NSSharpyTarget *    target;
    
    
private:
    
    int                 id;
    float               maxRadius;
    float               brightness;
    float               goboPct;
    
    ofMesh              cylinder;
    
    
    
    
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
        
        for(int i=0; i<5; i++ ) {
            ofxTween  * tween = new ofxTween();
            tween->setParameters(linear, ofxTween::easeOut, 0, 0, 1, 0);
            tween->start();
            tweens.push_back(tween);
            
        }
        
    }
    
    void  update() {
        for (int i = 0; i<4; i++)
            tweens[i]->update();
    }
    
    ofVec4f  setTweenedOrientation (ofQuaternion & current) {
        
        ofVec4f         currentQuatVec  = current.asVec4();
        
        ofQuaternion    targetQuat      = this->getOrientationQuat();
        ofVec4f         targetQuatVec   = targetQuat.asVec4();
        
        float xDist = fabs(targetQuatVec.x - currentQuatVec.x);
        float yDist = fabs(targetQuatVec.y - currentQuatVec.y);
        float zDist = fabs(targetQuatVec.z - currentQuatVec.z);
        float wDist = fabs(targetQuatVec.w - currentQuatVec.w);
        
        // update with the largest distance
        
        
        float maxDist = 0.0;
        maxDist = max(maxDist, xDist);
        maxDist = max(maxDist, yDist);
        maxDist = max(maxDist, zDist);
        maxDist = max(maxDist, wDist);
         
         
        
        // or min
        /*
        float maxDist = 99999999.0;
        maxDist = min(maxDist, xDist);
        maxDist = min(maxDist, yDist);
        maxDist = min(maxDist, zDist);
        maxDist = min(maxDist, wDist);
         
         */
        
        
        // try to get rollspeed
        
        float time = 120;
                
        tweens[0]->setParameters(linear, ofxTween::easeOut, currentQuatVec.x, targetQuatVec.x, maxDist * time, 0);
        tweens[1]->setParameters(linear, ofxTween::easeOut, currentQuatVec.y, targetQuatVec.y, maxDist * time, 0);
        tweens[2]->setParameters(linear, ofxTween::easeOut, currentQuatVec.z, targetQuatVec.z, maxDist * time, 0);
        tweens[3]->setParameters(linear, ofxTween::easeOut, currentQuatVec.w, targetQuatVec.w, maxDist * time, 0);
 
        
        //tweens[4]->setParameters(linear, ofxTween::easeOut, 0, 1, maxDist * 100, 0);
        
       // ofQuaternion q;
        //q.slerp(tweens[4]->update(), current, this->getOrientationQuat());
        
        //return q.asVec4();
        
        return ofVec4f(tweens[0]->update(), tweens[1]->update(), tweens[2]->update(), tweens[3]->update());
        
        
    }
    
  
    
    float   brt;
    float   goboPct;
    ofVec3f orientation;
    vector<ofxTween* >  tweens;
    ofxEasingLinear linear;
    float   slerpPct;
        
};

#endif /* defined(__NS2013__NSSharpyTarget__) */