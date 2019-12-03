//
//  TweetData.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#ifndef TweetData_hpp
#define TweetData_hpp

#include "ofMain.h"

class TweetData{
public:
    wstring tweet_text;
    wstring user_name;
    string twitter_id;
    string icon_url;
    
    int friends_count;
    int statuses_count;
    int followers_count;
    
    float lon, lat; // 緯度と経度
    
    ofImage image;
    
    TweetData();
    TweetData(const wstring &tweet_text,
              const wstring &user_name,
              const string &twitter_id,
              const string &icon_url,
              const int &friend_count,
              const int &statuses_count,
              const int &followers_count,
              const float &lon,
              const float &lat);
};

#endif /* TweetData_hpp */
