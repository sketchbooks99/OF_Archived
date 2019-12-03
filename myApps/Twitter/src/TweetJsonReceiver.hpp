//
//  TweetJsonReceiver.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#ifndef TweetJsonReceiver_hpp
#define TweetJsonReceiver_hpp

#include "ofxJSONElement.h"
#include "TweetData.hpp"
#include "ofMain.h"
#include "WStringConverter.hpp"

#define DATA_MAX_NUM 50

class TweetJsonReceiver {
public:
    int64_t cachedTweetId;
    ofxJSONElement jsonElement;
    static int data_num;
    static vector<TweetData> tweetData;
    static TweetJsonReceiver &getInstance();
    
    TweetJsonReceiver(){}
    TweetJsonReceiver &operator=(const TweetJsonReceiver &other){}
    
    vector<TweetData> getTweetData();
    bool checkUpdateJson();
    void parseJson();
    void init();
    void update();
    bool receive();
};

#endif
