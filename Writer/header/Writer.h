#pragma once

#include "pch.h"

#include "Boundary.h"
#include "Mesh.h"

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
