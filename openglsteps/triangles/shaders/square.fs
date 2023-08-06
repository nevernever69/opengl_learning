#version 330 core //fragmenet shader
out vec4 FragColor;
in vec3 glcolor; 
void main()
{
	FragColor =vec4(glcolor,1);
}

