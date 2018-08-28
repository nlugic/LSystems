#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;
layout (location = 2) in vec2 tCoord;
layout (location = 3) in float tPoint;

out vec3 vertNormal;
out vec2 texCoordinate;
out float texPointer;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = proj * view * model * vec4(vPos, 1.0f);
	vertNormal = vec3(model * vec4(vNorm, 1.0f));
	texCoordinate = tCoord;
	texPointer = tPoint;
}
