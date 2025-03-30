#include "include/renderer.h"
#include "include/fileworks.h"

void Renderer::shaderInit()
{
	std::string vert_sourceCodeLoaded= readFile("shaders/shader.vert").c_str();
	const char *vertexShaderSource=vert_sourceCodeLoaded.c_str();
	unsigned int vertexShaderid;
	vertexShaderid=glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderid,1,&vertexShaderSource,NULL);
	 
	std::string frag_sourceCodeLoaded=readFile("shaders/shader.frag").c_str();
	const char *fragShaderSource=frag_sourceCodeLoaded.c_str();
	unsigned int fragShaderid;
	fragShaderid=glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShaderid,1,&fragShaderSource, NULL);

	int vert_success_compile,frag_success_compile;
	char infoLog[512];
	glGetShaderiv(vertexShaderid, GL_COMPILE_STATUS, &vert_success_compile);
	glGetShaderiv(fragShaderid, GL_COMPILE_STATUS, &frag_success_compile);
	if(!vert_success_compile)
	{
		glGetShaderInfoLog(vertexShaderid,512, NULL,infoLog);
		std::cout<<" VERTEX SHADER COMPILE ERROR \n"<<infoLog<<std::endl;
	}
	if(!frag_success_compile)
	{
		glGetShaderInfoLog(fragShaderid,512, NULL,infoLog);
		std::cout<<" FRAG SHADER COMPILE ERROR \n"<<infoLog<<std::endl;
	}

		
	unsigned int shaderProgram;
	shaderProgram=glCreateProgram();
	glAttachShader(shaderProgram, vertexShaderid);
	glAttachShader(shaderProgram, fragShaderid);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glDeleteShader(vertexShaderid);
	glDeleteShader(fragShaderid);

}

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


