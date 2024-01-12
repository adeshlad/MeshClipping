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

	// return BBox data
	Point3D BBoxMinPoint() const;
	Point3D BBoxMaxPoint() const;
	Point3D BBoxCenterPoint() const;

	// update BBox
	void updateBBox();
private:


private:
	std::vector<Triangle> mTriangles;

	Point3D mMin;
	Point3D mMax;
	Point3D mCenter;
};
