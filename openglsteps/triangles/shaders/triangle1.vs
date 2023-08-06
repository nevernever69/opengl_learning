#version 330 core
layout(location = 0) in vec3 Pos;
out vec4 glcolor;

void main(){
	gl_Position = vec4(Pos, 1.0f);
	glcolor = vec4(1.0,0.5,0.2,1.0);

}

