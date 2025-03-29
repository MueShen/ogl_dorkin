#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

char* fetchShaderFile(std::string path){
	std::string textFromFile,storeText="";
	//std::cout<<std::filesystem::current_path()<<std::endl;
	std::ifstream readfile(path);
	while(getline(readfile,textFromFile))
	{
		storeText+="\n"+textFromFile;
	}
	std::cout<<storeText<<std::endl;
	if(storeText!="") return storeText.data();

	std::cerr<<"\nShader under path:  " +path+" failed to load"<<std::endl;
	return (char* )"";
}
