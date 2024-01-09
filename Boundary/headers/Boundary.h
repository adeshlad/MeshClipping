#pragma once

#include "pch.h"

#include "Point3D.h"

#include <vector>

class BOUNDARY_API Boundary
{
public:
	Boundary();
	~Boundary();

	// return Boundary points.
	std::vector<Point3D> points() const;

	// add Point to Boundary vector.
	void addPointToBoundary(const Point3D inNewPoint);

private:
	std::vector<Point3D> mBoundary;
};
