#version 150
precision mediump float;

uniform mat4 modelViewProjectionMatrix;
uniform sampler2DRect posTex;
uniform sampler2DRect video;
uniform vec2 screen;

in vec2 texcoord;

out vec4 vColor;
out vec2 vTexCoord;

void main() {
    vec2 pos = texture(posTex, texcoord).xy;
    
//    vColor = vec4(pos.x, 1.0 - pos.y, 0.0, 1.0);
    vColor = vec4(1.0, 0.0, 0.8, 1.0);
    
    pos.x = pos.x * screen.x;
    pos.y = pos.y * screen.y;
    
    vTexCoord = texcoord;
    
    gl_Position = modelViewProjectionMatrix * vec4(pos, 0.0, 1.0);
}
