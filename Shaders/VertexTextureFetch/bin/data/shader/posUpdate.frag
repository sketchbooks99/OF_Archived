#version 150
precision mediump float;

uniform sampler2DRect prevPosData;
uniform vec2 mouse;
uniform float velocity;
uniform bool mouseFrag;
const float SPEED = 0.05;

in vec2 vTexCoord;
out vec4 outputColor;

//void main() {
//    vec4 pos = texture(prevPosData, vTexCoord);
//    // pos = pos * 2.0;
//    vec2 v = normalize(mouse - pos.xy) * 0.2;
//    vec2 w = normalize(v + pos.zw);
//
//    vec4 destColor = vec4(pos.xy + w * SPEED * velocity, w);
//    if(!mouseFrag) destColor.zw = pos.zw;
//    outputColor = destColor;
//}

void main() {
    vec4 pos = texture(prevPosData, vTexCoord);
}

