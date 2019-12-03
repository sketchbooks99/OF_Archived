#version 150
precision mediump float;

uniform sampler2DRect debug;

in vec2 vTexCoord;

out vec4 outputColor;

void main() {
  outputColor = texture(debug, vTexCoord);
}
