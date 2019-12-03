//
//  TwitterStreamingManager.cpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#include "TwitterStreamingManager.hpp"

//-------------------------------------------------------------------------------------
void TwitterStreamingManager::setup() {
    
    // Twitter初期化はメインスレッドで行う
    if(TweetJsonReceiver::tweetData.size() > 0) return;
    TweetJsonReceiver::getInstance().init();
    
    ofxOpenGLContextScope::setup();
    mJsonReceiveThread.startThread();
}

//-------------------------------------------------------------------------------------
void TwitterStreamingManager::exit() {
    mJsonReceiveThread.stopThread();
}
