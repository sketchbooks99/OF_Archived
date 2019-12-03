#version 150

uniform mat4 modelViewProjectionMatrix;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in Vertex {
  vec4 position;
  vec3 normal;
  vec2 texcoord;
  vec4 color;
} vertex[];

out vec3 vNormal;

void main() {
  for(int i=0; i<gl_in.length(); i++) {
    vNormal = vertex[i].normal;
    vec3 newVertex = gl_in[i].gl_Position.xyz;
    gl_Position = modelViewProjectionMatrix * vec4(newVertex,1.0);
    EmitVertex();
  }
  EndPrimitive();
}
