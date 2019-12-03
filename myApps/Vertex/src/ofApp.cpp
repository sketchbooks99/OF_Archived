#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    speed = ofVec2f(10, 10);
    point = ofVec2f(0, 0);
//    centerPoint = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    
    center_x = ofGetWidth() / 2;
    center_y = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
//    speed = (centerPoint - point) * 0.03;
//    point = point + speed;
    
    speed_x = (center_x - point_x) * 0.03;
    speed_y = (center_y - point_y) * 0.03;
    
    point_x = point_x + speed_x;
    point_y = point_y + speed_y;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::fromHsb(ofMap((center_x - point_x), -ofGetWidth() / 2, ofGetWidth() / 2, 0, 255), 255, 255));
//    ofDrawCircle(point.x, point.y, 10);
    ofDrawCircle(point_x, point_y, 10);
    
    
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
    point = ofVec2f(x, y);
    point_x = x;
    point_y = y;
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
