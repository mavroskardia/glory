#version 150

in vec3 Color;
in vec2 Texcoord;

out vec4 outColor;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform int time;

void main()
{
    vec4 colTex0 = texture(tex0, Texcoord);
    vec4 colTex1 = texture(tex1, Texcoord);

    float factor = time * 0.01;

    if (Texcoord.y < 0.5) {
        // outColor = mix(colTex0, colTex1, factor);
        outColor = colTex0;
    } else {
        outColor = texture(
            tex0,
            vec2(Texcoord.x + sin(time) * 0.01, 1.0 - Texcoord.y)
            ) * vec4(0.7, 0.7, 1.0, 1.0);  // make it more blue
    }
}