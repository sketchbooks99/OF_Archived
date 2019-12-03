v#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform samplerCube cubeTexture;
uniform vec3 eyePosition;
uniform float time;
uniform vec3 mousePos;

in vec3 vPosition;
in vec3 vNormal;

out vec4 outputColor;

void main() {
  vec3 lightDir = mousePos;
  vec3 invLight = normalize(inverse(modelViewProjectionMatrix)*vec4(lightDir,0.0)).xyz;
  vec3 invEye = normalize(inverse(modelViewProjectionMatrix)*vec4(vPosition - eyePosition,1.0)).xyz;
  vec3 halfLE = normalize(invLight + invEye);
  float diffuse = clamp(dot(vNormal,invLight),0.0,1.0);
  float specular = pow(clamp(dot(vNormal,halfLE),0.0,1.0),50.0);

  vec3 I = normalize(vPosition - eyePosition);
  vec3 R = reflect(I,normalize(vNormal)); // 反射
  vec3 ref = refract(I, normalize(vNormal), 0.1);
  vec3 envColor = texture(cubeTexture, R).rgb;
  // vec3 envColor = vec3(0.6);
  vec4 ambientColor = vec4(envColor*0.5,1.0);
  vec4 destColor = vec4(envColor,1.0) * vec4(vec3(diffuse),1.0)+vec4(vec3(specular),1.0)+ambientColor;

  outputColor = destColor;
}
