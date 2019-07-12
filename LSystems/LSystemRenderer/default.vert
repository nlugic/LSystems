#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;
layout (location = 2) in vec3 tCoord;
layout (location = 3) in float trInd;

out vec3 vertNormal;
out vec3 fragPosition;
out vec3 texCoordinates;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transformData
{
	mat4 transforms[];
};

void main()
{
	mat4 combinedModel = model * transforms[uint(trInd)];

	vertNormal = mat3(transpose(inverse(combinedModel))) * vNorm;
	fragPosition = vec3(combinedModel * vec4(vPos, 1.0f));
	texCoordinates = tCoord;

	gl_Position = proj * view * vec4(fragPosition, 1.0f);
}
