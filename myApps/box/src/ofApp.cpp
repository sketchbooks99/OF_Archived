#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    ofBackground(0);
    
    shader.setGeometryInputType(GL_TRIANGLES);
    shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
    shader.setGeometryOutputCount(9);
    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    
    vboMesh = ofSpherePrimitive(300, 8).getMesh();
    
    planeMesh = ofPlanePrimitive(700, 700, 70, 70).getMesh();
    for(int i = 0; i < planeMesh.getVertices().size(); i++) {
        planeMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 0.8));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofRotateXDeg(ofGetElapsedTimef()*10.0);
    ofRotateYDeg(ofGetElapsedTimef()*12.0);
    ofRotateZDeg(ofGetElapsedTimef()*7.0);
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    vboMesh.draw();
    
    shader.end();
    
//    planeMesh.draw();
    
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
