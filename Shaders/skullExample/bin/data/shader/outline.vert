#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec4 normal;
in vec4 color;

void main() {
  vec3 p = position.xyz;
  p.xyz += normal.xyz * 0.04f;
  gl_Position = modelViewProjectionMatrix * vec4(p, 1.0);
}
