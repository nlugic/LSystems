#version 450 core

struct Light
{
	vec4 position;
	vec3 attenuation;
	vec3 ambient, diffuse, specular;
	float shininess;
};

in vec3 vertNormal;
in vec3 fragPosition;
in vec3 texCoordinates;
noperspective in vec3 edgeDistance;

layout (location = 0) out vec4 gl_FragColor;

uniform bool enableWireframe;
uniform vec3 viewPosition;
uniform Light light;

layout (binding = 0) uniform sampler2DArray textures;

void main()
{
	vec3 color = (texCoordinates.z < 0.0f) ? vec3(texCoordinates.xy, -texCoordinates.z) : texture(textures, texCoordinates).rgb;

	vec3 ambient = light.ambient * color;

	vec3 normalizedNormal = normalize(vertNormal);
	vec3 lightDirection = normalize((light.position.w) ? light.position.xyz - fragPosition : light.position.xyz);
	vec3 diffuse = light.diffuse * max(dot(normalizedNormal, lightDirection), 0.0f) * color;

	vec3 viewDirection = normalize(viewPosition - fragPosition);
	vec3 reflectionDirection = reflect(-lightDirection, normalizedNormal);
	vec3 specular = light.specular * pow(max(dot(viewDirection, reflectionDirection), 0.0f), light.shininess) * color;

	float distanceToFragment = (light.position.w) ? length(light.position.xyz - fragPosition) : 0.0f;
	float lightAttenuation = 1.0f / (light.attenuation.x + light.attenuation.y * distanceToFragment
		+ light.attenuation.z * (distanceToFragment * distanceToFragment));

	gl_FragColor = vec4(lightAttenuation * (ambient + diffuse + specular), 1.0f);

	if (!enableWireframe)
		return;

	float minDistance = min(edgeDistance.x, edgeDistance.y);
	minDistance = min(minDistance, edgeDistance.z);

	float lineWidth = 0.25f;
	vec4 lineColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	gl_FragColor = mix(lineColor, gl_FragColor, smoothstep(lineWidth - 1.0f, lineWidth + 1.0f, minDistance));
}
