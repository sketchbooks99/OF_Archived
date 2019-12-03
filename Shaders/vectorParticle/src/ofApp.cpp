#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());
    ofBackground(0);
    numParticle = 700 * 700;
    
    updatePos.load("shader/passthru.vert", "shader/posUpdate.frag");
    updateVel.load("shader/passthru.vert", "shader/velUpdate.frag");
    updateRender.load("shader/render.vert", "shader/render.frag");
    finalRender.load("shader/final.vert", "shader/final.frag");
    
    textureRes = (int)sqrt((float)numParticle);
    numParticle = textureRes * textureRes;
    
    vector<float> pos(numParticle * 3);
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            int i = textureRes * y + x;
            
            pos[i*3 + 0] = ofRandom(1.0);
            pos[i*3 + 1] = ofRandom(1.0);
            pos[i*3 + 2] = 0.0;
        }
    }
    
    posPingPong.allocate(textureRes, textureRes, GL_RGB32F);
    posPingPong.src->getTexture().loadData(pos.data(), textureRes, textureRes, GL_RGB);
    posPingPong.dst->getTexture().loadData(pos.data(), textureRes, textureRes, GL_RGB);
    
    vector<float> vel(numParticle * 3);
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            int i = textureRes * y + x;
            
            vel[i*3 + 0] = 0.0;
            vel[i*3 + 1] = 0.0;
            vel[i*3 + 2] = 0.0;
        }
    }
    
    velPingPong.allocate(textureRes, textureRes, GL_RGB32F);
    velPingPong.src->getTexture().loadData(vel.data(), textureRes, textureRes, GL_RGB);
    velPingPong.dst->getTexture().loadData(vel.data(), textureRes, textureRes, GL_RGB);
    
    renderFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB32F);
    renderFbo.begin();
    ofClear(0);
    renderFbo.end();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    for(int x = 0; x < textureRes; x++) {
        for(int y = 0; y < textureRes; y++) {
            mesh.addVertex(ofVec3f(x, y));
            mesh.addTexCoord(ofVec2f(x, y));
        }
    }
    
    gui.setup();
    gui.setPosition(10, 30);
    gui.add(strength.set("strength", 0.001, 0.0001, 0.01));
    gui.add(maxVel.set("maxVel", 0.02, 0.001, 0.1));
    
//    sphere = ofSpherePrimitive(200, 64);
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    attractor = ofVec2f(mouseX, mouseY);
    
    velPingPong.dst->begin();
    ofClear(0);
    updateVel.begin();
    updateVel.setUniformTexture("velData", velPingPong.src->getTexture(), 0);
    updateVel.setUniformTexture("posData", posPingPong.src->getTexture(), 1);
    updateVel.setUniform1f("strength", strength);
    updateVel.setUniform1f("maxVel", maxVel);
    updateVel.setUniform1i("resolution", (int)textureRes);
    updateVel.setUniform2f("screen", ofGetWidth(), ofGetHeight());
    updateVel.setUniform2f("attractor", attractor);
    
    velPingPong.src->draw(0, 0);
    
    updateVel.end();
    velPingPong.dst->end();
    
    velPingPong.swap();
    
    
    posPingPong.dst->begin();
    ofClear(0);
    updatePos.begin();
    updatePos.setUniformTexture("posData", posPingPong.src->getTexture(), 0);
    updatePos.setUniformTexture("velData", velPingPong.src->getTexture(), 1);
    
    posPingPong.src->draw(0, 0);
    
    updatePos.end();
    posPingPong.dst->end();
    
    posPingPong.swap();
    
    
    renderFbo.begin();
    ofClear(0, 0, 0, 0);
    updateRender.begin();
    updateRender.setUniformTexture("posTex", posPingPong.dst->getTexture(), 0);
    updateRender.setUniform2f("screen", ofGetWidth(), ofGetHeight());
    mesh.draw(OF_MESH_POINTS);
    
    updateRender.end();
    
    renderFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    
//    cam.begin();
    
    ofBackground(0);
    
    finalRender.begin();
    finalRender.setUniformTexture("video", vidGrabber.getTexture(), 0);
    finalRender.setUniformTexture("particle", renderFbo.getTexture(), 1);
    vidGrabber.draw(0, 0);

    finalRender.end();
//    vidGrabber.getTexture().bind();
//    sphere.draw();
//    vidGrabber.getTexture().unbind();
    
//    cam.end();
    
    ofDisableDepthTest();
    
    gui.draw();
    ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()), 10, 10);
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
