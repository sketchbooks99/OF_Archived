//
//  TweetJsonReceiver.cpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#include "TweetJsonReceiver.hpp"

vector<TweetData> TweetJsonReceiver::tweetData;
int TweetJsonReceiver::data_num;

//-------------------------------------------------------------------------------------
TweetJsonReceiver &TweetJsonReceiver::getInstance() {
    static TweetJsonReceiver instance;
    return instance;
}

//-------------------------------------------------------------------------------------
vector<TweetData> TweetJsonReceiver::getTweetData() {
    return tweetData;
}

//-------------------------------------------------------------------------------------
bool TweetJsonReceiver::checkUpdateJson() {
    if(jsonElement["id"].asInt64() != cachedTweetId) {
        cachedTweetId = jsonElement["id"].asInt64();
        return true;
    } else {
        return false;
    }
}

//-------------------------------------------------------------------------------------
void TweetJsonReceiver::init() {
    data_num = 0;
    TweetJsonReceiver::tweetData.clear();
    bool parsingSuccesful = jsonElement.openLocal("../../../TweetStream/twitter.json");
    if(parsingSuccesful) {
        cout << "Parsing Succesful" << endl;
        cachedTweetId = jsonElement["id"].asInt64();
    } else {
        cout << "Failed to parse JSON" << endl;
    }
}

//-------------------------------------------------------------------------------------
void TweetJsonReceiver::parseJson() {
    string tmptext = jsonElement["text"].asCString();
    string tmpusername = jsonElement["user"]["name"].asCString();
    wstring wtmptext = WStringConverter::convToWString(tmptext);
    wstring wtmpusername = WStringConverter::convToWString(tmpusername);
    
    tweetData.push_back((TweetData) {
        WStringConverter::convToWString(tmptext),
        WStringConverter::convToWString(tmpusername),
        jsonElement["user"]["screen_name"].asCString(),
        jsonElement["user"]["profile_image_url"].asCString(),
        jsonElement["user"]["friends_count"].asInt(),
        jsonElement["user"]["statuses_count"].asInt(),
        jsonElement["user"]["followers_count"].asInt(),
        jsonElement["place"]["bounding_box"]["coordinates"][0][0][0].asFloat(),
        jsonElement["place"]["bounding_box"]["coordinates"][0][0][1].asFloat()
    });
    data_num++;
    return;
}

//-------------------------------------------------------------------------------------
// Jsonの数に変化があればその分をtweetDataに追加
void TweetJsonReceiver::update() {
    
    // tweetDataが無限に溜まらないようにFIFOさせる
    if(TweetJsonReceiver::tweetData.size() > DATA_MAX_NUM) {
        TweetJsonReceiver::tweetData.erase(TweetJsonReceiver::tweetData.begin());
        cout << "Clear data" << endl;
    }
    
    receive();
}

//-------------------------------------------------------------------------------------
bool TweetJsonReceiver::receive() {
    bool parsingSuccesful = jsonElement.openLocal("../../../TweetStream/twitter.json");
    if(parsingSuccesful) {
        if(checkUpdateJson()) {
            parseJson();
            cout << "Parse JSON" << endl;
            return true;
        }
    } else {
        cout << "Failed to parse JSON" << endl;
    }
    return false;
}
