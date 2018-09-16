#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;
layout (location = 2) in vec3 tCoord;
layout (location = 3) in float trPoint;

out vec3 vertNormal;
out vec3 texCoordinate;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transformData
{
	mat4 transforms[];
};

void main()
{
	int trPtr = int(trPoint);
	gl_Position = proj * view * transforms[trPtr] * model * vec4(vPos, 1.0f);
	vertNormal = mat3(transpose(inverse(transforms[trPtr] * model))) * vNorm;
	texCoordinate = tCoord;
}
