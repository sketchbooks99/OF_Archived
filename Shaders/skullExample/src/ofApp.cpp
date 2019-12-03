#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofSetFrameRate(60);

    skull.loadModel("Objects/skull.obj", true);
    skull.setScaleNormalization(false);

    shader.load("shader/shader.vert", "shader/shader.frag", "shader/shader.geom");
    ground.load("shader/ground.vert", "shader/ground.frag", "shader/ground.geom");

    vboMesh = skull.getMesh(0);

    cout << vboMesh.getVertices().size() << endl;

//    skull.setScale(1, -1, 1);
//    skull.setPosition(0, -200, 0);
    int texRes = (int)sqrt((float)vboMesh.getVertices().size());
    for(int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec2f texCoord;
        texCoord.x = (float)(i / texRes) / texRes;
        texCoord.y = (float)(i % texRes) / texRes;
        ofVec3f pos = vboMesh.getVertex(i);
        ofVec3f newPos = pos * 60.0;
        newPos.y += (-200.0);
        vboMesh.setVertex(i, newPos);
        vboMesh.addTexCoord(texCoord);
    }

    // 周りのメッシュ
    groundMesh = ofSpherePrimitive(2000.0, 32).getMesh();
    for(int i = 0; i < groundMesh.getVertices().size(); i++) {
        ofVec2f texCoord = groundMesh.getTexCoord(i);
        groundMesh.addColor(ofFloatColor(.2f*sin(texCoord.x * 10.0)+.5f, sin(texCoord.y * 10.0)*.2f +.5f, .2f, 1.0f));
    }

    // skullの周りのboxMesh
    boxMesh = ofBoxPrimitive(500.0, 500.0, 500.0).getMesh();
    for(int i=0; i<boxMesh.getVertices().size(); i++) {
        boxMesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 0.2));
    }

    gui.setup();
    gui.setPosition(10, 10);
    gui.add(strength.set("strength", 0, -200.0, 200.0));
    gui.add(x.set("x", 1.0, 0.0, 1.0));
    gui.add(y.set("y", 1.0, 0.0, 1.0));
    gui.add(z.set("z", 1.0, 0.0, 1.0));
    gui.add(isSkull.setup("isSkull", false));
    gui.add(isGround.setup("isGround", false));
    
    // アウトライン
    outline.load("shader/outline.vert", "shader/outline.frag");
    outlineFbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    time = ofGetElapsedTimef();

    strength = 100.0 + sin(time)*100.0;
    
    // アウトラインエフェクト
    outlineFbo.begin();
    cam.begin();
    ofClear(0);
    outline.begin();
    vboMesh.draw();
    
    outline.end();
    cam.end();
    outlineFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();

    cam.begin();

    // model Matrix
    ofMatrix4x4 modelMatrix;
//    modelMatrix.translate(0, 0, 0);
    // modelMatrix.rotate(-70.0, 0.0, 1.0, 0.0);
//    modelMatrix.scale(1.0+abs(sin(time)), 1.0+abs(sin(time)), 1.0+abs(sin(time)));

    // view Matrix
    ofMatrix4x4 viewMatrix;
    viewMatrix = ofGetCurrentViewMatrix();

    // projection Matrix
    ofMatrix4x4 projectionMatrix;
    projectionMatrix = cam.getProjectionMatrix();

    // mvp Matrix
    ofMatrix4x4 mvpMatrix;
    mvpMatrix = modelMatrix * viewMatrix * projectionMatrix;

    // inversed Matrix(モデル座標変換行列の逆行列)
    ofMatrix4x4 invMatrix = mvpMatrix.getInverse();

    // skullMeshの描画
//    shader.begin();
//    shader.setUniform1f("time", time);
//    shader.setUniformMatrix4f("mvpMatrix", mvpMatrix);
//    shader.setUniformMatrix4f("invMatrix", invMatrix);
//    shader.setUniform1f("strength", strength);
//    shader.setUniform3f("dim", x, y, z);
//    shader.setUniform1i("isSkull", isSkull);
//
//    vboMesh.draw();
//
//    shader.end();

    // 周りの球体メッシュの描画
//    ofPushMatrix();
//    ofRotateXDeg(90.0);
//    ground.begin();
//    ground.setUniform1f("time", time);
//    ground.setUniform3f("dim", x, y, z);
//    ground.setUniform1f("strength", strength);
//    ground.setUniform1i("isGround", isGround);
//
//    groundMesh.draw();
//
//    ground.end();
//    ofPopMatrix();
    
    outlineFbo.draw(0, 0);

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
