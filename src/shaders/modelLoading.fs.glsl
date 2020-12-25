#version 300 es
precision mediump float;

out vec4 fFragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{
	fFragColor = texture(texture_diffuse1, TexCoords);
}