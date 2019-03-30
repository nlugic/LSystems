#version 450 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vNorm;
layout (location = 2) in vec3 tCoord;
layout (location = 3) in float trPoint;

out vec3 vsVertNormal;
out vec3 vsTexCoordinates;
out float vsTransPointer;

void main()
{
	vsVertNormal = vNorm;
	vsTexCoordinates = tCoord;
	vsTransPointer = trPoint;

	gl_Position = vec4(vPos, 1.0f);
}
