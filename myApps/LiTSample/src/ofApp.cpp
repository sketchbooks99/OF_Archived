#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    move_x = 0;
    move_y = 0;
    
    speed_x = 10;
    speed_y = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
    move_x = move_x + speed_x;
    move_y = move_y + speed_y;
    
    if(move_x < 0) {
        speed_x = speed_x * -1;
    }
    if(move_x > ofGetWidth()) {
        speed_x = speed_x * -1;
    }
    if(move_y < 0) {
        speed_y = speed_y * -1;
    }
    if(move_y > ofGetHeight() ) {
        speed_y = speed_y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float g_color;
    g_color = ofMap(40, 0, ofGetHeight(), 0, 255);
    ofSetColor(200, g_color, 200);
    ofDrawCircle(10, move_y, 10);
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
