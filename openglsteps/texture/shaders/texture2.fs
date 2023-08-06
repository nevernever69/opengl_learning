#version 330 core //fragmenet shader
out vec4 FragColor;
in vec2 texcoord;
uniform sampler2D texture1;
uniform sampler2D texture2;
void main()
{
   FragColor =mix(texture(texture1, texcoord),texture(texture2, texcoord), 0.4);
}

