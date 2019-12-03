#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofEnableAlphaBlending();
    ofEnableDepthTest();
    ofSetFrameRate(60);
    ofBackground(255);
    
    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    shader.setGeometryInputType(GL_TRIANGLES);
    shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
    shader.setGeometryOutputCount(6);
    
    vboMesh = ofSpherePrimitive(300, 32).getMesh();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    
    ofRotateXDeg(ofGetElapsedTimef() * 10.0);
    ofRotateYDeg(ofGetElapsedTimef() * 7.0);
    ofRotateZDeg(ofGetElapsedTimef() * 14.0);
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    vboMesh.draw();
    vboMesh.drawWireframe();
    
    shader.end();
    
    cam.end();
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
