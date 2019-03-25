#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;
layout (location = 2) in vec3 tCoord;
layout (location = 3) in float trPoint;

out vec3 vNormal;
out vec3 fPosition;
out vec3 tCoordinates;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transformData
{
	mat4 transforms[];
};

void main()
{
	mat4 combinedModel = model * transforms[uint(trPoint)];

	vNormal = mat3(transpose(inverse(combinedModel))) * vNorm;
	fPosition = vec3(combinedModel * vec4(vPos, 1.0f));
	tCoordinates = tCoord;

	gl_Position = proj * view * vec4(fPosition, 1.0f);
}
