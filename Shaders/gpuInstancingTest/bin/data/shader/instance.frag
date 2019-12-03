#version 150
precision mediump float;

in vec3 vNormal;

out vec4 outputColor;

const vec3 lightDir = vec3(10.0, 10.0, 0.0);

void main(){
  float diffuse = dot(normalize(lightDir), vNormal);
  float specular = pow(diffuse, 1.0);
  vec3 color = vec3(0.2, 0.4, 0.8);
  outputColor = vec4(color*diffuse+vec3(specular), 1.0);
}
