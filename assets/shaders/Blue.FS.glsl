#version 330

// Input
in vec3 frag_color;

// Output
layout(location = 0) out vec4 out_color;


void main()
{
    out_color = vec4(vec3(0.1, 0.2, 0.8), 1);
}
