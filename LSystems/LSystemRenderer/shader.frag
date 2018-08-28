#version 450 core

in vec3 vertNormal;
in vec2 texCoordinate;
in float texPointer;

out vec4 gl_FragColor;

uniform sampler2D tex[16];

void main()
{
	gl_FragColor = texture(tex[int(texPointer)], texCoordinate);
}
