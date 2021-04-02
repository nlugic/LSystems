#version 460 core

struct Light
{
	vec4 position;
	vec3 attenuation;
	vec3 ambient, diffuse, specular;
	float shininess;
};

in vec3 gs_vert_normal;
in vec3 gs_frag_position;
in vec3 gs_tex_coords;
noperspective in vec3 edge_distance;

layout (location = 0) out vec4 out_color;

uniform bool enable_wireframe;
uniform vec3 view_position;
uniform Light light;

layout (binding = 0) uniform sampler2DArray textures;

void main()
{
	vec3 color = (gs_tex_coords.z < 0.0f) ? vec3(gs_tex_coords.xy, -gs_tex_coords.z) : texture(textures, gs_tex_coords).rgb;

	vec3 ambient = light.ambient * color;

	vec3 normalized_normal = normalize(gs_vert_normal);
	vec3 light_direction = normalize((light.position.w) ? light.position.xyz - gs_frag_position : light.position.xyz);
	vec3 diffuse = light.diffuse * max(dot(normalized_normal, light_direction), 0.0f) * color;

	vec3 view_direction = normalize(view_position - gs_frag_position);
	vec3 reflection_direction = reflect(-light_direction, normalized_normal);
	vec3 specular = light.specular * pow(max(dot(view_direction, reflection_direction), 0.0f), light.shininess) * color;

	float distance_to_fragment = (light.position.w) ? length(light.position.xyz - gs_frag_position) : 0.0f;
	float light_attenuation = 1.0f / (light.attenuation.x + light.attenuation.y * distance_to_fragment
		+ light.attenuation.z * (distance_to_fragment * distance_to_fragment));

	gl_FragColor = vec4(light_attenuation * (ambient + diffuse + specular), 1.0f);

	if (!enable_wireframe)
		return;

	float min_distance = min(edge_distance.x, edge_distance.y);
	min_distance = min(min_distance, edge_distance.z);

	float line_width = 0.25f;
	vec4 line_color = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	out_color = mix(line_color, gl_FragColor, smoothstep(line_width - 1.0f, line_width + 1.0f, min_distance));
}
