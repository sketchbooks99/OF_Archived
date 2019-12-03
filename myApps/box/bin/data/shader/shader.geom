#version 150
precision mediump float;

uniform float time;
uniform mat4 modelViewProjectionMatrix;

layout(triangles) in;
layout(triangle_strip, max_vertices = 9) out;

in Vertex {
    vec4 normal;
    vec4 color;
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
    vec3 center = vec3((gl_in[0].gl_Position + gl_in[1].gl_Position + gl_in[2].gl_Position) / 3.0); // 3点の中心
    vec3 a = vec3(gl_in[1].gl_Position - gl_in[0].gl_Position);
    vec3 b = vec3(gl_in[2].gl_Position - gl_in[0].gl_Position);
    vec3 normal = normalize(cross(b, a)); // ポリゴンの法線を取得
    
    int count = 0;
    
    for(int i = 0; i < gl_in.length(); i++) {
        for(int j = 0; j < gl_in.length(); j++) {
            int index = (j + count) % 3;
            vec3 newVertex;
            if(j < gl_in.length() - 1) {
                newVertex = (gl_in[index].gl_Position.xyz * 19.0 + center) / 20.0;
            } else {
                vec2 texCoord = vertex[0].texcoord;
                newVertex = center + normal * noise(texCoord * 10.0 * mod(time, 1.0)) * 200.0;
            }
            gl_Position = modelViewProjectionMatrix * vec4(newVertex, 1.0);

            vTexCoord = vertex[index].texcoord;
            vColor = vertex[index].color;
            EmitVertex();
        }
        EndPrimitive();
        count++;
    }
    EndPrimitive();
}
