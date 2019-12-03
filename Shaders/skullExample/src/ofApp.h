#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"

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

    ofxAssimpModelLoader skull;
//    ofCamera cam;
    ofEasyCam cam;
    ofVboMesh vboMesh, groundMesh, boxMesh;

    float time;

    ofShader shader, ground;

    ofxPanel gui;
    ofParameter<float> strength;
    ofParameter<float> x;
    ofParameter<float> y;
    ofParameter<float> z;
    ofxToggle isSkull;
    ofxToggle isGround;

    // outline エフェクトをかける部分
    ofShader outline;
    ofFbo outlineFbo;
};
