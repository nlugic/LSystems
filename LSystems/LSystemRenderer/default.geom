#version 450 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 vNormal[];
in vec3 fPosition[];
in vec3 tCoordinates[];

out vec3 vertNormal;
out vec3 fragPosition;
out vec3 texCoordinates;
noperspective out vec3 edgeDistance;

uniform bool enableWireframe;
uniform vec3 viewport;

void main()
{
	float ha = 0.0f, hb = 0.0f, hc = 0.0f;

	if (enableWireframe)
	{
		vec3 v0 = viewport * vec3(gl_in[0].gl_Position / gl_in[0].gl_Position.w);
		vec3 v1 = viewport * vec3(gl_in[1].gl_Position / gl_in[1].gl_Position.w);
		vec3 v2 = viewport * vec3(gl_in[2].gl_Position / gl_in[2].gl_Position.w);

		float a = length(v1 - v2), b = length(v2 - v0), c = length(v1 - v0);
		float s = (a + b + c) / 2.0f, PP = 2.0f * sqrt(s * (s - a) * (s - b) * (s - c));
		ha = PP / a; hb = PP / b; hc = PP / c;
	}
	
	edgeDistance = vec3(ha, 0.0f, 0.0f);
	vertNormal = vNormal[0];
	fragPosition = fPosition[0];
	texCoordinates = tCoordinates[0];
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	
	edgeDistance = vec3(0.0f, hb, 0.0f);
	vertNormal = vNormal[1];
	fragPosition = fPosition[1];
	texCoordinates = tCoordinates[1];
	gl_Position = gl_in[1].gl_Position;
	EmitVertex();
	
	edgeDistance = vec3(0.0f, 0.0f, hc);
	vertNormal = vNormal[2];
	fragPosition = fPosition[2];
	texCoordinates = tCoordinates[2];
	gl_Position = gl_in[2].gl_Position;
	EmitVertex();

	EndPrimitive();
}
