#version 150
precision mediump float;


uniform mat4 mvpMatrix;
uniform mat4 invMatrix;
uniform float time;
uniform int size;

in vec4 vColor;
in vec2 vTexCoord;
in vec3 vNormal;
in vec4 vPosition;

out vec4 vFragColor;

const float m = 100.0;
const float refrac = 100.0;

void main() {
  //    vec3 lightDir = vec3(0.0, 1000.0, 1.0);
  //    vec3 invLight = normalize(invMatrix * vec4(lightDir, 0.0)).xyz;
  //    float diffuse = clamp(dot(vNormal, normalize(invLight)), 0.1, 1.0);
  //    float light = dot(normalize(lightDir), vNormal);

  // Cook-Trrans鏡面反射モデル
  // ライトのベース色
  vec3 lightColor = vec3(vTexCoord.x, vTexCoord.y, sin(time)*0.5+0.5);
  float offsetY = mod(time+vTexCoord.y, 1.0);
  offsetY = mod(vTexCoord.y, 1.0);
  offsetY = 0.0;
  lightColor = vec3(0.3+offsetY*1.0,offsetY*0.3, offsetY*0.7);
  vec3 la = vec3(0.4, 0.4, 0.4);// ライト環境光
  la = lightColor*0.7;
  vec3 ld = vec3(0.8, 0.8, 0.8);// ライト拡散反射光
  ld = lightColor*0.8;
  vec3 ls = vec3(1.0, 1.0, 1.0);// ライト鏡面反射光
  ls = lightColor;
  vec3 lp = vec3(0.0, 0.0, 1.0);// ライト位置

  // マテリアルの色
  vec3 kColor = vec3(0.3+offsetY*0.7,offsetY*0.3, offsetY*0.7);
  vec3 ke = vec3(0.0, 0.0, 0.0);// 放射色
  vec3 ka = vec3(0.2, 0.2, 0.2);// 環境光
  ka = kColor * 0.7;
  vec3 kd = vec3(1.0, 1.0, 1.0);// 拡散反射
  kd = kColor * 0.8;
  vec3 ks = vec3(1.0, 1.0, 1.0);// 鏡面反射
  ks = kColor;
  float shine = 1.0;

  vec3 V = normalize(-vPosition.xyz); // 視線ベクトル
  vec3 N = normalize(vNormal); // 法線ベクトル
  //    vec3 L = normalize(invMatrix*vec4(lp - vPosition.xyz, 0.0)).xyz; // ライトベクトル
  vec3 L = vec3(0.0, 1000.0, 0.0);
  L = normalize(invMatrix*vec4(L, 0.0)).xyz;
  vec3 H = normalize(L+V); // ハーフベクトル

  // 放射色の計算
  vec3 emissive = ke;

  // 環境光の計算
  vec3 ambient = ka*la;

  // 拡散反射の計算
  float diffuseLight = dot(N, L);
  vec3 diffuse = kd*ld*diffuseLight;

  // 鏡面反射の計算
  vec3 specular = vec3(0.0);
  if(diffuseLight > 0.0) {
    // Cook-Trrance反射モデルの計算

    float NH = dot(N, H);
    float VH = dot(V, H);
    float NV = dot(N, V);
    float NL = dot(N, L);

    float alpha = acos(NH);

    // D:ベックマン分布関数
    float D = (1.0/(4.0*m*m*NH*NH*NH*NH))*exp((NH*NH-1)/(m*m*NH*NH));

    //G:幾何減衰
    float G = min(1, min((2*NH*NV)/VH, (2*NH*NL)/VH));

    // F:フレネル項
    float c = VH;
    float g = sqrt(refrac*refrac+c*c-1);
    float F = ((g-c)*(g-c)/((g+c)*(g+c)))*(1+(c*(g+c)-1)*(c*(g+c)-1)/((c*(g-c)-1)*(c*(g-c)-1)));

    float specularLight = D*G*F/NV;
    specular = ks*ls*specularLight;
  }

  vFragColor.rgb = emissive+ambient+diffuse+specular;
  vFragColor.a = 1.0;
}

// void main() {
//     vec3 lightDir = vec3(1000.0, 0.0, -1.0);
//     vec3 invLight = normalize(invMatrix * vec4(lightDir, 0.0)).xyz;
//     float diffuse = clamp(dot(vNormal, normalize(invLight)), 0.1, 1.0);
//     float specular = pow(diffuse, 5.0);
//     float light = dot(normalize(lightDir), vNormal);
//     vec3 color = vNormal;
//     vFragColor = vec4(color*diffuse+vec3(specular), 1.0);
// }
