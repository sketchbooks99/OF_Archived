#version 150
precision mediump float;

uniform sampler2DRect posData;
uniform sampler2DRect velData;

in vec2 vTexCoord;

out vec4 vFragColor;

void main() {
    vec2 pos = texture(posData, vTexCoord).xy;
    vec2 vel = texture(velData, vTexCoord).xy;
    
    pos += vel;
    
    vFragColor = vec4(pos, 0.0, 1.0);
}
