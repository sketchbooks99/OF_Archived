#include "ofApp.h"

//--------------------------------------------------------------
ofVec2f ofApp::calcRef(float R,float x, float y) {
    ofVec2f result;
    float powR = pow(R,2);
    
    
    float newX = (-2*pow(R,2)*x*y-pow(R,2)*y+2*pow(x,2)*y+2*x*sqrt(pow(R,2)-pow(x,2))*y+pow(R,2)*x) / pow(R,2)*y;
    float newY = (2*x*(-sqrt(pow(R,2)-pow(x,2))+x)*y+pow(R,2)*(2*sqrt(pow(R,2)-pow(x,2))*y-y-sqrt(pow(R,2)-pow(x,2)))) / pow(R,2)*y;
    
    result = ofVec2f(newX, newY);
    return result;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    mesh = ofPlanePrimitive(100, 100, 100, 100).getMesh();
    float R = 5.0;
    
    for(int i=0; i<mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        ofVec3f pos = mesh.getVertex(i);
//        pos.x += 50.0;
//        pos.y += 50.0;
        cout << pos << endl;
        ofVec2f newP = calcRef(10.0, pos.x, pos.y);
        pos.x = newP.x;
        pos.y = newP.y;
        mesh.setVertex(i, pos);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    
    cam.begin();
    ofPushMatrix();
    ofTranslate(-50, 50, 0);
    mesh.draw(OF_MESH_POINTS);
    ofPopMatrix();
    cam.end();
    
    ofDisableDepthTest();
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
