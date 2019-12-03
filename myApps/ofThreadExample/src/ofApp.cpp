#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    loading = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if(loading == true && !imgLoader.isThreadRunning()) {
        img.getPixelsRef() = imgLoader.image;
        img.update();
        loading = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(img.isAllocated()) {
        img.draw(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!loading) {
        imgLoader.setup("perfume.jpg");
        loading = true;
        imgLoader.startThread();
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
