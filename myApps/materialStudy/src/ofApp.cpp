#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    icoSphere.setRadius(300.0);
    
    ofSetSphereResolution(64);
    
    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    
    icoMesh = icoSphere.getMesh();
    
    for(int i = 0; i < icoMesh.getVertices().size(); i++) {
        icoMesh.addColor(ofFloatColor(0.8, 0.8, 0.8));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    
//    cam.setPosition(1000*sin(time), 0, 1000*cos(time));
//    cam.lookAt(ofVec3f(0, 0, 0));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.setGlobalPosition({0, 0, cam.getImagePlaneDistance(ofGetCurrentViewport()) });
    cam.begin();
    
    ofEnableDepthTest();
    
    ofFill();
    
    ofPushMatrix();
    
    ofRotateXRad(time);
    ofRotateYRad(time);
    ofRotateZRad(time);
    
    ofVec3f rotate = ofVec3f(time*10.0, time*7.0, time*4.0);
    
    ofVec3f light1 = ofVec3f(10.0, 0.0, 0.0);
    float r, g, b;
    r = 100.0f / 255.0f;
    g = 136.0f / 255.0f;
    b = 190.0f / 255.0f;
    
    
    shader.begin();
    shader.setUniform1f("time", time);
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    shader.setUniform3f("light1", light1);
    shader.setUniform3f("rotate", rotate);
    shader.setUniform3f("lightColor", r, g, b);
    
    icoMesh.draw();
    shader.end();
    
    ofPopMatrix();
    
    
    cam.end();
    
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
