#version 150
precision mediump float;

uniform sampler2DRect preVel;
uniform vec2 mouseVec;
uniform vec2 resolution;

in vec2 vTexCoord;

out vec4 vFragColor;

// x,y...各ピクセルに格納されている速度
// z...圧力
float calcPress(sampler2DRect tex, vec2 uv, vec2 res) {
  vec2 newUV = vec2(0.0);
  if(uv.x < 0.0) {
    newUV.x = res.x;
  } else if(uv.x > res.x) {
    newUV.x = -res.x;
  }

  if(uv.y < 0.0) {
    newUV.y = res.y;
  } else if(uv.y > res.y) {
    newUV.y = -res.y;
  }

  return texture(tex, uv+newUV).z;
}

vec2 addForce(vec2 target, vec2 force) {
  target += force;
  return target;
}

// 速度計算
void main() {
  // Stable Fluidの計算するYO!
  vec2 offsetX = vec2(1.0, 0.0);
  vec2 offsetY = vec2(0.0, 1.0);

  vec4 p = texture(preVel, vTexCoord);
  float lp = calcPress(preVel, vTexCoord - offsetX, resolution); // left pixel
  float rp = calcPress(preVel, vTexCoord + offsetX, resolution); // right pixel
  float bp = calcPress(preVel, vTexCoord - offsetX, resolution); // up pixel
  float up = calcPress(preVel, vTexCoord + offsetX, resolution); // buttom pixel

  vec2 v = p.xy;
  v += vec2(rp-lp, bp-up) * 0.5;

  v += addForce(v, mouseVec);

  vFragColor = vec4(v, p.zw);
  // vFragColor = vec4(vTexCoord, 1.0, 1.0);

}
