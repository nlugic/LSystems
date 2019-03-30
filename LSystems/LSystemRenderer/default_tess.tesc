#version 450 core

layout (vertices = 4) out;

in vec3 vsVertNormal[];
in vec3 vsTexCoordinates[];
in float vsTransPointer[];

out vec3 tcsVertNormal[];
out vec3 tcsTexCoordinates[];
out float tcsTransPointer[];
out patch uint faceId;

uniform float outerX;
uniform float outerY;
uniform float innerX;
uniform float innerY;

void main()
{
	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;

	for (uint i = 0U; i < gl_PatchVerticesIn; ++i)
	{
		tcsVertNormal[i] = vsVertNormal[i];
		tcsTexCoordinates[i] = vsTexCoordinates[i];
		tcsTransPointer[i] = vsTransPointer[i];
	}

	faceId = gl_PrimitiveID % gl_PatchVerticesIn;

	gl_TessLevelOuter[0] = outerY;
	gl_TessLevelOuter[1] = outerX;
	gl_TessLevelOuter[2] = outerY;
	gl_TessLevelOuter[3] = outerX;

	gl_TessLevelInner[0] = innerY;
	gl_TessLevelInner[1] = innerX;
}
