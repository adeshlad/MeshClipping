#pragma once

#include "pch.h"

#include "Triangle.h"

#include <vector>
#include <string>

class READER_API Reader 
{
public:
	Reader();
	~Reader();

	void readSTL(const std::string inFilePath, std::vector<Triangle>& inTriangles);
	void readOBJ(const std::string inFilePath, std::vector<Triangle>& inTriangles);
};
