#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Triangle.h"

#include <vector>

class MESH_API Mesh
{
public:
	Mesh(const std::vector<Triangle>& inTriangles);
	~Mesh();

	// return Mesh points.
	std::vector<Point3D> points() const;

	// return Mesh triangles.
	std::vector<Triangle> triangles() const;

private:
	std::vector<Triangle> mTriangles;
};
