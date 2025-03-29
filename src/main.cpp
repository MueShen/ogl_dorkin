#include <iostream>
#include "include/renderer.h"
#include "include/shader.h"

int main()
{
	Renderer render=Renderer(600,400);
	render.startup();	
	fetchShaderFile("shaders/test.txt");
	return 0;
}
