//
//  NSScene
//  NS2013
//
//  Created by Martial on 25/03/13.
//
//

#include "NSScene.h"
#include "Globals.h"
#include "ofxEQ.h"

bool MyDataSortPredicate(const pair<int, float>& lhs, const pair<int, float>& rhs)
{
    return lhs.second < rhs.second;
}

NSScene::NSScene () {
    
    bEnableFFSA     = true;
    bEnableBloom    = true;
    bEnableDof      = true;
    bCamMouseInput  = false;
    bDrawGrid       = true;
    bToggleCamera   = false;
    bSndAlpha       = false;
    bSndGobo        = false;
    bdrawArrows     = false;
    bdrawLookAt     = false;
    bdrawModels     = true;
    bDrawIds        = false;
    
    bmapAnims       = true;
    
    bGlobalFrost    = false;
    
    bEqualizerMode  = false;
    
    
    dofAperture     = 1.0;
    dofFocus        = 0.2;
    
    globalDecay     = 1.0;
    globalGobo      = 1.0;
    globalStrob     = 0.0;
    globalFullStrob = 0.0;
    
    
    depth           = -22677.165354331 / 100.0f;;
    width           = 158740.157492 / 100.0f;
    height          = 60472.440949 / 100.0f;
    
    
    floorSize.x = width;
    floorSize.y = height;

    
    
}

//--------------------------------------------------------------


void NSScene::setup (int width, int height, NSEditor * editor) {
    
    // init sharpies
    
    this->editor = editor;
    
    numSharpies = 32;
    
    for (int i=0; i<numSharpies; i++) {
        
        ofPtr<NSSharpy> sharpyRef(new NSSharpy());
        
        sharpyRef->setParent(*this);
        sharpyRef->setup();
        sharpyRef->setID(i);
        
        sharpies.push_back(sharpyRef);
      
    }
    
    // map horizontal sharpies index
    
    
    for (int j = 0; j < 16; j++) {
        
        for (int i = 0; i < 2; i++) {
            int index = i * 16 + j;
            horizontalSharpiesIndex.push_back(index);
        }
        
    }
    
    
    light.setPosition(sharpiesCenter);
    light.setAmbientColor(255);
    
    ofVec3f lightUpPos = sharpiesCenter;
    lightUpPos.z =  0;
    lightUp.setPosition(lightUpPos);
    lightUp.setAmbientColor(255);
        
    post.init(width , height);
    post.createPass<FxaaPass>()->setEnabled(bEnableFFSA);
    post.createPass<BloomPass>()->setEnabled(bEnableBloom);
    //post.createPass<DofPass>()->setEnabled(bEnableDof);
    
    

    //dof = post.getPasses()[2];
    
    
    cam.setOrientation(ofVec3f(90, 90, 0));
    cam.setDistance(2000.f);
    
    dofAperture = 0.92;
    dofFocus = 0.4;
    
    sharpyModel.setup();
    
    // creat box
   
    
}

//--------------------------------------------------------------

void NSScene::update () {
    
   
    
    // lock cam position
    ofVec3f position = cam.getPosition();
    
    if ( position.z < -180.0) {
        position.z = -180.0;
        cam.setPosition(position);
        
    }
    
    
    
    /* update shaders */
    
    post.getPasses()[0]->setEnabled(bEnableFFSA);
    post.getPasses()[1]->setEnabled(bEnableBloom);
    
    /*
    post.getPasses()[2]->setEnabled(bEnableDof);
    
    shared_ptr<DofPass> pass = static_pointer_cast<DofPass>(dof);
    pass->setFocus(dofAperture);
    pass->setAperture(dofFocus);
    pass->setMaxBlur(.3);`
     
     */
    
    resetTransform();
    
    
    screenCenter.set(ofGetWidth() * .5, ofGetHeight() * .5 , 0.f);
    setPosition(screenCenter);
    
    
    ofVec3f pos;
    float xDistance = 7559.055119f * 2.0 / 100.0f;
    float yDistance = 32125.984254f * 2.0 / 100.0f;
    
    sharpiesCenter.set(ofVec3f( ( (float)numSharpies *.25  * xDistance) - xDistance*.5, yDistance * .5));
    
    ofxEQ * eq          = Globals::instance()->eq;
    //NSEditor * editor   = Globals::instance()->editor;
    
    vector<int> data    = editor->getActualFrameData();
    
    //printf("size %d", data.size());
    
    
     for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
         
         sharpyRef->setPosition(-getPosition() + pos - sharpiesCenter);
         
         
         sharpyRef->decay   = globalDecay;
         sharpyRef->goboPct = globalGobo;
         sharpyRef->bFrost  = bGlobalFrost;
       
        
        int index = ( i < 16 ) ? i : i - 16;
        float * eqChannel = ( i < 16 ) ?  eq->left :  eq->right;
        int indexMapped = ofMap(index, 0, 16, 0, 512);
         
         
         if(bEqualizerMode) {
             
             //take left at middle
             
             float snd = eq->left[256];
             float pct = snd * 32;
             
             //printf("pct %f\n", pct);
             
             int horizontalIndex = horizontalSharpiesIndex[i];
             ofPtr<NSSharpy> sharpyHorRef = sharpies[horizontalIndex];
                          
             if( pct > i ) {
                 
                 sharpyHorRef->target->brt = 1.0;
                 sharpyHorRef->brightness  = 1.0;
                 
             } else {
                 
                 sharpyHorRef->target->brt = 0.0;
                 sharpyHorRef->brightness  = 0.0;
                 
             }
             
             
             
         } else {
        
                          
         // map to anim
         
        if (bmapAnims) {
             
             if (find(data.begin(), data.end(), i) != data.end()) {
                 sharpyRef->target->brt = 1.0;
                 sharpyRef->brightness = 1.0;
             
             }
             else {
                 sharpyRef->target->brt = 0.0;
             }
         
        } else {
            sharpyRef->target->brt = 1.0;
            
        }
         
         // force lights
         
         if(sharpyRef->forcedBrightness >= 0.0) {
             
             sharpyRef->brightness = sharpyRef->forcedBrightness;
             sharpyRef->target->brt = sharpyRef->forcedBrightness;
                 
         }
         
        // sound
        
        if(bSndAlpha)
            sharpyRef->target->brt *= sharpyRef->target->brt * eqChannel[indexMapped];

        if(bSndGobo)
            sharpyRef->target->goboPct *= sharpyRef->target->goboPct * eqChannel[indexMapped];
         
        // finally global strobz
         
         if(globalStrob > 0.0 ) {
             
             int strobStep  = 1 + (int)(globalStrob * 12);
             //sharpyRef->decay = 0.0;
             if( ofGetFrameNum() % strobStep > (strobStep / 2) ) {
                 sharpyRef->target->brt *= 0.0;
                // sharpyRef->brightness  *= 0.0;
             } else {
                 sharpyRef->target->brt *= 1.0;
                 //sharpyRef->brightness  *= 1.0;
             }
         }
         
             if(globalFullStrob > 0.0 ) {
             
                 int strobStep  = 1 + (int)(globalFullStrob * 12);
             //sharpyRef->decay = 0.0;
                 if( ofGetFrameNum() % strobStep > (strobStep / 2) ) {
                     sharpyRef->target->brt = 0.0;
                     sharpyRef->brightness  = 0.0;
                 } else {
                 sharpyRef->target->brt = 1.0;
                 sharpyRef->brightness  = 1.0;
             }
         }
         
         }
         
         // global alpha
         
         sharpyRef->brightness *= globalAlpha;
         sharpyRef->target->brt *= globalAlpha;
         
                 
        sharpyRef->update();
        pos.x += xDistance;
        if( i == (floor)((float)numSharpies *.5) -1) {
            pos.x = 0.f;
            pos.y += yDistance;
        }

    }
    
}


//--------------------------------------------------------------


void NSScene::drawBox() {
    
    ofPushMatrix();
  
    glEnable(GL_CULL_FACE);
    
    ofSetColor(255);
    
    
    
    light.setAmbientColor(0);
    light.setDiffuseColor(.3);
    
    lightUp.setAmbientColor(ofFloatColor(.01));
    lightUp.setDiffuseColor(ofFloatColor(.1));
    

    
    
    glBegin(GL_QUADS);
    

    float zPos = depth;
    
    float floorScale = 10.0;
    
    glColor3f(0,0,0);               glVertex3f(-floorSize.x* floorScale, -floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(floorSize.x* floorScale, -floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(floorSize.x* floorScale, floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(-floorSize.x* floorScale, floorSize.y* floorScale, zPos-2);
    
    floorScale = 1.0;
    
    
    float floorColor = 0.6;
    glColor3f(floorColor,floorColor,floorColor);    glVertex3f(-floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);    glVertex3f(floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);    glVertex3f(floorSize.x* floorScale, floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);    glVertex3f(-floorSize.x* floorScale, floorSize.y* floorScale, zPos);
    
      
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-floorSize.x, -floorSize.y, 0);
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(floorSize.x, -floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(floorSize.x, -floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(-floorSize.x, -floorSize.y, zPos);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, floorSize.y, 0);
    
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x, -floorSize.y, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(-floorSize.x, floorSize.y, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(-floorSize.x, floorSize.y, 0);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x, -floorSize.y, 0);
    
    glEnd();
    
    ofPushMatrix();
    
    
    // ----------------------------------  scene box
    
    
    float w     = 3779.5275595 * 4 / 100;
    float depth = 75;
    
    if(!sceneBox.hasVertices())
        sceneBox = box(w, floorSize.y*2, depth, 16, 16, 16);;
    
    ofTranslate(-floorSize.x + (w*.5), 0, zPos + (depth*.5));
    ofSetColor(0.6 * 255);
    sceneBox.draw();
    ofPopMatrix();
    

    ofPopMatrix();
    
    ofSetColor(255);
    ofEnableAlphaBlending();
    glDisable(GL_CULL_FACE);
    

}

void NSScene::drawModels() {
    
   
    float zPos  = depth;
    
    light.setAmbientColor(ofFloatColor(.001,.001,.001));
    light.setDiffuseColor(ofFloatColor(.1,.1,.1));
    light.setSpecularColor(ofFloatColor(.001,.001,.001));
    
    ofSetColor(255);

    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255, 255);
    
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->transformGL();
        
        if(bdrawModels)
            sharpyModel.draw(ofVec3f(0,0,0), sharpyRef->rotationX, sharpyRef->rotationY);
        else
            sharpyModel.drawBlocks(ofVec3f(0,0,0), sharpyRef->rotationX, sharpyRef->rotationY);
        
        sharpyRef->restoreTransformGL();
        
    }
    
    
    light.setAmbientColor(1.0);
    lightUp.setAmbientColor(0.001);
    
    

    
    if(bDrawGrid) {
        ofPushMatrix();
        ofTranslate(0, 0, zPos +1);
        ofDrawGrid(3779.5275595 / 100 * 256, 128, false, false, false, true);
        ofPopMatrix();
    }
    
    list< pair<int, float> > depthList;
    
    // put indexed points and z-values into the list
    for(int i=0; i<sharpies.size(); i++) {
        depthList.push_back( make_pair(i, sharpies[i]->getPosition().x) );
    }
    
    // sort the list
    depthList.sort(MyDataSortPredicate);
    
    glAlphaFunc ( GL_GREATER, 0.1 ) ;
    glEnable ( GL_ALPHA_TEST ) ;

    std::list<pair<int, float> >::iterator it;
    for(it = depthList.begin(); it != depthList.end(); it++) {
        
        int i = it->first;
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->draw(bDrawIds);
        
        
        
        if(bdrawLookAt) {
            ofPushMatrix();
            ofTranslate(sharpyRef->lookAtPnt);
            ofSphere(0, 0, 0, 20);
            ofPopMatrix();
            
        }
        
    }
    
    //glDisable( GL_ALPHA_TEST ) ;

    ofSetColor(255);
    
    
    ofPopMatrix();
   
    
}



void NSScene::draw() {
    
    
    
    if(bCamMouseInput) {
        cam.enableMouseInput();
    } else {
        setCameraMode(camMode);
        cam.disableMouseInput();
        
    }
    
    
        
    // copy enable part of gl state
   

    glPushAttrib(GL_ENABLE_BIT);
    light.enable();
    lightUp.disable();
    
    
    post.begin(cam);
    
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_NICEST);

    
    
    drawBox();
    drawModels();
    
    ofDisableAlphaBlending();
    
    glDisable(GL_DEPTH_TEST); 

    post.end(false);
    
      glPopAttrib();
 
    

   
}

void NSScene::toggleCamera() {
    
        camMode++;
        if(camMode>3) camMode = 0;
        bToggleCamera = false;
        this->bCamMouseInput    = false;
    
}

void NSScene::setCameraMode(int camMode) {
    
    
    this->camMode           = camMode;
    
    switch (camMode) {
        case 0:
            
            cam.setGlobalPosition(2000, 0, 30);
            cam.setOrientation(ofVec3f(90, 90, 0));
            //cam.setDistance(2000.f);
            break;
            
        case 1:
            
            cam.setGlobalPosition(1500, 0, -80);
            cam.setOrientation(ofVec3f(90, 90, 0));
            break;
            
        case 2:
            cam.setOrientation(ofVec3f(0, 0, 0));
            cam.setDistance(2000.f);
            break;
            
        case 3:
            cam.setOrientation(ofVec3f(90, 90, 90));
            cam.setDistance(2000.f);
            break;
            
        case 4:
            cam.setPosition(0, 0, -ofGetMouseY());
            cam.setOrientation(ofVec3f(90, 90, 0));
            cam.setDistance(500.0);
            break;
            
        default:
            break;
    }
    
}

/*
 //--------------------------------------------------------------
 */

void NSScene:: setSharpyColor(ofColor color, string name) {
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->color = color;
        sharpyRef->colorName = name;
        
    }
    
}

void NSScene::setSvg(string name) {
    
    vector<ofVec3f> position = svg.getPositions(name);
    
    for (int i=0; i<position.size(); i++) {
        
        ofVec3f pos = position[i];
        sharpyLookAt(pos.z -1, ofVec3f(-width / 2 + pos.y, -height/2 + pos.x, depth));
        
        
    }
     
    
    
}

void NSScene::reset() {
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->forcedBrightness = -1.0;
    }
    
    
}

void NSScene::setSharpyDecay(float decay) {
    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->decay = decay;
    }
    
}

void NSScene::setRotation(int sharpyIndex, ofVec2f angles) {
    
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];

    
    
    sharpyRef->target->rotationX = angles.x;
    sharpyRef->target->rotationY = angles.y;
    
}

void NSScene::sharpyLookAt(int sharpyIndex, ofVec3f pos) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];

    ofVec3f pnt = pos  -getPosition() - sharpyRef->getPosition();;
    
    sharpyRef->lookAtPnt =pos;
    
    float rotx = ofRadToDeg(atan2(pnt.x, pnt.y));
    float roty = ofRadToDeg(atan2(sqrt(pow(pnt.x,2) + pow(pnt.y,2)),pnt.z));
    
      
    sharpyRef->target->rotationX =  180 - rotx;
    sharpyRef->target->rotationY =  180 - roty;
    
    
}

ofVec3f NSScene::getSharpyPos(int sharpyIndex) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    
    return getPosition() + sharpyRef->getPosition();
    
}

void NSScene::setGobo(int sharpyIndex, float pct) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    sharpyRef->setGobo(pct);
    
}

void NSScene::setBrightness(int sharpyIndex, float pct) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    sharpyRef->setBrightness(pct);
    
}

void NSScene::setPanTilt(int sharpyIndex, ofVec2f angles) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    

    sharpyRef->target->orientation.x = angles.x;
    sharpyRef->target->orientation.y = angles.y;
    //sharpyRef->childNode.setOrientation(tilt);
    
}

void NSScene::setOrientation(int sharpyIndex, ofVec3f eulerAngles) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    
    if(eulerAngles.z >= 0 ) eulerAngles.z = -1;

    
    ofVec3f pnt = eulerAngles  - getPosition() - sharpyRef->getPosition();;
    
    sharpyRef->lookAtPnt = pnt;
    
    float rotx = ofRadToDeg(atan2(eulerAngles.x, eulerAngles.y));
    float roty = ofRadToDeg(atan2(sqrt(pow(eulerAngles.x,2) + pow(eulerAngles.y,2)),eulerAngles.z));
    
        
    
    sharpyRef->target->rotationX =  180 - rotx;
    sharpyRef->target->rotationY =  180 - roty;
    
}

void NSScene::setSharpyFinePanTilt(int index, float pan, float tilt) {
    
    ofPtr<NSSharpy> sharpyRef = sharpies[index];
    sharpyRef->setFinePanTilt(pan, tilt);
    
}

void NSScene::onResize(int width, int height) {
    
    post.init(width , height);
    
    
}

// Box Mesh //
//--------------------------------------------------------------
ofMesh NSScene::box( float width, float height, float depth, int resX, int resY, int resZ ) {
    // mesh only available as triangles //
    ofMesh mesh;
    mesh.setMode( OF_PRIMITIVE_TRIANGLES );
    
    // halves //
    float halfW = width * .5f;
    float halfH = height * .5f;
    float halfD = depth * .5f;
    
    ofVec3f vert;
    ofVec2f texcoord;
    ofVec3f normal;
    int vertOffset = 0;
    
    // TRIANGLES //
    
    // Front Face //
    normal.set(0, 0, 1);
    // add the vertexes //
    for(int iy = 0; iy < resY; iy++) {
        for(int ix = 0; ix < resX; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resX-1.f));
            texcoord.y = ((float)iy/((float)resY-1.f));
            
            vert.x = texcoord.x * width - halfW;
            vert.y = texcoord.y * height - halfH;
            vert.z = halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resY-1; y++) {
        for(int x = 0; x < resX-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resX + x + vertOffset);
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
        }
    }
    
    vertOffset = mesh.getNumVertices();
    
    
    // Right Side Face //
    normal.set(1, 0, 0);
    // add the vertexes //
    for(int iy = 0; iy < resY; iy++) {
        for(int ix = 0; ix < resZ; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resZ-1.f));
            texcoord.y = ((float)iy/((float)resY-1.f));
            
            //vert.x = texcoord.x * width - halfW;
            vert.x = halfW;
            vert.y = texcoord.y * height - halfH;
            vert.z = texcoord.x * -depth + halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resY-1; y++) {
        for(int x = 0; x < resZ-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resZ + x + vertOffset);
            mesh.addIndex((y)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x + vertOffset);
        }
    }
    
    vertOffset = mesh.getNumVertices();
    
    // Left Side Face //
    normal.set(-1, 0, 0);
    // add the vertexes //
    for(int iy = 0; iy < resY; iy++) {
        for(int ix = 0; ix < resZ; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resZ-1.f));
            texcoord.y = ((float)iy/((float)resY-1.f));
            
            //vert.x = texcoord.x * width - halfW;
            vert.x = -halfW;
            vert.y = texcoord.y * height - halfH;
            vert.z = texcoord.x * depth - halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resY-1; y++) {
        for(int x = 0; x < resZ-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resZ + x + vertOffset);
            mesh.addIndex((y)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x+1 + vertOffset);
            mesh.addIndex((y+1)*resZ + x + vertOffset);
        }
    }
    
    vertOffset = mesh.getNumVertices();
    
    
    // Back Face //
    normal.set(0, 0, -1);
    // add the vertexes //
    for(int iy = 0; iy < resY; iy++) {
        for(int ix = 0; ix < resX; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resX-1.f));
            texcoord.y = ((float)iy/((float)resY-1.f));
            
            vert.x = texcoord.x * -width + halfW;
            vert.y = texcoord.y * height - halfH;
            vert.z = -halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resY-1; y++) {
        for(int x = 0; x < resX-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resX + x + vertOffset);
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
        }
    }
    
    vertOffset = mesh.getNumVertices();
    
    
    
    // Top Face //
    normal.set(0, -1, 0);
    // add the vertexes //
    for(int iy = 0; iy < resZ; iy++) {
        for(int ix = 0; ix < resX; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resX-1.f));
            texcoord.y = ((float)iy/((float)resZ-1.f));
            
            vert.x = texcoord.x * width - halfW;
            //vert.y = texcoord.y * height - halfH;
            vert.y = -halfH;
            vert.z = texcoord.y * depth - halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resZ-1; y++) {
        for(int x = 0; x < resX-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resX + x + vertOffset);
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
        }
    }
    
    vertOffset = mesh.getNumVertices();
    
    
    // Bottom Face //
    normal.set(0, 1, 0);
    // add the vertexes //
    for(int iy = 0; iy < resZ; iy++) {
        for(int ix = 0; ix < resX; ix++) {
            
            // normalized tex coords //
            texcoord.x = ((float)ix/((float)resX-1.f));
            texcoord.y = ((float)iy/((float)resZ-1.f));
            
            vert.x = texcoord.x * width - halfW;
            //vert.y = texcoord.y * height - halfH;
            vert.y = halfH;
            vert.z = texcoord.y * -depth + halfD;
            
            mesh.addVertex(vert);
            mesh.addTexCoord(texcoord);
            mesh.addNormal(normal);
        }
    }
    
    for(int y = 0; y < resZ-1; y++) {
        for(int x = 0; x < resX-1; x++) {
            // first triangle //
            mesh.addIndex((y)*resX + x + vertOffset);
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
            
            // second triangle //
            mesh.addIndex((y)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x+1 + vertOffset);
            mesh.addIndex((y+1)*resX + x + vertOffset);
        }
    }
    
    
    
    return mesh;
}



