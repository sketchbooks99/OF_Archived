//
//  TweetData.cpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#include "TweetData.hpp"

//------------------------------------------------------------------------
TweetData::TweetData() {
    
}

//------------------------------------------------------------------------
TweetData::TweetData(const wstring &tweet_text,
                     const wstring &user_name,
                     const string &twitter_id,
                     const string &icon_url,
                     const int &friends_count,
                     const int &statuses_count,
                     const int &followers_count,
                     const float &lon,
                     const float &lat) {
    
    cout << twitter_id << endl;
    this->tweet_text = tweet_text;
    this->user_name = user_name;
    this->twitter_id = twitter_id;
    this->icon_url = icon_url;
    this->friends_count = friends_count;
    this->statuses_count = statuses_count;
    this->followers_count = followers_count;
    this->image.load(this->icon_url);
    this->lon = lon;
    this->lat = lat;
}
