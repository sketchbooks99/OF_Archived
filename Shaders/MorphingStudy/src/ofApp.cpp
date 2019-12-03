#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetFrameRate(60);
    
    // skull mesh;
    skull.loadModel("skull.obj", true);
    skull.setScaleNormalization(false);
    
    skullMesh = skull.getMesh(0);
    
    for(int i = 0; i < skullMesh.getVertices().size(); i++) {
        ofVec3f vertex = skullMesh.getVertex(i);
        vertex *= 50.0;
        skullMesh.setVertex(i, vertex);
    }
    
    
    // human mesh
    human.loadModel("human.obj", true);
    human.setScaleNormalization(false);
    humanMesh = human.getMesh(0);
    for(int i = 0; i < humanMesh.getVertices().size(); i++) {
        ofVec3f vertex = humanMesh.getVertex(i);
        vertex *= 50;
        humanMesh.setVertex(i, vertex);
    }
    
    gui.setup();
    gui.setPosition(10, 10);
    gui.add(which.set("which", 0.0, 0.0, 1.0));
    
    skullSize = skullMesh.getVertices().size();
    humanSize = humanMesh.getVertices().size();
    if(skullSize > humanSize) {
        maxSize = skullSize;
        halfMesh = skullMesh;
    } else {
        maxSize = humanSize;
        halfMesh = humanMesh;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i < halfMesh.getVertices().size(); i++) {
        ofVec3f skullPoint, humanPoint;
        if(i < skullSize) {
            skullPoint = skullMesh.getVertex(i);
        } else {
            skullPoint = humanMesh.getVertex(i);
        }
        
        if(i < humanSize) {
            humanPoint = humanMesh.getVertex(i);
        } else {
            humanPoint = skullMesh.getVertex(i);
        }
        skullPoint = skullMesh.getVertex(i);
        humanPoint = humanMesh.getVertex(i);
        ofVec3f morphPoint = skullPoint*(1.0 - which) + humanPoint*which;
        halfMesh.setVertex(i, morphPoint);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    cam.begin();
    
    ofSetColor(255, 255, 255);
    halfMesh.drawWireframe();
    
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
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
