#version 460 core

#define PI 3.1415926538f

layout (quads, equal_spacing, cw) in;

in vec3 tcs_vert_normal[];
in vec3 tcs_tex_coords[];
in float tcs_trans_index[];
in patch uint face_id;

out vec3 tes_vert_normal;
out vec3 tes_frag_position;
out vec3 tes_tex_coords;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

layout (std430, binding = 0) buffer transform_data { mat4 transforms[]; };

void main()
{
	float u = gl_TessCoord.x;
	float v = gl_TessCoord.y;

	vec3 v0 = gl_in[0].gl_Position.xyz;
	vec3 v1 = gl_in[1].gl_Position.xyz;
	vec3 v2 = gl_in[2].gl_Position.xyz;
	vec3 v3 = gl_in[3].gl_Position.xyz;

	float r1 = length(v0 - v1) * sqrt(2.0f) / 2.0f, r2 = length(v2 - v3) * sqrt(2.0f) / 2.0f;
	float r = mix(r1, r2, v), s = length(v2 - v0), h = v2.y - v0.y;
	float angle = mix(face_id * PI / 2.0f, (face_id + 1u) * PI / 2.0f, u);
	
	vec3 vertex_position = vec3(r * cos(angle), mix(v0.y, v2.y, v), r * sin(angle));
	vec3 vertex_normal = vec3(cos(angle) * h / s, (r1 - r2) / s, sin(angle) * h / s);
	vec2 texture_coordinates = vec2((face_id + u) * 0.25f, v);

	mat4 combined_model = model * transforms[uint(tcs_trans_index[0])];

	tes_vert_normal = mat3(transpose(inverse(combined_model))) * vertex_normal;
	tes_frag_position = vec3(combined_model * vec4(vertex_position, 1.0f));
	tes_tex_coords = vec3(texture_coords, tcs_tex_coords[0].z);

	gl_Position = proj * view * vec4(tes_frag_position, 1.0f);
}
