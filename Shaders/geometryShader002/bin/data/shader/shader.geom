#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform float time;

layout(triangles) in;
layout(triangle_strip, max_vertices = 6) out;

const float PI = 3.14;

in Vertex {
    vec4 color;
    vec4 normal;
    vec2 texcoord;
} vertex[];

out vec2 vTexCoord;
out vec4 vColor;

float random(in vec2 st) {
    return fract(sin(dot(st.xy, vec2(12.9898, 78.233))) * 43758.543123);
}

float noise(in vec2 st) {
    vec2 i = floor(st);
    vec2 f = fract(st);
    
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));
    
    vec2 u = f*f*(3.0-2.0*f);
    
    return mix(a,b,u.x) + (c-a)*u.y*(1.0-u.x) + (d-b)*u.x*u.y;
}

void main() {
    vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[1].gl_Position);
    vec3 center = vec3(gl_in[0].gl_Position + gl_in[0].gl_Position + gl_in[0].gl_Position) / 3.0;
    vec3 normal = normalize(cross(b, a));
    
    vec2 texCoord = vertex[0].texcoord;
    vec3 newVertex;
//    for(int i = 0; i < gl_in.length(); i++) {
//        newVertex = gl_in[i].gl_Position.xyz;
//        gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
//
//        vTexCoord = vertex[i].texcoord;
//        vColor = vec4(texCoord * length(newVertex)*0.003, 0.0, 1.0);
////        vColor = vec4(1.0, 1.0, 1.0, 1.0);
//        EmitVertex();
//    }
//    EndPrimitive();

    for(int i = 0; i < gl_in.length(); i++) {
        float n = noise(texCoord * 15.0) * abs(sin(time * 10.0 + texCoord.x * 20.0) * 200.0);
        if(n > 100.0) {
            newVertex = gl_in[i].gl_Position.xyz + normal * n;
        } else {
            newVertex = gl_in[i].gl_Position.xyz;
        }
        gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
        
        vTexCoord = vertex[i].texcoord;
        vColor = vec4(texCoord * length(newVertex)*0.003, 0.0, 1.0);
//        vColor = vertex[i].color;
        EmitVertex();
    }
    EndPrimitive();
}
