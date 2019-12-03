#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform float time;

in vec4 position;
in vec2 texcoord;
in vec4 color;

out vec2 vTexCoord;
out vec4 vPosition;

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
    float n = noise(texcoord * 20.0);
    vec3 normal = normalize(position.xyz);
    vec3 newPos = position.xyz + normal * 100.0 * n * sin(time*10.0);
    vTexCoord = texcoord;
    vPosition = vec4(newPos, 1.0);
    gl_Position = modelViewProjectionMatrix * vec4(newPos, 1.0);
}
