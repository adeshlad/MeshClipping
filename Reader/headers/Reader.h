#pragma once

#include "pch.h"

#include "Triangle.h"

#include <string>
#include <vector>

class READER_API Reader 
{
public:
	Reader();
	~Reader();

	void readSTL(std::string inFilePath, std::vector<Triangle>& inTriangles);
	void readOBJ(std::string inFilePath, std::vector<Triangle>& inTriangles);
};
