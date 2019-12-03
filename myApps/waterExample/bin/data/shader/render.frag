#version 150
precision mediump float;

uniform sampler2DRect velTex;
uniform sampler2DRect render;

in vec2 vTexCoord;

out vec4 outputColor;

void main() {
  vec4 p = texture(render, vTexCoord);
  vec4 vel = texture(velTex, vTexCoord);

  // vec2 newTex;
  // if(vel.x > 0.0 && vel.y > 0.0) {
  //   newTex = vTexCoord - vec2(1.0, 1.0);
  // } else if(vel.x > 0.0 && vel.y < 0.0) {
  //   newTex = vTexCoord - vec2(1.0, -1.0);
  // } else if(vel.x < 0.0 && vel.y > 0.0) {
  //   newTex = vTexCoord - vec2(-1.0, 1.0);
  // } else {
  //   newTex = vTexCoord - vec2(-1.0, -1.0);
  // }
  // vec4 newP = texture(render, newTex);
  // outputColor = newP;
  outputColor = vec4(vel.z, vel.z*0.5, vel.z*0.3, 1.0);
}
