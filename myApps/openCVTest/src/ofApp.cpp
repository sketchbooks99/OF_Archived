#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    vidGrabber.initGrabber(640, 480);
    
    colorImg.allocate(640, 480);
    grayImg.allocate(640, 480);
    grayBg.allocate(640, 480);
    grayDiff.allocate(640, 480);
    
    bLearnBackground = true;
    
    gui.setup();
    gui.add(threshold.set("threshold", 80, 0, 200));
    
    ofSetLineWidth(0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
    bool bNewFrame = false;
    vidGrabber.update();
    bNewFrame = vidGrabber.isFrameNew();
    
    colorImg.setFromPixels(vidGrabber.getPixels());
    colorImg.mirror(false, true);
    
    grayImg = colorImg;
    
    if(bLearnBackground == true) {
        grayBg = grayImg;
        bLearnBackground = false;
    }

    grayDiff.absDiff(grayBg, grayImg);
    grayDiff.threshold(threshold);

    contourFinder.findContours(grayDiff, 20, (640*480) / 3, 10, true);

    points.resize(contourFinder.nBlobs);
    for(int i = 0; i < contourFinder.nBlobs; i++) {
        points[i].resize(contourFinder.blobs[i].pts.size());
        for(int j = 0; j < contourFinder.blobs[i].pts.size(); j++) {
            if(points[i][j].size() < 10) {
                ofVec2f p = contourFinder.blobs[i].pts[j];
                points[i][j].push_back(p);
            } else {
                points[i][j].erase(points[i][j].begin());
                ofVec2f p = contourFinder.blobs[i].pts[j];
                points[i][j].push_back(p);
            }
        }
       cout << contourFinder.blobs[i].pts.size() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    colorImg.draw(0, 0, 640, 480);
    gui.draw();

    if(points.size() > 0) {
        for(int i = 0; i < points.size(); i++) {
            for(int j = 0; j < points[i].size(); j++) {
                int last = points[i][j].size() - 1;

                float dist = points[i][j][0].distance(points[i][j][last]);
                cout << points[i][j].size() << endl;
                if(dist > 30) {
                    ofBeginShape();
                   for(int l = 0; l < points[i][j].size() - 1; l++) {
                        ofSetColor(ofColor::fromHsb(ofMap(l, 0, 9, 0, 255), 255, 255, 127));
                        // ofVertex(points[i][j][l]);
                        ofDrawLine(points[i][j][l], points[i][j][l + 1]);
                        ofDrawCircle(points[i][j][l], 2);
                    }
                    ofEndShape();
                }
            }
        }
    }
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
