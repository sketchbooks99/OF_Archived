#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    img.load("twitter.png");
    
    shader.load("shader/shader.vert", "shader/shader.frag");
    
    imgWidth = 60;
    imgHeight = 60;
    
    vboMesh = ofPlanePrimitive(imgWidth, imgHeight, imgWidth, imgHeight).getMesh();
    for(int i = 0; i < vboMesh.getVertices().size(); i++) {
        ofVec2f texcoord = vboMesh.getTexCoord(i);
        texcoord.x *= imgWidth;
        texcoord.y = texcoord.y * imgHeight;
        vboMesh.setTexCoord(i, texcoord);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    cam.begin();
//
//    shader.begin();
//
//    shader.setUniformTexture("tex", img.getTexture(), 0);
//    shader.setUniform1f("time", ofGetElapsedTimef());
//    shader.setUniform2f("imgSize", (float)imgWidth, (float)imgHeight);
//    vboMesh.draw();
//
//    shader.end();
//
    
    if(birds.size() > 0) {
        for(int i = 0; i < birds.size(); i++) {
            birds[i].update();
            birds[i].draw();
        }
    }
    
    cam.end();
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
    Birds bird = Birds();
    bird.shader = this->shader;
    bird.img = this->img;
    bird.init(ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2),
              ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2),
              0,
              (int)ofRandom(50, 70));
    birds.push_back(bird);
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
