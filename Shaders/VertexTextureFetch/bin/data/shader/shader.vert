#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;

in vec2 texcoord;
in vec4 color;

uniform sampler2DRect posTex;
uniform vec2 screen;

out vec4 vColor;
out vec2 vTexCoord;

void main() {
//    vec2 p = vec2(
//        mod(gl_VertexID, screen.x) / screen.x,
//        floor(gl_VertexID / screen.x) / screen.y
//    );
    float c = gl_VertexID / (screen.y * screen.y);
    
    vec2 pixPos = texture(posTex, texcoord).xy;
    pixPos.x = pixPos.x * screen.x;
    pixPos.y = pixPos.y * screen.y;
    vColor = vec4(vTexCoord, 1.0, 1.0);
//    vec4 t = texture(posTex, p);
//    t.x *= screen.x;
//    t.y *= screen.y;
//    vColor = color;
    vColor = vec4(c, 1.0, 1.0, 1.0);
    gl_Position = modelViewProjectionMatrix * vec4(pixPos.xy, 0.0, 1.0);
}

