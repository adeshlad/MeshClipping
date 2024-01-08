#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Triangle.h"

#include <vector>

class MESH_API Mesh
{
public:
	Mesh(std::vector<Triangle> inTriangles);
	~Mesh();

	std::vector<Point3D> points() const;
	std::vector<Triangle> triangles() const;

private:
	std::vector<Triangle> mTriangles;
};
