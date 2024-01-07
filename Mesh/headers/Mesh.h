#pragma once

#include "pch.h"

#include "Triangle.h"

#include <vector>

class MESH_API Mesh
{
public:
	Mesh(std::vector<Triangle> inTriangles);
	~Mesh();

	std::vector<Triangle> triangles() const;

private:
	std::vector<Triangle> mTriangles;
};
