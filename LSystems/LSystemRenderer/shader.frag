#version 450 core

out vec4 frColor;

uniform sampler2D tex;

void main()
{
	frColor = vec4(0.7f, 0.6f, 0.2f, 1.0f);
}
