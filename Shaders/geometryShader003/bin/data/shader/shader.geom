#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform vec2 resolution;
uniform float time;
uniform float strength;
uniform float border;

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in Vertex {
    vec2 texcoord;
    vec4 color;
    vec4 normal;
} vertex[];

out vec4 vColor;
out vec2 vTexCoord;

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
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
    vec3 center = vec3(gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) / 3.0;
    vec3 normal = normalize(cross(b, a));
    
    vec2 texCoord = vertex[0].texcoord;
    float n = noise((vec2(texCoord.x + time * 600.0, texCoord.y)/resolution)*10.0);
    for(int i = 0; i < gl_in.length(); i++) {
        vec3 newVertex;
        if(n > border) {
            newVertex = gl_in[i].gl_Position.xyz + normal * n * strength;
        } else {
            newVertex = gl_in[i].gl_Position.xyz;
        }
        gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);
        
//        vColor = vertex[i].color;
        vColor = vec4(texCoord, 1.0, 1.0);
        vTexCoord = vertex[i].texcoord;
        EmitVertex();
    }
    EndPrimitive();
}
