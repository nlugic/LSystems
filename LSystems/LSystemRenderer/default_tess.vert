#version 460 core

layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec3 v_norm;
layout (location = 2) in vec3 t_coord;
layout (location = 3) in float tr_ind;

out vec3 vs_vert_normal;
out vec3 vs_tex_coords;
out float vs_trans_index;

void main()
{
	vs_vert_normal = v_norm;
	vs_tex_coords = t_coord;
	vs_trans_index = tr_ind;

	gl_Position = vec4(v_pos, 1.0f);
}
