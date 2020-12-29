#version 300 es
precision mediump float;


in vec2 TexCoords;
in float color_factor;

out vec4 FragColor;
out vec4 color;

uniform sampler2D texture_diffuse1;
uniform vec4 ambiant_color;

void main() {
	FragColor = texture(texture_diffuse1, TexCoords);
	color = color_factor * ambiant_color;
}