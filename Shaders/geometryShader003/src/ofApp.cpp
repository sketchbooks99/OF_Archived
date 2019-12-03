#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    vidGrabber.initGrabber(640, 480);
    
    vboMesh = ofPlanePrimitive(640, 480, 64, 48).getMesh();
    
    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    shader.setGeometryInputType(GL_TRIANGLES);
    shader.setGeometryOutputCount(3);
    shader.setGeometryOutputType(GL_TRIANGLE_STRIP);
    
    for(int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec2f texCoord = vboMesh.getTexCoord(i);
        texCoord.x *= vidGrabber.getWidth();
        texCoord.y *= vidGrabber.getHeight();
        vboMesh.setTexCoord(i, texCoord);
    }
    
    
    gui.setup();
    gui.setPosition(10, 10);
    gui.add(border.set("border", 0.5, 0.0, 1.0));
    gui.add(strength.set("strength", 200.0, 0, 400.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    cam.begin();
    
    shader.begin();
    shader.setUniformTexture("tex", vidGrabber.getTexture(), 0);
    shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("resolution", vidGrabber.getWidth(), vidGrabber.getWidth());
    shader.setUniform1f("strength", strength);
    shader.setUniform1f("border", border);
    
    vboMesh.draw();
    
    shader.end();
    
    cam.end();
    
    ofSetColor(255);
    
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
