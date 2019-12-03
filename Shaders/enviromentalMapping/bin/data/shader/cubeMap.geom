#version 150

layout(triangles) in;
layout(triangle_strip,max_vertices=3) out;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelMatrix;
uniform float time;

in Vertex {
  vec3 position;
  vec3 normal;
}vertex[];

out vec3 vPosition;
out vec3 vNormal;

void main() {
  vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
  vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
  vec3 normal = normalize(cross(b,a));
  for(int i=0; i<gl_in.length(); i++) {
    gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
    vPosition = vec3(modelMatrix * vec4(vertex[i].position,1.0));
    vNormal = normal; // もしかしたらvertexでモデル座標変換行列をかけていたからおかしい法線になったのかも
    EmitVertex();
  }
  EndPrimitive();
}
