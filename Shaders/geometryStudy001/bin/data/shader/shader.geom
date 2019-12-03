#version 150
precision mediump float;

#define SPEED 5.0
#define OFFSET 20.0

layout(triangles) in;
layout(triangle_strip) out;
layout(max_vertices = 3) out;

uniform float time;
uniform mat4 modelViewProjectionMatrix;

float PI = 3.14;

in Vertex {
    vec4 normal;
    vec4 color;
    vec2 texCoord;
} vertex[];

out vec2 vTexCoord;
out vec4 vColor;

float m;
float n;

void main() {
    vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
    vec3 center = vec3(gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) / 3.0;
    vec3 normal = normalize(cross(b, a));

    for(int j = 0; j < gl_in.length(); j++) {
        vec3 newVertex;
        m = 10.0 * abs(sin(time * PI + vertex[j].texCoord.x * PI));
        n = 1.0;
        vec3 strength = center + normalize(center)*abs(sin(time * PI + (vertex[j].texCoord.x * PI))) * 50.0;
        
//        newVertex = normal * cos(time * SPEED + gl_in[j].gl_Position.x) * OFFSET + vec3(gl_in[j].gl_Position.xyz);
        newVertex = (gl_in[j].gl_Position.xyz*m + center*n) / (m + n); // 内分点
        newVertex = normalize(newVertex)*length(strength);
        gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
        
        vTexCoord = vertex[j].texCoord;
        vColor = vertex[j].color;
        EmitVertex();
    }
    EndPrimitive();
}
