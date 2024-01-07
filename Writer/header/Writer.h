#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Mesh.h"
#include "Boundary.h"

#include <string>
#include <vector>

class WRITER_API Writer
{
public:
	Writer();
	~Writer();

	void write(std::string filePath, Mesh& inMesh);

	void write(std::string filePath, Boundary& inBoundary);
};
