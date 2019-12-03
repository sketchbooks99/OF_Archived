#version 150
precision mediump float;

uniform float time;
uniform float strength;
uniform vec3 dim; // x,y,z各成分の強さ
uniform mat4 mvpMatrix;
uniform bool isSkull;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in Vertex {
    vec4 color;
    vec2 texcoord;
    vec4 normal;
} vertex[];
in int vIndex[];

out vec4 vColor;
out vec2 vTexCoord;
out vec3 vNormal;
out vec4 vPosition;

void main() {
    vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
    vec3 normal = normalize(cross(a, b));

    for(int i = 0; i < gl_in.length(); i++){
        vec3 newVertex;
        if(isSkull) {
          // newVertex = gl_in[i].gl_Position.xyz + normal * sin(time*3.0 + vIndex[0]) * strength * dim;
          newVertex = gl_in[i].gl_Position.xyz + normal * sin(time*3.0+vIndex[0]) * mod(time, 1.0) * 10.0;
        } else {
          newVertex = gl_in[i].gl_Position.xyz;
        }
        gl_Position = vPosition = mvpMatrix * vec4(newVertex, 1.0);
        vColor = vertex[i].color;
        vTexCoord = vertex[i].texcoord;
//        vNormal = normal;
        vNormal = vertex[i].normal.xyz;

        EmitVertex();
    }
    EndPrimitive();
}
