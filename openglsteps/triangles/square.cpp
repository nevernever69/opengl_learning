//drawing a multiple coloured square 
//done created a square that is multi coloured
#include<iostream>
#include<SDL2/SDL.h>
#include"glad/glad.h"
#include<string>
#include"compileshader.h"

	


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
	SDL_Window* window  = SDL_CreateWindow("line", 0, 0, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_OPENGL);
	if(window==NULL){
		std::cout<<"cannot creat window";
	}
	SDL_GLContext context = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	Shader ourshader("shaders/square.vs", "shaders/square.fs");

	GLuint VAO,VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	
	float vertices[] = {-0.5f, -0.5f,0.0f,  1.0f,0.0f,0.0f,
		            0.5f, -0.5f,0.0f, 	0.0f, 1.0f, 0.0f,
			    0.5f,0.5f,0.0f,   	0.0f, 0.0f, 1.0f,
		            -0.5f,0.5f,0.0f, 	1.0f, 1.0f, 1.0f,
	};
	unsigned int indices[]  = {
		0,1,2,
		0, 3, 2,

	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE,6*sizeof(float), nullptr);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE,6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
	
	SDL_Event event;
	bool quite=  false;
	while(!quite){
		while(SDL_PollEvent(&event)!=0){
			if(event.type==SDL_QUIT){

				quite =true;
			}
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		



		}
			ourshader.use();
			glBindVertexArray(VAO);
			/* glDrawArrays(GL_TRIANGLES, 0, 6); */
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			SDL_GL_SwapWindow(window);	

			
		
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

}


