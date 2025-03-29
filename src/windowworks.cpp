#include "include/renderer.h"
#define GLFW_INCLUDE_OPENGL
#include "include/glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

// settings


int Renderer::init(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	window = glfwCreateWindow(m_width, m_height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -2;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return 0;

}


int Renderer::gladInit(){
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
{
	std::cout << "Failed to initialize GLAD" << std::endl;
	return -1;
	}  
	return 0;

}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// -----;----------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);
std::cout<<"resize event! \n";
}

int Renderer::terminate(){
	glfwTerminate();
	return 0;
}


