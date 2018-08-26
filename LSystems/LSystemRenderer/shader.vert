#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 tCoord;
layout (location = 2) in float tPoint;

out float texPointer;
out vec2 texCoordinate;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = proj * view * model * vec4(vPos, 1.0f);
	texPointer = tPoint;
	texCoordinate = tCoord;
}
