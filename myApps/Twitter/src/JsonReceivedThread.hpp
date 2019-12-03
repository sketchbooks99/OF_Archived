//
//  JsonReceivedThread.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//
#ifndef JsonReceiveThread_hpp
#define JsonReceiveThread_hpp

#include "ofMain.h"
#include "TweetJsonReceiver.hpp"
#include "ofxOpenGLContextScope.h"

class JsonReceiveThread : public ofThread {
public:
    void threadedFunction() {
        ofxOpenGLContextScope scope;
        while(isThreadRunning()) {
            if(lock()) {
                TweetJsonReceiver::getInstance().update();
                unlock();
                sleep(100);
            }
        }
    }
};

#endif
