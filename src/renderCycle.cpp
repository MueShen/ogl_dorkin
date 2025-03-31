#include "include/renderer.h"
#include "include/fileworks.h"
#include "include/object.h"



std::vector<float> vertices= {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

std::vector<GLuint> indicies={
	0,1,2
};





void Renderer::renderLoop() 
{
	std::string vertexShaderSource=readFile("shaders/shader.vert");
	std::string fragmentShaderSource=readFile("shaders/shader.frag"); 
	
	gObject firstTrig(vertexShaderSource.c_str(),
			fragmentShaderSource.c_str(),
			vertices,indicies);
	firstTrig.ShaderPrep();
	firstTrig.BufferInit(3);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		//glClearColor(0.859f, 0.388f, 0.004f, 1.0f);
		glClearColor(0.14f, 0.14f, 0.14f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	

		firstTrig.Draw();
		//std::cout<<"test\n";
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	firstTrig.Dealloc();

}


