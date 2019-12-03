#version 150
precision mediump float;

uniform sampler2DRect velData;
uniform sampler2DRect posData;
uniform vec2 attractor;
uniform float strength;
uniform float maxVel;

in vec2 vTexCoord;

out vec4 vFragColor;

void main() {
    vec2 pos = texture(posData, vTexCoord).xy;
    vec2 vel = texture(velData, vTexCoord).xy;
    
    vec2 m = attractor / vec2(1024.0, 768.0);
    vec2 dir = m - pos;
//    vec2 acc = 0.001 * normalize(dir);
    vec2 acc = strength * normalize(dir);
    
    vel += acc;
    
    if(vel.x > maxVel) vel.x = maxVel;
    if(vel.y > maxVel) vel.y = maxVel;
    vec2 nextPos = vel + pos;
    
    
    vFragColor = vec4(vel, 0.0, 1.0);
}
