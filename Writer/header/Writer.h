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

	void write(const std::string filePath, const Mesh& inMesh);

	void write(const std::string filePath, const Boundary& inBoundary);
};
