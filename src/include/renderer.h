#pragma once
#define GLFW_INCLUDE_OPENGL
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>


class Renderer{
public:
	GLFWwindow *window;
	unsigned int m_width=400,m_height=400;
	Renderer();
	Renderer(int width,int height){m_width=width; m_height=height;};

	int init();
	void startup(){
		init();
		gladInit();
		shaderInit(); //TODO: implement object and shader handling
		renderLoop();
		terminate();	
	};
	int gladInit();
	void shaderInit();
	void renderLoop();
	void processInput(GLFWwindow *window);
	int terminate();
}; 
