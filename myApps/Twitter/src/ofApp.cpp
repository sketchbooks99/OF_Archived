#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    twitterStreamingManager.setup();
    FontManager::init();
    font.load("verdana.ttf", 70);
    w = 60;
    h = 60;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle("FPS : " + ofToString(ofGetFrameRate()) + "/ num of element:" + ofToString(TweetJsonReceiver::data_num));
    
    if(images.size() > 15 * 7) {
        images.erase(images.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofDrawRectangle(0, 420, ofGetWidth(), ofGetHeight() - 420);
    if(TweetJsonReceiver::tweetData.size() > 0) {
        if(icon_url != TweetJsonReceiver::tweetData.back().icon_url)
            images.push_back(TweetJsonReceiver::tweetData.back().image);
        
//        アカウント情報の描画部分
        TweetJsonReceiver::tweetData.back().image.draw(50, 450, 60, 60);
        ofSetColor(30);
//        FontManager::drawSmallString("@"+ofToString(TweetJsonReceiver::tweetData.back().twitter_id), 150, -60);
        FontManager::drawSmallWString(TweetJsonReceiver::tweetData.back().user_name, 120, 490);
//        FontManager::drawSmallString("followers_count: " + ofToString(TweetJsonReceiver::tweetData.back().followers_count), 150, -20);
//        FontManager::drawSmallString("friends_count: "+ofToString(TweetJsonReceiver::tweetData.back().friends_count), 150, 0);
        FontManager::drawSmallWString(TweetJsonReceiver::tweetData.back().tweet_text, 50, 540);
        if(TweetJsonReceiver::tweetData.back().lon != 0) {
            FontManager::drawSmallString("Longtitude : " + ofToString(TweetJsonReceiver::tweetData.back().lon), 150, 40);
            FontManager::drawSmallString("Latitude : " + ofToString(TweetJsonReceiver::tweetData.back().lat), 150, 60);
        }
        icon_url = TweetJsonReceiver::tweetData.back().icon_url;
    }
//    font.drawString("Perfume Tweet", 150, 90);
    ofSetColor(200);
    for(int i = 0; i < images.size(); i++) {
        int posX = (i % 15) * w;
        int posY = (i / 15) * h;
        images[i].draw(posX, posY, w, h);
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
