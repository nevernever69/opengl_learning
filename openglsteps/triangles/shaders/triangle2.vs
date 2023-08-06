#version 330 core   //vertex shader
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 acolor;
out vec3 glcolor;
void main()
{
	gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);
	glcolor = acolor;
}
