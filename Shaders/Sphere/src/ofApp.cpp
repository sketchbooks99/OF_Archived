#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    
    ofSetSmoothLighting(true);
    
    radius = 100;
    plWidth = 1000; plHeight = 1000;
    
    shader.load("shader/shader.vert", "shader/shader.frag");
    
    vboMesh = ofSpherePrimitive(radius, 64).getMesh();
    for(int x = 0; x < plWidth; x+=10) {
        for(int z = 0; z < plWidth; z+=10) {
            ofVec3f pos;
            pos.x = x;
            pos.z = z;
            pos.y = ofNoise(x, z)*50.0;
            planeMesh.addVertex(pos);
            planeMesh.addColor(ofFloatColor(ofRandom(1.0), ofRandom(1.0), ofRandom(1.0), 0.8));
        }
    }
    
    planeMesh = ofPlanePrimitive(plWidth, plHeight, 20, 20).getMesh();
    
    for(int i = 0; i < planeMesh.getVertices().size(); i++) {
        int x = i % 10;
        int y = i / 10;
        ofVec3f pos = planeMesh.getVertex(i);
        pos.z += ofNoise(x, y) * 50.0;
        float delight = ofRandom(1.0);
//        planeMesh.addColor(ofFloatColor(delight, delight, delight, 1.0));
        planeMesh.setVertex(i, pos);
        
        ofVec4f spawn = ofVec4f(pos.x, pos.y, pos.z, ofRandom(1, 3));
        spawnP.push_back(spawn);
        
        float velZ = ofRandom(3.0, 6.0);
        spawnVelZ.push_back(velZ);
    }
    
    translate = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, -200);
    
    glPointSize(3.0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fboOnePass.allocate(ofGetWidth(), ofGetHeight());
    fboTwoPass.allocate(ofGetWidth(), ofGetHeight());
    finalFbo.allocate(ofGetWidth(), ofGetHeight());
    blur.load("shader/blur.vert", "shader/blur.frag");
    bloom.load("shader/bloom.vert", "shader/bloom.frag");

    
    gui.setup();
    gui.setPosition(10, 10);
    gui.add(strength.set("strength", 6.0, 3.0, 20.0));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();
    
    for(int i = 0; i < planeMesh.getVertices().size(); i++) {
        ofVec3f pos = planeMesh.getVertex(i);
        float newZ = pos.z + sin(time + i) * 0.3;
        planeMesh.setVertex(i, ofVec3f(pos.x, pos.y, newZ));
        
        if(spawnP[i].w < 0) {
            spawnP[i] = ofVec4f(pos.x, pos.y, pos.z, ofRandom(1,2));
            spawnVelZ[i] = ofRandom(3, 6);
        }
        spawnP[i].w -= 0.01;
        spawnVelZ[i] *= 0.99;
        spawnP[i].z += spawnVelZ[i];
    }
    
    
    // burn to fbo first sketch
    fbo.begin();
    ofClear(0, 0, 0, 0);
    
    cam.begin();
    
    ofRotateYDeg(time * 20.0);

    ofPushMatrix();
    ofTranslate(0, 100, 0);
    
    ofRotateXDeg(time*10);
    ofRotateYDeg(time*12);
    ofRotateZDeg(time*14);
    
    shader.begin();
    
    shader.setUniform1f("time", time);
    vboMesh.draw();
    
    shader.end();
    
    ofPopMatrix();
    
    ofPushMatrix();
    ofScale(1, -1, 1);
    ofRotateXDeg(90.0);
    ofTranslate(0, 0, -200);
    ofSetColor(255);
    planeMesh.drawWireframe();
    ofSetColor(255, 50);
    planeMesh.draw();
    for(int i = 0; i < planeMesh.getVertices().size(); i++) {
        ofVec3f pos = planeMesh.getVertex(i);
        ofSetColor(100, 200, 200,  200);
        ofDrawSphere(pos, 5);
//        ofSetColor(255);
        ofDrawSphere(spawnP[i].x, spawnP[i].y, spawnP[i].z, 5);
    }
    
    ofPopMatrix();
    
    cam.end();
    
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // gaussian blur (Horizontal)
    fboOnePass.begin();
    
    blur.begin();
    blur.setUniformTexture("tex", fbo.getTexture(), 0);
    blur.setUniform1f("minBright", strength);
    blur.setUniform1i("horizontal", true);
    
    fbo.draw(0, 0);
    
    blur.end();
    
    fboOnePass.end();
    
    // gaussian blur (Vertical)
    fboTwoPass.begin();
    
    blur.begin();
    blur.setUniformTexture("tex", fboOnePass.getTexture(), 0);
    blur.setUniform1f("minBright", strength);
    blur.setUniform1i("horizontal", false);
    
    fboOnePass.draw(0, 0);
    
    blur.end();
    
    fboTwoPass.end();
    
    // blending gaussian blur and original

    bloom.begin();

    bloom.setUniformTexture("tex", fbo.getTexture(), 0);
    bloom.setUniformTexture("blur", fboTwoPass.getTexture(), 1);

    fbo.draw(0, 0);

    bloom.end();
    
//    gui.draw();
    
    
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
