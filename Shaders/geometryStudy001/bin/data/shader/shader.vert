#version 150
precision mediump float;

in vec4 position;
in vec2 texcoord;
in vec4 color;
in vec4 normal;

out Vertex {
    vec4 normal;
    vec2 texCoord;
    vec4 color;
} vertex;

void main() {
    gl_Position = position;
    vertex.texCoord = texcoord;
    vertex.color = color;
    vertex.normal = normal;
}
