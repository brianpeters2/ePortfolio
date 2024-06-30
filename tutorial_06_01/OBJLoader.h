#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

// GLEW
#include<GL/glew.h>

//GLFW
#include<GLFW/glfw3.h>

//OpenGL Math Lib
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Own Lib
#include"Vertex.h"

static std::vector<Vertex> loadOBJ(const char* file_name)
{
	//Vertex portions
	std::vector<glm::fvec3> vertex_position;
	std::vector<glm::fvec2> vertex_texcoord;
	std::vector<glm::fvec3> vertex_normal;

	//Face vectors
	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcoord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	//Vertex array
	std::vector<Vertex> verticies;

	std::stringstream ss;
	std::ifstream in_file(file_name);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec3 temp_vec2;
	GLint temp_glint = 0;

	//File open error check
	if (!in_file.is_open()) 
	{
		throw "ERROR::OBJLOADER::Could not open file.";

	}

	//Read one line at a time
	while (std::getline(in_file, line)) {
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "#") {

		}
		 else if (prefix == "o")
		{

		}
		else if (prefix == "s")
		{

		}
		else if (prefix == "use_mtl")
		{

		}
		else if (prefix == "v")//vertex position
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_position.push_back(temp_vec3);
		}
		else if (prefix == "vt")
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoord.push_back(temp_vec2);
		}
		else if (prefix == "vn")
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normal.push_back(temp_vec3);
		}
		else if (prefix == "f")
		{

		}
		else
		{

		}

		//Debug
		std::cout << line << "ln";
		std::cout << "Nr of verticies: " << vertex_position.size() << "ln";
	}

	//loaded success
	return verticies;
}