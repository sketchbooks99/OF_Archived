#version 150
precision mediump float;

uniform float time;

in vec2 vTexCoord;
in vec4 vColor;
out vec4 vFragColor;

void main() {
    vFragColor = vec4(vTexCoord, 0.5 + sin(time)*0.5, 1.0);
}
