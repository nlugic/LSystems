#version 450 core

#define PI 3.1415926538

layout (quads, equal_spacing, cw) in;

in vec3 tcsVertNormal[];
in vec3 tcsTexCoordinates[];
in float tcsTransPointer[];
in patch uint faceId;

out vec3 tesVertNormal;
out vec3 tesFragPosition;
out vec3 tesTexCoordinates;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transformData
{
	mat4 transforms[];
};

void main()
{
	float u = gl_TessCoord.x;
	float v = gl_TessCoord.y;

	vec3 v0 = gl_in[0].gl_Position.xyz;
	vec3 v1 = gl_in[1].gl_Position.xyz;
	vec3 v2 = gl_in[2].gl_Position.xyz;
	vec3 v3 = gl_in[3].gl_Position.xyz;

	float r1 = length(v0 - v1) * sqrt(2.0f) / 2.0f, r2 = length(v2 - v3) * sqrt(2.0f) / 2.0f;
	float r = mix(r1, r2, v), s = length(v2 - v0), h = v2.y - v0.y;
	float angle = mix(faceId * PI / 2.0f, (faceId + 1U) * PI / 2.0f, u);
	
	vec3 vertexPosition = vec3(r * cos(angle), mix(v0.y, v2.y, v), r * sin(angle));
	vec3 vertexNormal = vec3(cos(angle) * h / s, (r1 - r2) / s, sin(angle) * h / s);
	vec2 textureCoordinates = vec2((faceId + u) * 0.25f, v);

	mat4 combinedModel = model * transforms[uint(tcsTransPointer[0])];

	tesVertNormal = mat3(transpose(inverse(combinedModel))) * vertexNormal;
	tesFragPosition = vec3(combinedModel * vec4(vertexPosition, 1.0f));
	tesTexCoordinates = vec3(textureCoordinates, tcsTexCoordinates[0].z);

	gl_Position = proj * view * vec4(tesFragPosition, 1.0f);
}
