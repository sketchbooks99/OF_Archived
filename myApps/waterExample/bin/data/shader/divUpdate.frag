#version 150
precision mediump float;

uniform sampler2DRect preVel;
uniform vec2 resolution;

in vec2 vTexCoord;

out vec4 outputColor;

vec2 calcVel(sampler2DRect tex, vec2 uv, vec2 res) {
  vec2 newUV = vec2(0.0);
  if(uv.x < 0.0) {
    newUV.x = res.x;
  } else if(uv.x > res.x) {
    newUV.x = -res.y;
  }

  if(uv.y < 0.0) {
    newUV.y = res.y;
  } else if(uv.y > res.y) {
    newUV.y = -res.y;
  }

  return texture(tex, uv+newUV).xy;
}

// 発散計算
void main() {
  vec3 p = texture(preVel, vTexCoord).xyz;

  vec2 offsetX = vec2(1.0, 0.0);
  vec2 offsetY = vec2(0.0, 1.0);

  vec2 rVel = calcVel(preVel, vTexCoord+offsetX, resolution);
  vec2 lVel = calcVel(preVel, vTexCoord-offsetX, resolution);
  vec2 bVel = calcVel(preVel, vTexCoord+offsetY, resolution);
  vec2 uVel = calcVel(preVel, vTexCoord-offsetY, resolution);

  float d = ((rVel.x-lVel.x) + (bVel.y - uVel.y)) * 0.5;
  outputColor = vec4(p, d);
}
