#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define NUM 500

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
    

    
    ofShader shader;
    ofShader blur;
    ofShader bloom;
    ofFbo fbo;
    ofFbo fboOnePass, fboTwoPass, finalFbo;
    ofVboMesh vboMesh, planeMesh;
    int plWidth, plHeight;
    float time;
    ofEasyCam cam;
    int radius;
    
    vector<ofVec3f> points;
    vector<ofVec3f> speeds;
    vector<ofVec4f> spawnP;
    vector<float> spawnVelZ;
    
    ofVec3f translate;
    
    ofxPanel gui;
    ofParameter<float> strength;
		
};
