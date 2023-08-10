#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1 ) in vec2 atexcord;
out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 texcord;

uniform mat4 transform;
uniform float updater;



void main()
{


	vec4 new_pos= transform * vec4(aPos, 1.0f); 
	gl_Position = vec4(new_pos.x, new_pos.y+updater, new_pos.z, new_pos.w);


	vertexColor = vec4(0.5, 0.0, 0.0, 1.0); 
	texcord = vec2(atexcord);
}
