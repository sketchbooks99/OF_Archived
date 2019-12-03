#include "ofApp.h"

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    this->world.setup();
    this->world.setGravity(ofVec3f(0.0, 0.0, 0.0));
    
    float size = 30;
    for (float x = -150; x < 150; x += size) {
        for (float y = -150; y < 150; y += size) {
            for (float z = -150; z < 150; z += size) {
                ofxBulletSphere* sphere = new ofxBulletSphere();
                sphere->create(this->world.world, ofVec3f(x, y, z), 1.0, size / 2);
                sphere->setRestitution(1.0);
                sphere->add();
                
                this->spheres.push_back(sphere);
                
                ofColor color;
                color.setHsb(ofRandom(255), 255, 255);
                this->spheres_color.push_back(color);
                this->spheres_location.push_back(ofVec3f(x, y, z));
            }
        }
    }
    
    this->light.setPosition(ofVec3f(0, 0, 512));
    ofEnableLighting();
    this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f diff;
    for (int i = 0; i < this->spheres.size(); i++) {
        diff = this->spheres_location[i] - this->spheres[i]->getPosition();
        diff *= 10;
        this->spheres[i]->applyCentralForce(diff);
    }
    
    handPosition = ofVec3f(mouseX, mouseY, 0);
    
    ofVec3f dif;
    for (int i = 0; i < this->spheres.size(); i++) {
        dif = this->handPosition - this->spheres[i]->getPosition();
        if (dif.length() < 150) {
            dif *= ofMap(dif.length(), 0, 300, 300, 0);
            this->spheres[i]->applyCentralForce(dif);
        }
    }
    
    
    this->world.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    
    float len = 50;
    for (int i = 0; i < this->spheres.size(); i++) {
        ofSetColor(this->spheres_color[i]);
        this->spheres[i]->draw();
    }
    
    this->cam.end();
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
