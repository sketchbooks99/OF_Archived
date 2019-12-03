#version 150
precision mediump float;

in vec4 color;
in vec2 texcoord;
in vec4 position;
in vec4 normal;

out Vertex {
    vec4 color;
    vec2 texcoord;
    vec4 normal;
} vertex;

void main() {
    gl_Position = position;
    vertex.color = color;
    vertex.texcoord = texcoord;
    vertex.normal = normal;
}
