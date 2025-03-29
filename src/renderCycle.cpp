#include "include/renderer.h"


void Renderer::renderLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);




		glClearColor(0.859f, 0.388f, 0.004f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

}
