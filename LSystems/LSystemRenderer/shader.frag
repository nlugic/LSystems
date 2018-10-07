#version 450 core

struct Light
{
	vec3 position, attenuation;
	vec3 ambient, diffuse, specular;
	float shininess;
};

in vec3 vertNormal;
in vec3 fragPosition;
in vec3 texCoordinate;

out vec4 gl_FragColor;

uniform vec3 viewPosition;
uniform Light light;

layout (binding = 0) uniform sampler2DArray textures;
uniform int texLayers;

void main()
{
	vec3 ambient = light.ambient * texture(textures, texCoordinate).rgb;

	vec3 normalizedNormal = normalize(vertNormal);
	vec3 lightDirection = normalize(light.position - fragPosition);
	vec3 diffuse = light.diffuse * max(dot(normalizedNormal, lightDirection), 0.0f)
		* texture(textures, texCoordinate).rgb;

	vec3 viewDirection = normalize(viewPosition - fragPosition);
	vec3 reflectionDirection = reflect(-lightDirection, normalizedNormal);
	vec3 specular = light.specular * pow(max(dot(viewDirection, reflectionDirection), 0.0f), light.shininess)
		* texture(textures, texCoordinate).rgb;

	float distanceToFragment = length(light.position - fragPosition);
	float lightAttenuation = 1.0f / (light.attenuation.x + light.attenuation.y * distanceToFragment
		+ light.attenuation.z * (distanceToFragment * distanceToFragment));

	gl_FragColor = vec4(lightAttenuation * (ambient + diffuse + specular), 1.0f);
}
