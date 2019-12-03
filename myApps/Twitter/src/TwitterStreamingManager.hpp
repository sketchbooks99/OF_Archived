//
//  TwitterStreamingManager.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#ifndef TwitterStreamingManager_hpp
#define TwitterStreamingManager_hpp

#include "ofMain.h"
#include "TweetJsonReceiver.hpp"
#include "TweetData.hpp"
#include "ofxOpenGLContextScope.h"
#include "JsonReceivedThread.hpp"

class TwitterStreamingManager {
private:
    JsonReceiveThread mJsonReceiveThread;
public:
    void setup();
    void exit();
};

#endif
