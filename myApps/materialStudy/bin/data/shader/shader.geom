#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform float time;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in Vertex {
    vec4 color;
    vec2 texcoord;
    vec4 normal;
} vertex[];

out vec2 vTexCoord;
out vec4 vColor;
out vec3 vNormal;

void main() {
    vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
    vec3 normal = normalize(cross(b, a));
    
    vec2 texCoord = vertex[0].texcoord;
    for(int i = 0; i < gl_in.length(); i++) {
        vec3 newVertex = gl_in[i].gl_Position.xyz + normal * -abs(sin(time*texCoord.x)) * 150.0;
        gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
        
        vTexCoord = vertex[1].texcoord;
        vColor = vertex[0].color;
        vNormal = normal;
        EmitVertex();
    }
    EndPrimitive();
}

