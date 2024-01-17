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

	// return Mesh triangles.
	std::vector<Triangle> triangles() const;

	// return BBox points
	Point3D BBoxMinPoint() const;
	Point3D BBoxMaxPoint() const;
	Point3D BBoxCenterPoint() const;

private:
	void updateBBox();

private:
	std::vector<Triangle> mTriangles;

	Point3D mBBoxMinPoint;
	Point3D mBBoxMaxPoint;
	Point3D mBBoxCenterPoint;
};
