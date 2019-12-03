#pragma once

#include "ofMain.h"

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
    
    unsigned int loadCubeMap(string name[]);
    void drawCube(int width);
    void createMesh();
    
    const int width = 256;
		
    ofShader shader;
    ofEasyCam cam;
    ofVboMesh vboMesh, skullMesh;
    ofTexture tex;
    
    ofImage img[6];
    
    ofVec3f mousePos;
    
    ofVboMesh boxFaces[6];
    
    // cubeMapTexture用の変数
    unsigned int cubeTexture;
};
