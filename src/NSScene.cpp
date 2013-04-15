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

NSScene::NSScene () {
    
    bEnableFFSA     = true;
    bEnableBloom    = true;
    bEnableDof      = true;
    bCamMouseInput  = false;
    bDrawGrid       = true;
    bToggleCamera   = false;
    bSndAlpha       = false;
    bSndGobo        = false;
    dofAperture     = 1.0;
    dofFocus        = 0.2;
    
    
}

//--------------------------------------------------------------


void NSScene::setup (int width, int height) {
    
    // init sharpies
    
    numSharpies = 32;
    
    for (int i=0; i<numSharpies; i++) {
        
        ofPtr<NSSharpy> sharpyRef(new NSSharpy());
        
        sharpyRef->setParent(*this);
        sharpyRef->setup();
        sharpyRef->setID(i);
        
        sharpies.push_back(sharpyRef);
      
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
    post.createPass<DofPass>()->setEnabled(bEnableDof);
    
    

    dof = post.getPasses()[2];
    
    
    cam.setOrientation(ofVec3f(90, 90, 0));
    cam.setDistance(2000.f);
    
    dofAperture = 0.92;
    dofFocus = 0.4;
    
    //load the squirrel model - the 3ds and the texture file need to be in the same folder
    flash.loadModel("model/model.3ds", 0.5);
    
    //you can create as many rotations as you want
    //choose which axis you want it to effect
    //you can update these rotations later on
    
    //flash.setRotation(0, 90, 0, 0, 1);
    flash.setScale(0.9, 0.9, 0.9);
    flash.setPosition(0, 0, -215);
    
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
    post.getPasses()[2]->setEnabled(bEnableDof);
    
    shared_ptr<DofPass> pass = static_pointer_cast<DofPass>(dof);
    pass->setFocus(dofAperture);
    pass->setAperture(dofFocus);
    pass->setMaxBlur(.3);
    
    resetTransform();
    
    ofVec3f screenCenter;
    screenCenter.set(ofGetWidth() * .5, ofGetHeight() * .5 , 0.f);
    setPosition(screenCenter);
    
    
    ofVec3f pos;
    float xDistance = 7559.055119f * 2.0 / 100.0f;
    float yDistance = 32125.984254f * 2.0 / 100.0f;
    
    sharpiesCenter.set(ofVec3f( ( (float)numSharpies *.25  * xDistance) - xDistance*.5, yDistance * .5));
    
    ofxEQ * eq = Globals::instance()->eq;
    
     for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->setPosition(-getPosition() + pos - sharpiesCenter);
        
        
        int index = ( i < 16 ) ? i : i - 16;
        float * eqChannel = ( i < 16 ) ?  eq->left :  eq->right;
        int indexMapped = ofMap(index, 0, 16, 0, 512);
        
        if(bSndAlpha)
            sharpyRef->target->brt *= sharpyRef->target->brt * eqChannel[indexMapped];

        if(bSndGobo)
            sharpyRef->target->goboPct *= sharpyRef->target->goboPct * eqChannel[indexMapped];
        
        sharpyRef->update();
        pos.x += xDistance;
        if( i == (floor)((float)numSharpies *.5) -1) {
            pos.x = 0.f;
            pos.y += yDistance;
        }

    }
    
}


//--------------------------------------------------------------

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
    
    // begin scene to post process
    
    post.begin(cam);
    
    ofPushMatrix();
    
    //ofScale(ofGetMouseY() /1000, ofGetMouseY() /1000);
    
    glEnable(GL_CULL_FACE);

    ofSetColor(255);
    //ofDrawGrid(1000, 2, true);
    
    
    //float width = sharpiesCenter.x * 2.f;
    //float height = 300;
    
    ofDisableAlphaBlending();
    
    light.setAmbientColor(0);
    light.setDiffuseColor(.3);
    
    lightUp.setAmbientColor(ofFloatColor(.01));
    lightUp.setDiffuseColor(ofFloatColor(.1));

    
    
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_QUADS);

    // sol
    //float zPos = -300.0;
    float zPos = -20787.401576 / 100.0f;
    ofVec3f floorSize;
    floorSize.x = 158740.157492 / 100.0f;
    floorSize.y = 60472.440949 / 100.0f;
    
    
    float floorScale = 10.0;
    
    glColor3f(0,0,0);               glVertex3f(-floorSize.x* floorScale, -floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(floorSize.x* floorScale, -floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(floorSize.x* floorScale, floorSize.y* floorScale, zPos-2);
    glColor3f(0,0,0);               glVertex3f(-floorSize.x* floorScale, floorSize.y* floorScale, zPos-2);
    
    floorScale = 1.0;
    
    
    float floorColor = 0.6;
    glColor3f(floorColor,floorColor,floorColor);    glVertex3f(-floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);     glVertex3f(floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);        glVertex3f(floorSize.x* floorScale, floorSize.y* floorScale, zPos);
    glColor3f(floorColor,floorColor,floorColor);             glVertex3f(-floorSize.x* floorScale, floorSize.y* floorScale, zPos);
    
    /*
    glColor3f(0.95, 0.95, 0.95);    glVertex3f(-floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(.85, 0.85, 0.85);     glVertex3f(floorSize.x* floorScale, -floorSize.y* floorScale, zPos);
    glColor3f(.9, 0.9, 0.9);        glVertex3f(floorSize.x* floorScale, floorSize.y* floorScale, zPos);
    glColor3f(1, 1, 1);             glVertex3f(-floorSize.x* floorScale, floorSize.y* floorScale, zPos);
     
     */
    // right
    
    
   
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
    
    
    //3779,5275595 / 100 = 1 Meter
    
    
    
    ofPushMatrix();
    
    float w = 3779.5275595 * 4 / 100;
    float h = 60472.440949 / 100.0f;
    float depth = 75;
    
    ofTranslate(-floorSize.x + (w*.5), 0, zPos + (depth*.5));
    ofMesh b =box(w, floorSize.y*2, depth, 16, 16, 16);
    ofSetColor(0.6 * 255);
    b.draw();
    ofPopMatrix();
    
    //ofCylinder();
    ofPopMatrix();
    
    
    /*
    flash.draw();
     
     */
    
    // walls
    //int groundWidth = 4000, groundHeight = 1000;
    
    //ofRect(0, 0, groundWidth, groundHeight);
    
    light.setAmbientColor(1.0);
    lightUp.setAmbientColor(0.001);
    
    light.draw();
    lightUp.draw();

   
    
    ofSetColor(255);
    ofSphere (light.getPosition(), 10);
    
   
    
    //ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetColor(255);
    ofEnableAlphaBlending();
    glDisable(GL_CULL_FACE);
    
    
    if(bDrawGrid) {
        ofPushMatrix();
        ofTranslate(0, 0, zPos +1);
        ofDrawGrid(3779.5275595 / 100 * 256, 128, false, false, false, true);
        ofPopMatrix();
    }

    
    for (int i=0; i<sharpies.size(); i++) {
        
        ofPtr<NSSharpy> sharpyRef = sharpies[i];
        sharpyRef->draw();
        
    }
    
  
    ofSetColor(255);

    
    ofDisableAlphaBlending();
    
    ofPopMatrix();
    
    //ofDisableBlendMode();
    //cam.end();
    post.end(false);
    //restoreTransformGL();
    
    
    glDisable(GL_DEPTH_TEST);
    glPopAttrib();
    
    //post.draw();
   
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

void NSScene::sharpyLookAt(int sharpyIndex, ofVec3f pos) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];
    
    ofNode tmpNode;
    tmpNode.setParent(*this);
    tmpNode.setPosition(sharpyRef->getPosition());
    tmpNode.lookAt(pos);
    
    sharpyRef->target->setOrientation(tmpNode.getOrientationQuat());
    
    
    
    //sharpyRef->lookAt(pos);
    
    
    
    
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
    
    
    
    ofQuaternion pan, tilt;
    pan.makeRotate  ( angles.x, 0, 0, 1);
    tilt.makeRotate ( angles.y, 0, 1, 0);

    sharpyRef->target->setOrientation(pan);
    sharpyRef->childNode.setOrientation(tilt);
    
}

void NSScene::setOrientation(int sharpyIndex, ofVec3f eulerAngles) {
    
    sharpyIndex = ofClamp(sharpyIndex, 0, sharpies.size()-1);
    ofPtr<NSSharpy> sharpyRef = sharpies[sharpyIndex];

    
    
    
    sharpyRef->target->setOrientation(eulerAngles);
    
    
    /*
    
    ofQuaternion pan, tilt;
    pan.makeRotate( eulerAngles.x, 0, 0, 1);
    tilt.makeRotate( eulerAngles.y, 0, 1, 0);
    
    
    
    sharpyRef->target->setOrientation(pan * tilt);
    sharpyRef->childNode.setOrientation(tilt);
    
    //sharpyRef->target->setOrientation(pan * tilt);
     

    ofQuaternion pan, tilt;
    pan.makeRotate  ( eulerAngles.x, 0, 0, 1);
    tilt.makeRotate ( eulerAngles.y, 0, 1, 0);
    
    sharpyRef->tmpQuaternion.setOrientation(pan * tilt);
    
    sharpyRef->target->setOrientation(eulerAngles);
     
     */

    
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



