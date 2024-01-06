#pragma once

#include "pch.h"

#include "Triangulation.h"

#include <string>

class WRITER_API Writer
{
public:
	Writer();
	~Writer();

	void write(std::string filePath, Triangulation& inTriangulation);
};
