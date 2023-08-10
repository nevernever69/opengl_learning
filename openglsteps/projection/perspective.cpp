//trying to add perspective 
#include<iostream>
#include"glad/glad.h"
#include<SDL2/SDL.h>
#include"compileshader.h"
#include"stb/stb_image.h"
#include"glm/glm.hpp"
#include"glm/gtc/matrix_transform.hpp"
#include"glm/gtc/type_ptr.hpp"

float input(float updater, int flag ){
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	
	if(state[SDL_SCANCODE_UP] && flag == 0){
		updater+=0.09f;
		return updater;
	}
	if(state[SDL_SCANCODE_DOWN] && flag == 0){
		updater-=0.09f;
		return updater;
	}
	if(state[SDL_SCANCODE_LEFT] && flag == 1){
		updater+=0.1f;
		return updater;
	}
	if(state[SDL_SCANCODE_RIGHT] && flag == 1){
		updater-=0.1f;
		return updater;
	}

	return updater;

}

int main(){

	SDL_Window *window = SDL_CreateWindow("name",0,0,1080, 720, SDL_WINDOW_OPENGL );
	SDL_GLContext context = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	Shader ourshader("shaders/perspective.vs", "shaders/perspective.fs");

	float vertices[] = {
		0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  // top right
		0.5f, -0.5f, 0.0f, 1.0f,0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};


	GLuint VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	glBindVertexArray(0);

	//textures
	unsigned int texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	int width, height, nrchannel;

	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load("de.png", &width, &height, &nrchannel,0 );
	if(data){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,  0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else{
		std::cout << "failed to load texture" << std::endl;
	}
	stbi_image_free(data);
	SDL_Event event;

	bool quit = true;
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the clear color to black

	float updater = 0.0f;
	float updater1 = 0.0f;
	float updater2 = 0.0f;
	ourshader.use();
	while(quit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				quit=false;
			}

		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glBindTexture(GL_TEXTURE_2D, texture);
		//transformation
		updater = input(updater, 0);
		updater1 = input(updater1, 1);

		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::translate(transform, glm::vec3(0.0f,0.0f, updater));
		transform = glm::rotate(transform, updater1/*(GLfloat)SDL_GetTicks()/1000*/, glm::vec3(0.0f, 1.0f, 0.0f));
		
		ourshader.use();
		GLint transformLocation = glGetUniformLocation(ourshader.program, "transform");
		glUniformMatrix4fv(transformLocation, 1, GL_FALSE,glm::value_ptr(transform));
		
		glm::mat4 perspective = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 10.0f);
		GLint u_perspective = glGetUniformLocation(ourshader.program, "perspective");
		glUniformMatrix4fv(u_perspective, 1, GL_FALSE, glm::value_ptr(perspective));




		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(window);

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);


}
