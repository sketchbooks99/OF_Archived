#version 150
precision mediump float;

uniform sampler2DRect tex;

in vec4 vColor;
in vec2 vTexCoord;

out vec4 outputColor;

void main() {
    outputColor = vColor;
}
