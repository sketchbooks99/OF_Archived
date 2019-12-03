#include "ofApp.h"
#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------
void ofApp::setup(){
//    ofDisableArbTex();
    ofBackground(255);
    ofSetVerticalSync(true);
    shader.load("shader/cubeMap.vert", "shader/cubeMap.frag");
    ofEnableAlphaBlending();

    string imgName[] = {
        "image/cube_PX.jpg",
        "image/cube_NX.jpg",
        "image/cube_PY.jpg",
        "image/cube_NY.jpg",
        "image/cube_PZ.jpg",
        "image/cube_NZ.jpg"
    };

    vboMesh = ofSpherePrimitive(100, 32).getMesh();

    tex.allocate(256, 256, GL_RGBA);

    cubeTexture = loadCubeMap(imgName);
    createMesh();
    cam.setGlobalPosition(0,0,400.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    float camRadius = 500.0;
//    cam.setPosition(camRadius * sin(ofGetElapsedTimef()),0.0,camRadius*cos(ofGetElapsedTimef()));
//    cam.lookAt(ofVec3f(0, 0, 0));
    mousePos = ofVec3f((float)mouseX - ofGetWidth()/2, -(float)mouseY + ofGetHeight()/2, -1.0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_FRONT);
//    glDepthMask(GL_FALSE);

    cam.begin();

    // model Matrix
    ofMatrix4x4 modelMatrix;
    modelMatrix.translate(0, 0, 0);
    modelMatrix.rotate(ofGetElapsedTimef()*10.0,0.0,2.0,0.0);

    // view Matrix
    ofMatrix4x4 viewMatrix;
    viewMatrix = ofGetCurrentViewMatrix();

    // projection Matrix
    ofMatrix4x4 projectionMatrix;
    projectionMatrix = cam.getProjectionMatrix();

    // model view projection Matrix
    ofMatrix4x4 mvpMatrix;
    mvpMatrix = modelMatrix * viewMatrix * projectionMatrix;


//    glEnable(GL_TEXTURE_CUBE_MAP);
//    glBindTexture(GL_TEXTURE_CUBE_MAP, cubeTexture);

    shader.begin();

    shader.setUniform3f("eyePosition", cam.getPosition());
    shader.setUniform1i("cubeTexture", 0);
    shader.setUniformMatrix4f("modelMatrix", modelMatrix);
    shader.setUniformMatrix4f("modelViewProjectionMatrix", mvpMatrix);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform3f("mousePos", mousePos);

    vboMesh.draw();
    
    shader.end();

//    drawCube(256);
//    ofSetColor(0);
    for(int i=0; i<6; i++) {
        img[i].bind();
        boxFaces[i].draw(OF_MESH_FILL);
        img[i].unbind();
    }
    

//    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
//    glDisable( GL_TEXTURE_CUBE_MAP );

    cam.end();

//    glDepthMask(GL_TRUE);

    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//--------------------------------------------------------------
unsigned int ofApp::loadCubeMap(string name[]) {
    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
    ofImage img[6];
    for(int i=0; i<6; i++) {
        img[i].load(name[i]);
        this->img[i] = img[i];
    }

    unsigned char *pixels;
    for(int i=0; i<6; i++){
        pixels = img[i].getPixels().getData();
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,GL_RGB,img[i].getWidth(),img[i].getHeight(),0,GL_RGB,GL_UNSIGNED_BYTE,pixels);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    return textureID;
}

//--------------------------------------------------------------
void ofApp::drawCube(int w) {
//    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofSetColor(0);

    this->img[0].bind();
    ofBeginShape();
    ofVertex(w, w, w);
    ofVertex(w, -w, w);
    ofVertex(w, w, w);
    ofVertex(w, -w, w);
    ofEndShape();
    this->img[0].unbind();

    this->img[1].bind();
    ofBeginShape();
    ofVertex(-w, w, -w);
    ofVertex(-w, -w, -w);
    ofVertex(-w, -w, w);
    ofVertex(-w, w, w);
    ofEndShape();
    this->img[1].unbind();

    this->img[2].bind();
    ofBeginShape();
    ofVertex(-w, w, -w);
    ofVertex(-w, w, w);
    ofVertex(w, w, w);
    ofVertex(w, w, -w);
    ofEndShape();
    this->img[2].unbind();

    this->img[3].bind();
    ofBeginShape();
    ofVertex(-w, -w, w);
    ofVertex(-w, -w, -w);
    ofVertex(w, -w, -w);
    ofVertex(w, -w, w);
    ofEndShape();
    this->img[3].unbind();

    this->img[4].bind();
    ofBeginShape();
    ofVertex(-w, w, w);
    ofVertex(-w, -w, w);
    ofVertex(w, -w, w);
    ofVertex(w, w, w);
    ofEndShape();
    this->img[4].unbind();

    this->img[5].bind();
    ofBeginShape();
    ofVertex(w, w, -w);
    ofVertex(w, -w, -w);
    ofVertex(-w, -w, -w);
    ofVertex(-w, w, -w);
    ofEndShape();
    this->img[5].unbind();
}

//--------------------------------------------------------------
void ofApp::createMesh() {
    // right Face
    int w = this->width*2;
    boxFaces[0].addVertex(ofVec3f(w,-w,w));
    boxFaces[0].addTexCoord(ofVec2f(0,width));
    boxFaces[0].addVertex(ofVec3f(w,-w,-w));
    boxFaces[0].addTexCoord(ofVec2f(width,width));
    boxFaces[0].addVertex(ofVec3f(w,w,-w));
    boxFaces[0].addTexCoord(ofVec2f(width,0));
    boxFaces[0].addVertex(ofVec3f(w,w,w));
    boxFaces[0].addTexCoord(ofVec2f(0,0));

    // left Face
    boxFaces[1].addVertex(ofVec3f(-w,-w,w));
    boxFaces[1].addTexCoord(ofVec2f(width,width));
    boxFaces[1].addVertex(ofVec3f(-w,w,w));
    boxFaces[1].addTexCoord(ofVec2f(width,0));
    boxFaces[1].addVertex(ofVec3f(-w,w,-w));
    boxFaces[1].addTexCoord(ofVec2f(0,0));
    boxFaces[1].addVertex(ofVec3f(-w,-w,-w));
    boxFaces[1].addTexCoord(ofVec2f(0,width));

    // top Face
    boxFaces[2].addVertex(ofVec3f(w,w,w));
    boxFaces[2].addTexCoord(ofVec2f(width,width));
    boxFaces[2].addVertex(ofVec3f(w,w,-w));
    boxFaces[2].addTexCoord(ofVec2f(width,0));
    boxFaces[2].addVertex(ofVec3f(-w,w,-w));
    boxFaces[2].addTexCoord(ofVec2f(0,0));
    boxFaces[2].addVertex(ofVec3f(-w,w,w));
    boxFaces[2].addTexCoord(ofVec2f(0,width));

    // bottom Face
    boxFaces[3].addVertex(ofVec3f(-w,-w,w));
    boxFaces[3].addTexCoord(ofVec2f(0,0));
    boxFaces[3].addVertex(ofVec3f(-w,-w,-w));
    boxFaces[3].addTexCoord(ofVec2f(0,width));
    boxFaces[3].addVertex(ofVec3f(w,-w,-w));
    boxFaces[3].addTexCoord(ofVec2f(width,width));
    boxFaces[3].addVertex(ofVec3f(w,-w,w));
    boxFaces[3].addTexCoord(ofVec2f(width,0));

    // front Face
    boxFaces[4].addVertex(ofVec3f(w,w,w));
    boxFaces[4].addTexCoord(ofVec2f(width,0));
    boxFaces[4].addVertex(ofVec3f(-w,w,w));
    boxFaces[4].addTexCoord(ofVec2f(0,0));
    boxFaces[4].addVertex(ofVec3f(-w,-w,w));
    boxFaces[4].addTexCoord(ofVec2f(0,width));
    boxFaces[4].addVertex(ofVec3f(w,-w,w));
    boxFaces[4].addTexCoord(ofVec2f(width,width));

    // backFace
    boxFaces[5].addVertex(ofVec3f(-w,-w,-w));
    boxFaces[5].addTexCoord(ofVec2f(width,width));
    boxFaces[5].addVertex(ofVec3f(-w,w,-w));
    boxFaces[5].addTexCoord(ofVec2f(width,0));
    boxFaces[5].addVertex(ofVec3f(w,w,-w));
    boxFaces[5].addTexCoord(ofVec2f(0,0));
    boxFaces[5].addVertex(ofVec3f(w,-w,-w));
    boxFaces[5].addTexCoord(ofVec2f(0,width));

    for(int i=0; i<6; i++) {
        boxFaces[i].setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    }
}
