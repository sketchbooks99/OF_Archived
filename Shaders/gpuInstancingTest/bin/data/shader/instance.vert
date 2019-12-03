#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 scaleMatrix;
uniform float time;

in vec4 color;
in vec4 position;
in vec4 normal;
in vec2 texcoord;

out vec4 vPosition;
out vec3 vNormal;
out vec2 vTexCoord;
out vec4 vColor;

out Vertex {
  vec4 position;
  vec3 normal;
  vec2 texcoord;
  vec4 color;
} vertex;

mat4 rotationMatrix(vec3 axis, float angle)
{
    axis = normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;

    return mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
                0.0,                                0.0,                                0.0,                                1.0);
}

void main() {
  int id = gl_InstanceID;
  // mat4 scaleMatrix = mat4(
  //   abs(sin(time+id*0.489))*50.0, 0.0, 0.0, 0.0,
  //   0.0, 1.0, 0.0, 0.0,
  //   0.0, 0.0, 1.0, 0.0,
  //   0.0, 0.0, 0.0, 1.0
  // );
  vec3 axis = normalize(vec3(sin(id*0.678), cos(id*0.489), sin(id*0.783)));
  mat4 rotateMatrix = rotationMatrix(axis, time*0.1+gl_InstanceID*0.239);
  vec3 newPos = position.xyz;

  newPos += vec3(sin(time)*cos(time*2.0+id)*id*0.01, sin(time)*sin(time*2.0+id)*id*0.01, cos(time)*id*0.01);
  gl_Position = /*rotateMatrix */scaleMatrix * vec4(newPos, 1.0);
  vertex.position = position;
  vertex.normal = normal.xyz;
}
