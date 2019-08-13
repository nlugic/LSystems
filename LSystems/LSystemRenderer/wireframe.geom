#version 460 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 tes_vert_normal[];
in vec3 tes_frag_position[];
in vec3 tes_tex_coords[];

out vec3 gs_vert_normal;
out vec3 gs_frag_position;
out vec3 gs_tex_coords;
noperspective out vec3 edge_distance;

uniform bool enable_wireframe;
uniform vec3 viewport;

void main()
{
	float ha = 0.0f, hb = 0.0f, hc = 0.0f;

	if (enable_wireframe)
	{
		vec3 v0 = viewport * vec3(gl_in[0].gl_Position / gl_in[0].gl_Position.w);
		vec3 v1 = viewport * vec3(gl_in[1].gl_Position / gl_in[1].gl_Position.w);
		vec3 v2 = viewport * vec3(gl_in[2].gl_Position / gl_in[2].gl_Position.w);

		float a = length(v1 - v2), b = length(v2 - v0), c = length(v1 - v0);
		float s = (a + b + c) / 2.0f, PP = 2.0f * sqrt(s * (s - a) * (s - b) * (s - c));
		ha = PP / a; hb = PP / b; hc = PP / c;
	}
	
	edge_distance = vec3(ha, 0.0f, 0.0f);
	gs_vert_normal = tes_vert_normal[0];
	gs_frag_position = tes_frag_position[0];
	gs_tex_coords = tes_tex_coords[0];
	gl_Position = gl_in[0].gl_Position;
	EmitVertex();
	
	edge_distance = vec3(0.0f, hb, 0.0f);
	gs_vert_normal = tes_vert_normal[1];
	gs_frag_position = tes_frag_position[1];
	gs_tex_coords = tes_tex_coords[1];
	gl_Position = gl_in[1].gl_Position;
	EmitVertex();
	
	edge_distance = vec3(0.0f, 0.0f, hc);
	gs_vert_normal = tes_vert_normal[2];
	gs_frag_position = tes_frag_position[2];
	gs_tex_coords = tes_tex_coords[2];
	gl_Position = gl_in[2].gl_Position;
	EmitVertex();

	EndPrimitive();
}
