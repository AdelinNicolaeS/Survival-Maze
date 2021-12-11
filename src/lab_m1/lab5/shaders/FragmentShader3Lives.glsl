#version 330

in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_texture;
in vec3 frag_color;

in float Lives;

layout(location = 0) out vec4 out_color;


void main()
{
	// write pixel out color
	out_color = vec4(vec3(0, 204.0/256.0, 102.0/256.0), 1.f);
}