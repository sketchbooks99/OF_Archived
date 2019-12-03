#version 150
precision mediump float;

uniform sampler2DRect video;
uniform sampler2DRect particle;

in vec2 vTexCoord;

out vec4 outputColor;

void main() {
    vec4 vid = texture(video, vTexCoord);
    vec4 par = texture(particle, vTexCoord);
    
//    vec4 color = mix(vid, par, 0.5);
    vec4 color = vid + par;
    
    outputColor = color;
}
