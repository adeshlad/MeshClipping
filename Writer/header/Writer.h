#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Triangulation.h"
#include "Boundary.h"

#include <string>
#include <vector>

class WRITER_API Writer
{
public:
	Writer();
	~Writer();

	void write(std::string filePath, Triangulation& inTriangulation);

	void write(std::string filePath, Boundary& inBoundary);
};
