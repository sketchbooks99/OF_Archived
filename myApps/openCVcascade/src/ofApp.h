#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"

class Circle {
public:
    ofVec2f loc; // 位置
    ofVec2f vel; // 速度
    ofVec2f acc; // 加速度
    float radius; // 半径
    ofColor color; // 色
    
    Circle() { // コンストラクタ
        
    }
    
    void init(float x, float y) {
        acc = ofVec2f(ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1));
        vel = ofVec2f(0, 0);
        loc = ofVec2f(x, y);
        color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255), 150);
        radius = ofRandom(2, 5);
    }
    
    void draw() {
        ofSetColor(color);
        ofDrawCircle(loc, radius);
    }
    
    void update() {
        vel += acc;
        loc += vel;
        checkVel();
        checkEdges(640, 480);
    }
    
    void checkVel() {
        if(vel.x > 5) {
            vel.x = 5;
        } else if(vel.x < -5) {
            vel.x = -5;
        }
        
        if(vel.y > 5) {
            vel.y = 5;
        } else if(vel.y < -5) {
            vel.y = -5;
        }
    }
    
    void checkEdges(int x, int y) {
        if(loc.x < 0 || loc.x > x) {
            vel.x *= -1;
            acc.x *= -1;
        }
        if(loc.y < 0 || loc.y > y) {
            vel.y *= -1;
            acc.y *= -1;
        }
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofVideoGrabber vidGrabber;
    
    ofxCvHaarFinder finder;
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImg;
    
    ofVec2f eyePos;
    vector<Circle> circles;
    
    ofVbo vbo;
    
    ofxPanel gui;
};
