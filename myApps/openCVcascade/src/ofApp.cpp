#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    vidGrabber.initGrabber(320, 240);
    
    ofSetFrameRate(60);
    
    colorImg.allocate(320, 240);
    grayImg.allocate(320, 240);
    
    finder.setup("haarcascade_righteye_2splits.xml");
    finder.findHaarObjects(grayImg);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    colorImg.setFromPixels(vidGrabber.getPixels());
    grayImg = colorImg;
    
    for(int i = 0; i < circles.size(); i++) {
        circles[i].update();
    }
    
    
    
    finder.findHaarObjects(grayImg);
    
    if(circles.size() > 500) {
        for(int i = 0; i < 10; i++) {
            circles.erase(circles.begin());
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    colorImg.draw(0, 0, 640, 480);
    
    if(finder.blobs.size() > 0) {
        for(int i = 0; i < finder.blobs.size(); i++) {
            ofRectangle b = finder.blobs[i].boundingRect;
            eyePos = ofVec2f(b.x * 2 + b.width / 2, b.y * 2 + b.height / 2);
            ofPushMatrix();
            ofScale(2, 2);
            finder.draw(0, 0);
            ofPopMatrix();
        }
    } else {
        for(int i = 0; i < 10; i++) {
            Circle c;
            c.init(eyePos.x, eyePos.y);
            circles.push_back(c);
        }
    }
    
    for(int i = 0; i < circles.size(); i++) {
        circles[i].draw();
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 650, 10);
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
