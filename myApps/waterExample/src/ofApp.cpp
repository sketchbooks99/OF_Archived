#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(5);
    // 速度更新用シェーダ読み込み
    updateVel.load("shader/passthru.vert", "shader/velUpdate.frag");
    updatePres.load("shader/passthru.vert", "shader/presUpdate.frag");
    updateDiv.load("shader/passthru.vert", "shader/divUpdate.frag");
    // レンダリング用シェーダ読み込み
    render.load("shader/render.vert", "shader/render.frag");
    // デバッグ用
    debug.load("shader/passthru.vert", "shader/debug.frag");

    int texRes = 600;
    pingPong.allocate(texRes, texRes, GL_RGB32F);
    float* pos = new float[texRes*texRes*4];
    for(int x=0; x<texRes; x++) {
        for(int y=0; y<texRes; y++) {
            int i = texRes * y + x;
            pos[i*4+0] = ofRandom(0.0, 1.0); // x軸の速度
            pos[i*4+1] = ofRandom(0.0, 1.0); // y軸の速度
            pos[i*4+2] = 0.0;// 圧力
            pos[i*4+3] = 0.0; // 発散値
        }
    }
    pingPong.src->getTexture(0).loadData(pos, texRes, texRes, GL_RGBA);
    delete [] pos;
//    pingPong.dst->getTexture().loadData(pos.data(), texRes, texRes, GL_RGBA);

    // 描画用のfbo
    renderFbo.allocate(texRes, texRes);
    renderFbo.begin();
    ofClear(0);
    ofFill();
    for(int i = 0; i < 10; i++) {
        float x = ofRandom(0, 600);
        float y = ofRandom(0, 600);
        ofSetColor(ofColor::fromHsb(ofRandom(0, 255), 255, 255, 255));
        ofDrawCircle(x, y, ofRandom(30, 70));
    }
    renderFbo.end();
//    prevMouse = ofVec2f((float)ofGetMouseX(), (float)ofGetMouseY());
    prevMouse = ofVec2f(0.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec2f mouseVec = ofVec2f((float)mouseX, (float)mouseY) - prevMouse;


    // 発散
    pingPong.dst->begin();
    ofClear(0);
    updateDiv.begin();
    updateDiv.setUniform2f("resolution", pingPong.src->getWidth(), pingPong.src->getHeight());
    updateDiv.setUniformTexture("preVel", pingPong.src->getTexture(0), 0);
    pingPong.src->draw(0, 0);
    updateDiv.end();
    pingPong.dst->end();
    pingPong.swap();


    // 圧力
    for(int i=0; i<4; i++) {
        pingPong.dst->begin();
        ofClear(0);
        updatePres.begin();
        updatePres.setUniform2f("resolution", pingPong.src->getWidth(), pingPong.src->getHeight()   );
        updatePres.setUniformTexture("preVel", pingPong.src->getTexture(), 0);
        pingPong.src->draw(0, 0);
        updatePres.end();
        pingPong.dst->end();
        pingPong.swap();
    }

    // 速度
    pingPong.dst->begin();
    ofClear(0);
    updateVel.begin();
    updateVel.setUniformTexture("preVel", pingPong.src->getTexture(), 0);
    updateVel.setUniform2f("mouseVec", mouseVec);
    updateVel.setUniform2f("resolution", pingPong.src->getWidth(), pingPong.src->getHeight());
    pingPong.src->draw(0, 0);
    updateVel.end();

    pingPong.dst->end();
    pingPong.swap();


    prevMouse = ofVec2f(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    render.begin();
    render.setUniformTexture("render", renderFbo.getTexture(), 0);
    render.setUniformTexture("velTex", pingPong.dst->getTexture(), 1);
    renderFbo.draw(0, 0);

    render.end();


//    debug.begin();
//    debug.setUniformTexture("debug", pingPong.dst->getTexture(), 0);
//    pingPong.dst->draw(0, 0);
//    debug.end();

    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
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
