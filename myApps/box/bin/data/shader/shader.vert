#version 150
precision mediump float;

in vec4 position;
in vec2 texcoord;
in vec4 normal;
in vec4 color;

out Vertex{
    vec4 normal;
    vec4 color;
    vec2 texcoord;
} vertex;

void main() {
    gl_Position = position;
    vertex.normal = normal;
    vertex.color = color;
    vertex.texcoord = texcoord;
}
