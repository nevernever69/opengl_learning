// g++ randomshape.cpp  -o randomshape src/glad.c -I /glad/glad.h  -lSDL2 -ldl
//just creates the three triangles that arae connected together
#include<iostream>
#include<SDL2/SDL.h>
#include"glad/glad.h"
#include<string>

	
const char *vertexshadersource = "#version 330 core\n"
	"layout (location = 0) in vec aPos\n"
	"void main()\n"
	"{\n"
	" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0)\n"
	"}\0";
const char *fragmentshadersource = "#version 330 core\n"
	"out vec4 FragColor;\n"
	"void main()\n"
	"{\n"
	" FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
	"}\n\0";

const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 800;

int main(){
	SDL_Window* window  = SDL_CreateWindow("line", 0, 0, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL);
	if(window==NULL){
		std::cout<<"cannot creat window";
	}
	SDL_GLContext context = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	unsigned int vertexshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexshader, 1, &vertexshadersource, NULL);
	glCompileShader(vertexshader);
	unsigned int fragmentshader= glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentshader, 1, &fragmentshadersource, NULL);
	glCompileShader(fragmentshader);

	GLuint program = glCreateProgram();

	glAttachShader(program, vertexshader);
	glAttachShader(program, fragmentshader);
	glLinkProgram(program);

	GLuint VAO,VBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	float vertices[] = {-0.5f, -0.5f,
		            0.5f, 0.5f,
			    0.5f, -0.5f,
			   
			    0.5f, 0.5f,
			    -0.5f,-0.5f,
			    -0.5f, 0.5f,

			    -0.5f, -0.5f,
			    0.5f, 0.5f,
			    1.0f, -1.0f,

			   

				};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0,2, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	/* glBindBuffer(GL_ARRAY_BUFFER, 0); */
	/* glBindVertexArray(0); */
	
	SDL_Event event;
	bool quite=  false;
	while(!quite){
		while(SDL_PollEvent(&event)!=0){
			if(event.type==SDL_QUIT){

				quite =true;
			}
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glUseProgram(program);
			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 9);
			SDL_GL_SwapWindow(window);	

			


		}
		
	}
	glDeleteBuffers(1,&VBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(program);
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

}


