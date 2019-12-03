//
//  FontManager.cpp
//  Twitter
//
//  Created by 木内舜司 on 2018/08/28.
//

#include "FontManager.hpp"
#include <codecvt>

ofxTrueTypeFontUC FontManager::msmallfont;
ofxTrueTypeFontUC FontManager::mbigfont;

//------------------------------------------------------------------------
void FontManager::init() {
    setlocale(LC_CTYPE, "");
    if(msmallfont.isLoaded()) return;
    FontManager::loadSmallFont("font.otf", 15);
    FontManager::loadBigFont("font.otf", 30);
    
    
}

//------------------------------------------------------------------------
void FontManager::loadSmallFont(const string &arg, const int &size) {
    msmallfont.loadFont(arg, size);
}

//------------------------------------------------------------------------
void FontManager::drawSmallString(const string &arg, const float &x, const float &y) {
    msmallfont.drawString(arg, x, y);
}

//------------------------------------------------------------------------
void FontManager::drawSmallWString(const wstring &arg, const float &x, const float &y) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> cv;
    std::string convertedString = cv.to_bytes(arg);
    msmallfont.drawString(convertedString, x, y);
}

//------------------------------------------------------------------------
void FontManager::loadBigFont(const string &arg, const int &size) {
    mbigfont.loadFont(arg, size);
}

//------------------------------------------------------------------------
void FontManager::drawBigString(const string &arg, const float &x, const float &y) {
    mbigfont.drawString(arg, x, y);
}

//------------------------------------------------------------------------
void FontManager::drawBigWString(const wstring &arg, const float &x, const float &y) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>,wchar_t> cv;
    std::string convertedString = cv.to_bytes(arg);
    mbigfont.drawString(convertedString, x, y);
}
