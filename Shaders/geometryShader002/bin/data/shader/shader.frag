#version 150
precision mediump float;

uniform float time;

in vec4 vColor;
in vec2 vTexCoord;

out vec4 vFragColor;

void main() {
//    vFragColor = vec4(vTexCoord, 0.5 + sin(time), 1.0);
    vFragColor = vColor;
}
