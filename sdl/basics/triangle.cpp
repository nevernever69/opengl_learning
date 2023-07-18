// g++ triangle.cpp -o triangle src/glad.c -I /glad/glad.h  -lSDL2 -ldl
#include"glad/glad.h"
#include<iostream>
#include<SDL2/SDL.h>
//create a vertex shader first
const char *vertexShaderSource = "#version 330 core\n"   //vertex shader
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n" //fragmenet shader
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";



int main(){
	
	SDL_Window* createwindow = SDL_CreateWindow("start with triangle", 0, 0, 640, 480, SDL_WINDOW_OPENGL);

	SDL_GLContext context  = SDL_GL_CreateContext(createwindow);
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	GLuint vertexshader = glCreateShader(GL_VERTEX_SHADER);//create vertex shader
	glShaderSource(vertexshader, 1, &vertexShaderSource, NULL);// replace a source code in shader object
	glCompileShader(vertexshader);//it will compile a shader;

	//check if vertex shader compiled 
	GLint checkvertex;
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &checkvertex);
	if(checkvertex!=GL_TRUE){
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(vertexshader, 1024, &log_length, message);
	}



	GLuint fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);//create a fragment shader
	glShaderSource(fragmentshader, 1, &fragmentShaderSource, NULL);//replace a source code in shader object
	glCompileShader(fragmentshader);//compile the shader
	
	//check fragment shader compiled or not
	GLint checkfragment;
	glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &checkfragment);
	if(checkfragment!=GL_TRUE){
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(fragmentshader, 1024, &log_length, message);
	}

	int shaderprogram = glCreateProgram();//create a new program
	glAttachShader(shaderprogram, vertexshader);//attach the vertex shader 
	glAttachShader(shaderprogram, fragmentshader);//attach the fragment shader
	glLinkProgram(shaderprogram);//link the shaders with the program
	glDeleteShader(vertexshader);//delete the vertex shader that are linked 
	glDeleteShader(fragmentshader);//delete the fragment shader that are linked




/* 	float vertices[] = { */
/* 		0.0f, 0.5f, 0.0f, */
/* 		-0.5f, -0.5f, 0.0f, */
/* 		0.5f, -0.5f, 0.0f, */
/* 	}; */

float vertices[] = {
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.0f, -0.5f, 0.0f
	};//created vertex for a triangle


	GLuint VAO, VBO;//create Vertex array object and vertex buffer object
	//create a VAO vertex array object 
	glGenVertexArrays(1, &VAO);//gen vertex arrays
	//bind it means use it 
	glBindVertexArray(VAO);

	//create a VBO object
	glGenBuffers(1, &VBO);
	//use this VBO object
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);

	int running = true;

	SDL_Event event;
	while(running){

		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				running =false;

			}
	    /* glClearColor(1.0f, 1.0f, 0.1f, 1.0f); */
			glClear(GL_COLOR_BUFFER_BIT);


		}

		glUseProgram(shaderprogram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		SDL_GL_SwapWindow(createwindow);

	}
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    /* glDeleteBuffers(1, &EBO); */
    glDeleteProgram(shaderprogram);
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(createwindow);
    SDL_Quit();



}
