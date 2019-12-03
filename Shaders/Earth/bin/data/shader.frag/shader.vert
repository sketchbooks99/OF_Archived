#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform float time;

in vec2 texcoord;
in vec4 color;
in vec4 position;

out vec2 vTexCoord;
out vec4 vColor;
out vec4 vPosition;

void main() {
    vec3 normal = normalize(position.xyz - vec3(0.0));
    vec3 p = position.xyz + normal * sin(time*3.0 + texcoord.x / 50.0) * 25.0 + normal * sin(time*4.0 + texcoord.y / 50.0) * 25.0;
    vColor = color;
    vTexCoord = texcoord;
//    vPosition = p;
    gl_Position = modelViewProjectionMatrix * vec4(p, 1.0);
}
