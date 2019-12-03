#version 150
precision mediump float;

uniform sampler2DRect tex;
uniform vec2 resolution;
uniform vec2 imgSize;
uniform float time;

in vec4 vColor;
in vec2 vTexCoord;
in vec4 vPosition;

out vec4 vFragColor;

void main() {
    vec4 p = texture(tex, vTexCoord);
    
    vec4 color;
    color = vec4(vec3(p.r), 1.0);
    if(p.b < 0.5 && p.r < 0.1 && p.g < 0.2) {
//        color = vec4(0.0, 0.5, 0.0, 0.5);
        discard;
    } else {
//        color += vec4(0.3, vec3(0.0));
    }
    
    
    vFragColor = color;
}
