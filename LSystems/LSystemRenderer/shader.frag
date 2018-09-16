#version 450 core

in vec3 vertNormal;
in vec3 texCoordinate;

out vec4 gl_FragColor;

layout (binding = 0) uniform sampler2DArray textures;
uniform int texLayers;

void main()
{
	float texIndex = max(0, min(texLayers - 1, floor(texCoordinate.z + 0.5f)));
	gl_FragColor = texture(textures, vec3(texCoordinate.xy, texIndex));
}
