#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    kinect.setRegistration(true);
    kinect.open();
    if(!kinect.isConnected()) {
        ofSystemAlertDialog("Serial Error");
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    kinect.draw(0, 0, ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case ' ':
            kinect.init();
            kinect.open();
            if(!kinect.isConnected()) {
                ofSystemAlertDialog("Serial Error");
            }
            break;
    }
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
