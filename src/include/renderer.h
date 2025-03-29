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
	int gladInit();
	void renderLoop();
	void processInput(GLFWwindow *window);
	int terminate();
};
