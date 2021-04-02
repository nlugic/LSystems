#version 460 core

layout (vertices = 4) out;

in vec3 vs_vert_normal[];
in vec3 vs_tex_coords[];
in float vs_trans_index[];

out vec3 tcs_vert_normal[];
out vec3 tcs_tex_coords[];
out float tcs_trans_index[];
out patch uint face_id;

uniform float outer_x;
uniform float outer_y;
uniform float inner_x;
uniform float inner_y;

void main()
{
	gl_out[gl_InvocationID].gl_Position = gl_in[gl_InvocationID].gl_Position;

	for (uint i = 0u; i < gl_PatchVerticesIn; ++i)
	{
		tcs_vert_normal[i] = vs_vert_normal[i];
		tcs_tex_coords[i] = vs_tex_coords[i];
		tcs_trans_index[i] = vs_trans_index[i];
	}

	face_id = gl_PrimitiveID % gl_PatchVerticesIn;

	gl_TessLevelOuter[0] = outer_y;
	gl_TessLevelOuter[1] = outer_x;
	gl_TessLevelOuter[2] = outer_y;
	gl_TessLevelOuter[3] = outer_x;

	gl_TessLevelInner[0] = inner_y;
	gl_TessLevelInner[1] = inner_x;
}
