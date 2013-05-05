//
//  NSSceneManager.h
//  NS2013
//
//  Created by Martial on 29/03/13.
//
//

#ifndef __NS2013__NSSceneManager__
#define __NS2013__NSSceneManager__

#include "ofMain.h"
#include "NSScene.h"

class NSSceneManager {
    
  
public:
    NSSceneManager();
    void            setup();
    void            update();
    void            draw();
    void            createScene(int width, int height,  NSEditor * editor);
    
    
    ofPtr<NSScene>  getScene(int index);
    int             getNumScenes() { return scenes.size(); };

private:
    
    vector<ofPtr<NSScene> > scenes;

    
    
};

#endif /* defined(__NS2013__NSSceneManager__) */
