#version 300 es
precision mediump float;

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

in vec4 normal;
in vec4 vertex;

out float color_factor;

uniform vec4 light_direction;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 matrixpmv;

void main(){
	TexCoords = aTexCoords;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	color_factor = max(dot(normal, light_direction), 0.0);
    gl_Position = matrixpmv * vertex;
}