#version 150
precision mediump float;

uniform float time;
in vec2 vTexCoord;
in vec4 vColor;
in vec4 vPosition;

out vec4 vFragColor;

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
    
    float n = noise(vTexCoord * 20.0);
    
    vec3 color;
//    if(n > 0.5) {
//        color = vec3(smoothstep(0.0, n, vTexCoord.x), 0.1, 0.1);
//    } else {
//        color = vec3(n);
//    }
    color = vec3(n);
    color += vec3(0.5, 0.1, 0.1);
    
    vFragColor = vec4(color, 1.0);
}
