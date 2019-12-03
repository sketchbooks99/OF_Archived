#version 150

#pragma include "noise3D.glsl"
in vec4 position;
in vec4 normal;

out vec3 vNormal;
out vec3 vPosition;

// -- used geometry version --
// out Vertex {
//   vec3 position;
//   vec3 normal;
// } vertex;

uniform mat4 modelMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform float time;

// -- used geometry version --
// void main() {
//   // vNormal = mat3(transpose(inverse(modelMatrix))) * normal.xyz;
//   vertex.normal = normal.xyz;
//   float noise = snoise(vec3(position.xyz*0.00589)+vec3(sin(time*0.4),sin(time*0.9),cos(time*0.2)));
//   vec3 newVertex = position.xyz + normal.xyz * noise * 80.0;
//   // vertex.position = vec3(modelMatrix*vec4(newVertex,1.0));
//   // vertex.position = vec3(modelMatrix*vec4(position.xyz, 1.0));
//   vertex.position = position.xyz; // geomでvPositionを設定してね
//   gl_Position = vec4(newVertex, 1.0);
// }

void main() {
  float noise = snoise(vec3(position.xyz*0.004)+vec3(sin(time*0.4),sin(time*0.7),cos(time*0.2)));
  vec3 newVertex = position.xyz + normal.xyz * noise * 80.0;
  vPosition = newVertex;
  vNormal = normal.xyz;
  gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
}
