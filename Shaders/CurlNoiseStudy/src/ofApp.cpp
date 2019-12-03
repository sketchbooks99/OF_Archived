#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
//    ofSetFrameRate(60);
    ofBackground(0);
    ofDisableAlphaBlending();

    numParticles = 700 * 700;

    // アップデート用シェーダ
    updatePos.load("shader/passthru.vert", "shader/posUpdate.frag");
    // レンダリング用シェーダ
    render.load("shader/render.vert", "shader/render.frag");
    // FBO setting
    renderFbo.allocate(ofGetWidth(), ofGetHeight());
    

    texRes = (int)sqrt((float)numParticles);
    numParticles = texRes * texRes;

    // particleの設定
    particles.setMode(OF_PRIMITIVE_POINTS);
    for(int x = 0; x < texRes; x++) {
        for(int y = 0; y < texRes; y++) {
            int index = texRes * y + x;
            if(index < numParticles) {
                particles.addVertex(ofVec3f(0, 0, 0));
                particles.addTexCoord(ofVec2f(x, y));
                particles.addColor(ofFloatColor(1.0, 1.0, 1.0, 0.5));
            }
        }
    }

    // パーティクルの座標・加速度の保存用FBO
    // RGBA32Fの形式で2つのColorBufferを用意

    posPingPong.allocate(texRes, texRes, GL_RGBA32F, 2);

    // パーティクルの位置と経過時間の初期設定
    float * posAndAge = new float[texRes * texRes * 4];
    for(int x = 0; x < texRes; x++) {
        for(int y = 0; y < texRes; y++) {
            int i = texRes * y + x;
            posAndAge[i*4+0] = ofRandom(-1.0, 1.0);
            posAndAge[i*4+1] = ofRandom(-1.0, 1.0);
            posAndAge[i*4+2] = ofRandom(-1.0, 1.0);
            posAndAge[i*4+3] = 0;
        }
    }
    // pingPongBufferに初期値を書き込み

    posPingPong.src->getTexture(0).loadData(posAndAge, texRes, texRes, GL_RGBA);
    delete [] posAndAge;

    // パーティクルの速度と生存期間の設定
    float * velAndMax = new float[texRes * texRes * 4];
    for(int x = 0; x < texRes; x++) {
        for(int y = 0; y < texRes; y++) {
            int i = texRes * y + x;
            velAndMax[i*4+0] = ofRandom(-1, 1);
            velAndMax[i*4+1] = ofRandom(-1, 1);
            velAndMax[i*4+2] = ofRandom(-1, 1);
            // velAndMax[i*4+3] = ofRandom(1, 150);
            velAndMax[i*4+3] = 60.0;
        }
    }

    // pingPongBufferに書き込み
    posPingPong.src->getTexture(1).loadData(velAndMax, texRes, texRes, GL_RGBA);
    delete [] velAndMax;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    float time = ofGetElapsedTimef();

    // パーティクルの発生位置を更新
    prevEmitterPos = emitterPos;
    emitterPos = 150 * ofVec3f(ofSignedNoise(time, 0, 0), ofSignedNoise(0, time, 0), ofSignedNoise(0, 0, time));

    // パーティクルの位置を計算
    posPingPong.dst->begin();

    // 複数バッファの書き出しを有効化
    posPingPong.dst->activateAllDrawBuffers();
    ofClear(0);
    updatePos.begin();

    // パーティクルの位置と経過時間
    updatePos.setUniformTexture("posAndAgeTex", posPingPong.src->getTexture(0), 0);

    // パーティクルの速度と生存期間
    updatePos.setUniformTexture("velAndMaxTex", posPingPong.src->getTexture(1), 1);
    // パーティクルの色
    updatePos.setUniform1f("time", time);
    updatePos.setUniform1f("timestep", 0.1);
    updatePos.setUniform1f("scale", 0.01);
    updatePos.setUniform3f("emitterPos", emitterPos);
    updatePos.setUniform3f("prevEmitterPos", prevEmitterPos);
    updatePos.setUniform1i("mode", mode);
    posPingPong.src->draw(0, 0);
    updatePos.end();
    posPingPong.dst->end();
    posPingPong.swap();


    // レンダリング
    renderFbo.begin();
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofEnablePointSprites();

    float radius = 400.0 + abs(sin(time)) * 400.0;
    cam.setPosition(sin(time*0.7)*cos(TWO_PI)*radius, sin(time*0.7)*sin(TWO_PI)*radius, cos(time*1.0)*radius);
    cam.lookAt(glm::vec3(0.0, 0.0, 0.0));

    cam.begin();

    ofPushMatrix();

    ofClear(0, 0, 0);

    render.begin();

    render.setUniformTexture("posAndAgeTex", posPingPong.src->getTexture(0), 0);
    render.setUniform1f("time", ofGetElapsedTimef());
    particles.draw();

    render.end();

    ofPopMatrix();

    cam.end();

    ofDisablePointSprites();
    ofPopStyle();
    renderFbo.end();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    renderFbo.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    mode = (int)ofRandom(0, 5);
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
