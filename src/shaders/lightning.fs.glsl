#version 300 es
precision mediump float;


in vec2 TexCoords;

out vec4 FragColor;

out vec4 color;

in float color_factor;

uniform sampler2D texture_diffuse1;

uniform vec3 objectColor;
uniform vec3 lightColor;

uniform vec4 ambiant_color;

void main() {
	FragColor = texture(texture_diffuse1, TexCoords);
	color = color_factor * ambiant_color;
	FragColor = vec4(lightColor * objectColor, 1.0);
}