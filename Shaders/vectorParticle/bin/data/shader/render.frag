#version 150
precision mediump float;

in vec2 vTexCoord;
in vec4 vColor;

out vec4 outputColor;

void main() {
    outputColor = vColor;
}
