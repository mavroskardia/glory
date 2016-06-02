#version 150

uniform vec3 triangleColor;

out vec4 outColor;

void main()
{
	// output only white for the moment
    outColor = vec4(triangleColor, 1.0);
}