#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofBackground(0);
    ofSetCircleResolution(32);
    img.load("earth.jpg");
    
    light.enable();
    light.setPosition(-100, 0, 150);
    sphere = ofSpherePrimitive(100, 100);
    mesh = sphere.getMesh();
    
    for(int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= img.getWidth();
        texCoord.y = (1.0 - texCoord.y) * img.getHeight();
        mesh.setTexCoord(i, texCoord);
    }
    
    gui.setup();
    gui.setPosition(0, 10);
    gui.add(rotate.set("rightPos", 0, -180, 180));
}

//--------------------------------------------------------------
void ofApp::update(){
    time += 0.01;
    float x = sin(ofDegToRad(rotate)) * 300;
    float z = cos(ofDegToRad(rotate)) * 300;
    light.setPosition(x, 0, z);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(255), ofColor(128));
    
    ofEnableDepthTest();
    
    cam.begin();
    
    ofPushMatrix();
    
//    ofNoFill();
//    for(int i = 0; i < 10; i++) {
//        ofDrawCircle(0, 0, 0, i*100);
//    }
//
//    ofFill();
//    for(int i = 0; i < 10; i++) {
//        ofDrawSphere(sin(time) * i * 100, cos(time) * i * 100, 0, 10);
//    }
    
    img.bind();
    
    mesh.draw();
    
    img.unbind();
    
    light.draw();
    
    ofPopMatrix();
    
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
