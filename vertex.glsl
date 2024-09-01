#version 330 core
layout (location = 0) in vec3 localPos
uniform mat4 worldPos;
uniform mat4 view;
uniform mat4 perspective;

void main()
{
    gl_Position = perspective * vec4(localPos.x, localPos.y, localPos.z, 1.0);
}