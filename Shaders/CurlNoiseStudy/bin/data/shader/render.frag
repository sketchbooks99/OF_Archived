#version 150
precision mediump float;

uniform sampler2DRect posAndAgeTex;
uniform float time;

in vec2 vTexCoord;
in vec4 vColor;
in vec4 vNormal;

out vec4 vFragColor;

void main() {
  // vFragColor = vec4(1.0, 0.8, 0.3, 1.0);
  vFragColor = vec4(1.0, 0.5+sin(time)*0.3, 0.3, 1.0);


}
