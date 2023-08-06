//trying to load two texture on each other
#include<iostream>
#include"glad/glad.h"
#include<SDL2/SDL.h>
#include"compileshader.h"
#include"stb/stb_image.h"

int main(){

	SDL_Window *window = SDL_CreateWindow("name",0,0,1080, 720, SDL_WINDOW_OPENGL );
	SDL_GLContext context = SDL_GL_CreateContext(window);
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	Shader ourshader("shaders/texture2.vs", "shaders/texture2.fs");

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
	unsigned int texture1;

	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
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


	unsigned int texture2;
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	data = stbi_load("gold.png", &width, &height, &nrchannel,0 );
	if(data){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,  0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else{
		std::cout << "failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	ourshader.use(); // don't forget to activate/use the shader before setting uniforms!
			 // either set it manually like so:
	/* ourshader.setInt("texture1",0); */
	glUniform1i(glGetUniformLocation(ourshader.program, "texture1"), 0);
	// or set it via the texture class
	ourshader.setInt("texture2", 1);


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

		 glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		 glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		ourshader.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(window);

	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);


}
