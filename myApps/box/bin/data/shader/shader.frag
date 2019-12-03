#version 150
precision mediump float;

uniform float time;

in vec2 vTexCoord;
in vec4 vColor;

out vec4 vFragColor;

void main() {
    
    vFragColor = vec4(vTexCoord, 0.0, 1.0);
}
