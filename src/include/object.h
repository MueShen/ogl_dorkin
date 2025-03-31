#pragma once
#include "renderer.h"
#include <vector>

class gObject{

	public:
		unsigned int VBO, VAO, EBO;
		unsigned int vertexShader,fragmentShader;
		unsigned int shaderProgram;
		const char* vert_shaderSource;
		const char* frag_shaderSource;
		
		std::vector<GLuint> indicies;
		std::vector<float> verticies;
		gObject(){};	
		gObject(const char* v_src,const char* f_src,std::vector<float> vert, std::vector<GLuint> indx){
			vert_shaderSource=v_src;
			frag_shaderSource=f_src;
			verticies=vert;
			indicies=indx;
		}
	
	void ShaderPrep( ){
		vertexShader=glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader,1,&vert_shaderSource,NULL);
		glCompileShader(vertexShader);
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader,1,&frag_shaderSource,NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}


		shaderProgram=glCreateProgram();
		glAttachShader(shaderProgram,vertexShader);
		glAttachShader(shaderProgram,fragmentShader);
		glLinkProgram(shaderProgram);
		
		glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
		if(!success){
			glGetProgramInfoLog(shaderProgram,512, NULL, infoLog);
			std::cout<<"ERROR::SHADER::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

	}

	void BufferInit(int CompPerVert=3){
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1,&VBO);
		glGenBuffers(1,&EBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indicies),&indicies,GL_STATIC_DRAW);

		glVertexAttribPointer(0,CompPerVert,GL_FLOAT,GL_FALSE,CompPerVert*sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		
		//glBindBuffer(GL_ARRAY_BUFFER,0);
		//glBindVertexArray(0);


	}

	void Draw(int triangles=3)
	{
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, triangles);
		//glDrawElements(GL_TRIANGLES,triangles,GL_UNSIGNED_INT,0);
		//glBindVertexArray(0);
	}

	void Dealloc()
	{
		glDeleteVertexArrays(1,&VAO);
		glDeleteBuffers(1,&VBO);
		glDeleteBuffers(1,&EBO);
		glDeleteProgram(shaderProgram);
	}

};
