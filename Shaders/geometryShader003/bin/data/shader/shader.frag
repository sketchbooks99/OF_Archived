#version 150
precision mediump float;

uniform sampler2DRect tex;

in vec2 vTexCoord;
in vec4 vColor;

out vec4 vFragColor;

void main() {
    vec3 p = texture(tex, vTexCoord).xyz;
    vFragColor = vec4(p, 1.0);
}
