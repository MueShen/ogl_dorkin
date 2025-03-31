#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <stdexcept> 
#include <sstream>


std::string readFile(std::string path){
	//std::cout<<path<<std::endl;
	std::ifstream file(path);
	if (file.fail()==true)throw std::invalid_argument("shader file not found or failed to load");
	std::ostringstream oss;
	oss<< file.rdbuf();
	return oss.str(); //for shaders it req char*, might use the .c_str() option to export it in future
}

//TODO implement object loading from files
