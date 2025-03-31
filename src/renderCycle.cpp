#include "include/renderer.h"
#include "include/fileworks.h"
#include "include/object.h"



std::vector<float> vertices = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

std::vector<GLuint> indicies={
	0,1,2
};

std::string vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\n\0";
std::string fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";



void Renderer::renderLoop()
{
	gObject firstTrig(vertexShaderSource.c_str(),fragmentShaderSource.c_str(),vertices,indicies);
	firstTrig.ShaderPrep();
	firstTrig.BufferInit(3);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		//glClearColor(0.859f, 0.388f, 0.004f, 1.0f);
		glClearColor(0.1f,0.1f,0.2f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	

		firstTrig.Draw(3);
		//std::cout<<"test\n";
		glfwSwapBuffers(window);
		glfwPollEvents();

	}

}


