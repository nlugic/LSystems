#version 460 core

struct Light
{
	vec4 position;
	vec3 attenuation;
	vec3 ambient, diffuse, specular;
	float shininess;
};

in vec3 vert_normal;
in vec3 frag_position;
in vec3 tex_coords;

layout (location = 0) out vec4 out_color;

uniform vec3 view_position;
uniform Light light;

layout (binding = 0) uniform sampler2DArray textures;

void main()
{
	vec3 color = (tex_coords.z < 0.0f) ? vec3(tex_coords.xy, -tex_coords.z) : texture(textures, tex_coords).rgb;

	vec3 ambient = light.ambient * color;

	vec3 normalized_normal = normalize(vert_normal);
	vec3 light_direction = normalize((bool(light.position.w)) ? light.position.xyz - frag_position : light.position.xyz);
	vec3 diffuse = light.diffuse * max(dot(normalized_normal, light_direction), 0.0f) * color;

	vec3 view_direction = normalize(view_position - frag_position);
	vec3 reflection_direction = reflect(-light_direction, normalized_normal);
	vec3 specular = light.specular * pow(max(dot(view_direction, reflection_direction), 0.0f), light.shininess) * color;

	float distance_to_fragment = (bool(light.position.w)) ? length(light.position.xyz - frag_position) : 0.0f;
	float light_attenuation = 1.0f / (light.attenuation.x + light.attenuation.y * distance_to_fragment
		+ light.attenuation.z * (distance_to_fragment * distance_to_fragment));

	out_color = vec4(light_attenuation * (ambient + diffuse + specular), 1.0f);
}
