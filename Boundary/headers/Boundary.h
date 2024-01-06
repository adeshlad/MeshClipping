#pragma once

#include "pch.h"

#include "Point3D.h"

#include <vector>

class BOUNDARY_API Boundary
{
public:
	Boundary();
	~Boundary();

	std::vector<Point3D> boundary() const;

	void addPointToBoundary(Point3D inNewPoint);

private:
	std::vector<Point3D> mBoundary;
};
