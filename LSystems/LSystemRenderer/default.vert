#version 460 core

layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec3 v_norm;
layout (location = 2) in vec3 t_coord;
layout (location = 3) in float tr_ind;

out vec3 vert_normal;
out vec3 frag_position;
out vec3 tex_coords;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transform_data { mat4 transforms[]; };

void main()
{
	mat4 combinedModel = model * transforms[uint(tr_ind)];

	vert_normal = mat3(transpose(inverse(combinedModel))) * v_norm;
	frag_position = vec3(combinedModel * vec4(v_pos, 1.0f));
	tex_coords = t_coord;

	gl_Position = proj * view * vec4(frag_position, 1.0f);
}
