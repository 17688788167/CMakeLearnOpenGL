#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 texCoord;
void main()
{
    FragColor = vec4(texCoord,1.0f, 1.0f);
}