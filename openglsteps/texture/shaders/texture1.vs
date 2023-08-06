#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location =1 ) in vec2 atexcord;
out vec2 texcord;



void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f); // see how we directly give a vec3 to vec4's constructor
    texcord = vec2(atexcord);
}
