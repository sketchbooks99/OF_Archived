//
//  Birds.hpp
//  shader003
//
//  Created by 木内舜司 on 2018/08/30.
//

#ifndef Birds_hpp
#define Birds_hpp

#include "ofMain.h"

class Birds {
    
public:
    ofVec3f loc; // 位置
    ofVec3f vel; // 速度
    ofVec3f acc; // 加速度
    ofVec2f imgSize;
    ofVboMesh mesh;
    ofImage img;
    ofShader shader;
    
    Birds();
    
    void init(int x, int y, int z, int size);
    void update();
    void draw();
    
};

#endif /* Birds_hpp */
