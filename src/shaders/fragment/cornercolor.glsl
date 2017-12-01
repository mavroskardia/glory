#version 150 core

in vec3 Color;
in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D tex0;

void main()
{
    vec4 texColor = texture(tex0, Texcoord);
    outColor = vec4(Color, 1.0) * texColor;
}