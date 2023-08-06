//load the triangle
#include<iostream>
#include<SDL2/SDL.h>
#include"compileshader.h"
#include"glad/glad.h"

int main(){

	SDL_Window *window = SDL_CreateWindow("name",0,0,1080, 720, SDL_WINDOW_OPENGL );
	SDL_GLContext context = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	Shader ourshader("shaders/triangle1.vs", "shaders/triangle1.fs");

	float vertices[] = {
		-0.5f,  -0.5f, 0.0f,  // top right
		0.0f, 0.5f, 0.0f,  // bottom right
		0.5f, -0.5f, 0.0f,  // bottom left
	};


	GLuint VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); 


	glBindVertexArray(0);


	SDL_Event event;

	bool quit = true;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the clear color to black

	while(quit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				quit=false;
			}

		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ourshader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		SDL_GL_SwapWindow(window);

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);


}
