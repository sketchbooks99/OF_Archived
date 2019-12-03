//
//  WStringConverter.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//
#ifndef WStringConverter_hpp
#define WStringConverter_hpp

#include "ofMain.h"

class WStringConverter {
public:
    static wstring convToWString(string src);
    template <class T>
    static wstring convToUCS4(basic_string<T> src);
};

#endif
