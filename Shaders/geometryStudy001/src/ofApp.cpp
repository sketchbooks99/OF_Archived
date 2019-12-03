#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    
    vboMesh = ofSpherePrimitive(200, 8).getMesh();
    
    glPointSize(2.0);
    
    for(int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec2f texCoord = vboMesh.getTexCoord(i);
        vboMesh.addColor(ofFloatColor(texCoord.x, texCoord.y, 0.8, 0.8));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.setPosition(0, 0, abs(sin(ofGetElapsedTimef()*0.1))*500.0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    cam.begin();
    
    ofRotateXDeg(ofGetElapsedTimef()*10.0);
    ofRotateYDeg(ofGetElapsedTimef()*13.0);
    ofRotateZDeg(ofGetElapsedTimef()*5.0);
    
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    vboMesh.draw();
    
    shader.end();
    
    cam.end();
    
    ofDisableDepthTest();
    
    cout << cam.getPosition() << endl;
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
