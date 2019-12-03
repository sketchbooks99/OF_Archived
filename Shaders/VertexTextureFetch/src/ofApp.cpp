#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofNoFill();
    isMouseDragged = false;
    velocity = 0;
    
    numParticle = 512 * 512;
    updatePos.load("shader/passthru.vert", "shader/posUpdate.frag");
    updateRender.load("shader/shader.vert", "shader/shader.frag");
    
    textureRes = (int)sqrt((float)numParticle);
    numParticle = textureRes * textureRes;
    
    vector<float> pos(numParticle * 3);
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            int i = y * textureRes + x;
            
            pos[i*3 + 0] = ofRandom(1.0);
            pos[i*3 + 1] = ofRandom(1.0);
            pos[i*3 + 2] = 0.0;
        }
    }
    
    vector<float> vel(numParticle * 3);
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            int i = y * textureRes + x;
            
            vel[i*3 + 0] = 0.0;
            vel[i*3 + 1] = 0.0;
            vel[i*3 + 2] = 0.0;
        }
    }
    
    posPingPong.allocate(textureRes, textureRes, GL_RGB32F);
    posPingPong.src->getTexture().loadData(pos.data(), textureRes, textureRes, GL_RGB);
    posPingPong.dst->getTexture().loadData(pos.data(), textureRes, textureRes, GL_RGB);
    
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            int i = y * textureRes + x;
            mesh.addVertex(ofVec3f(x, y));
            mesh.addTexCoord(ofVec2f(x, y));
            ofFloatColor fc = ofFloatColor(ofMap(i, 0, textureRes * textureRes, 0, 1), 1.0, 1.0, 0.5);
            //mesh.addColor(fc);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    posPingPong.dst->begin();
    ofClear(0, 0, 0);
    
    updatePos.begin();
    updatePos.setUniformTexture("prevPosData", posPingPong.src->getTexture(), 0);
    updatePos.setUniform1f("velocity", velocity);
    updatePos.setUniform2f("mouse", mouseX, mouseY);
    updatePos.setUniform1i("mouseFrag", isMouseDragged);
    
    posPingPong.src->draw(0, 0);
    updatePos.end();
    
    posPingPong.dst->end();
    
    posPingPong.swap();
    
    if(isMouseDragged) {
        velocity = 1.0f;
    } else {
        velocity *= 0.95;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    // cam.begin();
    
    updateRender.begin();
    updateRender.setUniformTexture("posTex", posPingPong.dst->getTexture(), 0);
    updateRender.setUniform2f("screen", ofGetWidth(), ofGetHeight());
    mesh.draw(OF_MESH_POINTS);
    
    updateRender.end();
    // cam.end();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 15,  15);
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
    isMouseDragged = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isMouseDragged = false;
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
