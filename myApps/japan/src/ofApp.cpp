#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("japan.jpg");
    
    xcut = ofGetWidth() / ((150-128)/2);
    ycut = ofGetHeight() / ((46-30)/2);
    
    vboMesh = ofPlanePrimitive(ofGetWidth(), ofGetHeight(), ofGetWidth(), ofGetWidth()).getMesh();
    
    for(int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec2f texCoord = vboMesh.getTexCoord(i);
        texCoord.x *= img.getWidth();
        texCoord.y = (1.0-texCoord.y)*img.getHeight();
        vboMesh.setTexCoord(i, texCoord);
    }
    
    chofu.x = degToFloat(139, 32, 27);
    chofu.y = degToFloat(35, 39, 2);
    
    gui.setup();
    gui.setPosition(10, 10);
    gui.add(pointX.set("X", chofu.x, 128, 150));
    gui.add(pointY.set("Y", chofu.y, 30, 46));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    img.bind();
    
    vboMesh.draw();
    
    img.unbind();
    ofPopMatrix();
    
    ofSetColor(255, 0, 0, 255);

    for(float x = 0; x < ofGetWidth(); x+=xcut) {
        ofDrawLine(x, 0, x, ofGetHeight());
    }

    for(float y = 0; y < ofGetHeight(); y+=ycut) {
        ofDrawLine(0, y, ofGetWidth(), y);
    }
    
    float pX = (pointX - 128)/2 * xcut;
    float pY = (46-pointY)/2 * ycut;
    ofDrawCircle(pX, pY, 10);
    
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

//--------------------------------------------------------------
float ofApp::degToFloat(float deg, float min, float sec) {
    float value;
    float m = (float)min/60;
    float s = (float)sec/60*m;
    value = deg+m+s;
    return value;
}
