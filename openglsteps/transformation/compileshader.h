#include"glad/glad.h"
#include<fstream>
#include<sstream>
#include<string>
#include<iostream>


class Shader{
public:
	unsigned int program;
	Shader(const char* pathvertex, const char* pathfragment){
		std::ifstream in(pathvertex);
		std::ifstream intk(pathfragment);
		std::stringstream store;
		std::stringstream st;

		store << in.rdbuf();
		st << intk.rdbuf();
		in.close();
		intk.close();

		unsigned int vertex, fragment;
		std::string vertexcode = store.str();
		std::string fragmentcode= st.str();
		const char *vertexshader = vertexcode.c_str();
		const char *fragmentshader= fragmentcode.c_str();

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexshader, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragmentshader, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");


		program  = glCreateProgram();
		glAttachShader(program, vertex);
		glAttachShader(program, fragment);
		glLinkProgram(program);
		checkCompileErrors(program, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);



	}
	void use() 
	{ 
		glUseProgram(program); 
	}
	// utility uniform functions
	// ------------------------------------------------------------------------
	void setBool(const std::string &name, bool value) const
	{         
		glUniform1i(glGetUniformLocation(program, name.c_str()), (int)value); 
	}
	// ------------------------------------------------------------------------
	void setInt(const std::string &name, int value) const
	{ 
		glUniform1i(glGetUniformLocation(program, name.c_str()), value); 
	}
	// ------------------------------------------------------------------------
	void setFloat(const std::string &name, float value) const
	{ 
		glUniform1f(glGetUniformLocation(program, name.c_str()), value); 
	}


private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}


};
