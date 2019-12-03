//
//  Birds.cpp
//  shader003
//
//  Created by 木内舜司 on 2018/08/30.
//

#include "Birds.hpp"

//--------------------------------------------------------------
Birds::Birds() {
    
}

//--------------------------------------------------------------
void Birds::init(int x, int y, int z, int size) {
//    img.load("twitter.png");
    imgSize = ofVec2f(size, size);
    img.resize(imgSize.x, imgSize.y);
    loc = ofVec3f(x, y, z);
    vel = ofVec3f(0);
    acc = ofVec3f(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
    
    mesh = ofPlanePrimitive(imgSize.x, imgSize.y, imgSize.x, imgSize.y).getMesh();
    for(int i = 0; i < mesh.getVertices().size(); i++) {
        ofVec2f texCoord = mesh.getTexCoord(i);
        texCoord.x *= imgSize.x;
        texCoord.y *= imgSize.y;
        mesh.setTexCoord(i, texCoord);
    }
}

//--------------------------------------------------------------
void Birds::update() {
    vel += acc;
    loc += vel;
    if(loc.x < 0 || loc.x > ofGetWidth())
        vel.x *= -1;
    if(loc.y < 0 || loc.y > ofGetHeight())
        vel.y *= -1;
    if(loc.z > 0 || loc.z < -1000)
        vel.z *= -1;
}

//--------------------------------------------------------------
void Birds::draw() {
    ofPushMatrix();
    
    ofTranslate(loc.x, loc.y, loc.z);
    
    shader.begin();
    shader.setUniformTexture("tex", img.getTexture(), 0);
    shader.setUniform1f("time", ofGetElapsedTimef() * 10.0);
    shader.setUniform2f("imgSize", imgSize);
    
    mesh.draw();
    
    shader.end();
    
    ofPopMatrix();
}

//--------------------------------------------------------------

//--------------------------------------------------------------

