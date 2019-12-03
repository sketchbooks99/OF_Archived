#version 150
precision mediump float;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

uniform mat4 modelViewProjectionMatrix;
uniform float time;
uniform vec3 dim; // x,y,zの各成分の強さ
uniform float strength;
uniform bool isGround;

in Vertex {
  vec4 color;
  vec2 texcoord;
  vec4 normal;
} vertex[];
in int vIndex[];

out vec2 vTexCoord;
out vec4 vColor;
out vec3 vNormal;

void main() {
  vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
  vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
  vec3 normal = normalize(cross(b, a));
  vNormal = normal;

  for(int i = 0; i < gl_in.length(); i++) {
    vec3 newVertex;
    if(isGround) {
      newVertex = gl_in[i].gl_Position.xyz + normal * sin(time*10.0+vIndex[0])*dim*strength*2.0;
    } else {
      newVertex = gl_in[i].gl_Position.xyz;
    }
    gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
    vColor = vertex[0].color;
    vTexCoord = vertex[i].texcoord;

    EmitVertex();
  }
  EndPrimitive();
}
