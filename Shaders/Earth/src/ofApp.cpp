#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("earth.jpg");
    
    shader.load("shader.frag/shader.vert", "shader.frag/shader.frag");
    
    mesh = ofSpherePrimitive(300, 100).getMesh();
    for(int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= image.getWidth();
        texCoord.y = texCoord.y * image.getHeight();
        mesh.setTexCoord(i, texCoord);
    }
    
    glPointSize(3.0f);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
    
    ofPushMatrix();
    ofRotateXDeg(ofGetElapsedTimef() * 3.0);
    ofRotateYDeg(ofGetElapsedTimef()*4.0);
    ofRotateZDeg(ofGetElapsedTimef()*5.0);
    
    shader.begin();
    
    shader.setUniformTexture("tex", image.getTexture(), 0);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
    
    mesh.draw();
    
    shader.end();
    
    ofPopMatrix();
    
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
