#version 450 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 tesVertNormal[];
in vec3 tesFragPosition[];
in vec3 tesTexCoordinates[];

out vec3 gsVertNormal;
out vec3 gsFragPosition;
out vec3 gsTexCoordinates;
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
	gsVertNormal = tesVertNormal[0];
	gsFragPosition = tesFragPosition[0];
	gsTexCoordinates = tesTexCoordinates[0];
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	
	edgeDistance = vec3(0.0f, hb, 0.0f);
	gsVertNormal = tesVertNormal[1];
	gsFragPosition = tesFragPosition[1];
	gsTexCoordinates = tesTexCoordinates[1];
	gl_Position = gl_in[1].gl_Position;
	EmitVertex();
	
	edgeDistance = vec3(0.0f, 0.0f, hc);
	gsVertNormal = tesVertNormal[2];
	gsFragPosition = tesFragPosition[2];
	gsTexCoordinates = tesTexCoordinates[2];
	gl_Position = gl_in[2].gl_Position;
	EmitVertex();

	EndPrimitive();
}
