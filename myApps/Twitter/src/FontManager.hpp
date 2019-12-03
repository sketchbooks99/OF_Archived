//
//  FontManager.hpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#ifndef FontManager_hpp
#define FontManager_hpp

#include "ofMain.h"
#include "ofxTrueTypeFontUC.h"

class FontManager {
public:
    FontManager(){};
    
    static ofxTrueTypeFontUC mbigfont;
    static ofxTrueTypeFontUC msmallfont;
    
    static void init();
    
    static void loadSmallFont(const string &arg, const int &size);
    static void loadBigFont(const string &arg, const int &size);
    
    static void drawSmallString(const string &arg, const float &x, const float &y);
    static void drawBigString(const string &arg, const float &x, const float &y);
    
    static void drawSmallWString(const wstring &arg, const float &x, const float &y);
    static void drawBigWString(const wstring &arg, const float &x, const float &y);
};

#endif
