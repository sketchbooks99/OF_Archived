#version 150
precision mediump float;

uniform float time;

in vec2 vTexCoord;
in vec4 vColor;
in vec3 vNormal;

out vec4 vFragColor;

void main() {
  vFragColor = vec4(vColor.rgb + vec3(0.3+sin(time*4.0 + vTexCoord.y*20.0)*0.3), vColor.a);
  // vFragColor = vec4(vNormal, 1.0);
}
