#version 450 core

in float texPointer;
in vec2 texCoordinate;

out vec4 frColor;

uniform sampler2D tex[16];

void main()
{
	frColor = texture(tex[int(texPointer)], texCoordinate);
}
