#version 150
precision mediump float;

uniform float time;
uniform vec2 resolution;
uniform vec3 light1;
uniform vec3 rotate;
uniform vec3 lightColor;

in vec4 vColor;
in vec2 vTexCoord;
in vec3 vNormal;

out vec4 vFragColor;

void main() {
    vec3 l1 = normalize(light1 + rotate);
    
    vec4 color = vec4(0.8, 0.8, 0.8, 1.0);
    
    vec4 diffuseColor = vec4(vec3(dot(vNormal, l1))*color.rgb*lightColor, color.a);
    
    vFragColor = diffuseColor;
    
    
}
