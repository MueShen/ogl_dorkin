#include <iostream>
#include "include/renderer.h"

int main()
{
	Renderer render=Renderer(600,400);
	render.init();
	render.gladInit();
	//std::cin.get();//
	render.renderLoop();
	render.terminate();			

	
	return 0;
}
