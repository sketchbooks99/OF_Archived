#version 150
precision mediump float;

uniform sampler2DRect tex;
uniform mat4 modelViewProjectionMatrix;
uniform vec2 imgSize;
uniform float time;

in vec2 texcoord;
in vec4 color;
in vec4 position;

out vec4 vColor;
out vec2 vTexCoord;

void main() {
    vColor = texture(tex, texcoord);
//    vColor = vec4(texcoord, 1.0, 1.0);
    vec2 t = texcoord / imgSize;
    float z = abs(0.5 - t.x) * 100.0 * sin(time);
    vec4 p = vec4(position.xy, position.z + z, position.w);
    vTexCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * p;
}
