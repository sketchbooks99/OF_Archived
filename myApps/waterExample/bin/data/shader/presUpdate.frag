#version 150
precision mediump float;

uniform sampler2DRect preVel;
uniform vec2 resolution;

in vec2 vTexCoord;

out vec4 outputColor;

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

// 圧力計算
void main() {
  vec4 p = texture(preVel, vTexCoord);

  vec2 offsetX = vec2(1.0, 0.0);
  vec2 offsetY = vec2(0.0, 1.0);

  float rp = calcPress(preVel, vTexCoord+offsetX, resolution);
  float lp = calcPress(preVel, vTexCoord-offsetX, resolution);
  float bp = calcPress(preVel, vTexCoord+offsetY, resolution);
  float up = calcPress(preVel, vTexCoord-offsetY, resolution);

  float divergence = p.w;
  float pressure = (divergence + (rp+lp+bp+up))*0.25;

  outputColor = vec4(p.xy, pressure, divergence);
}
