#version 150
precision mediump float;

in vec4 normal;
in vec4 position;
in vec4 color;
in vec2 texcoord;

out Vertex {
    vec4 color;
    vec2 texcoord;
    vec4 normal;
} vertex;
out int vIndex;

void main() {
    gl_Position = position;
    vertex.color = color;
    vertex.texcoord = texcoord;
    vertex.normal = normal;
    vIndex = gl_VertexID;
}
