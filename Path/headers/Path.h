#pragma once

#include "pch.h"

#include "Point3D.h"

#include <vector>

class PATH_API Path {
public:
	Path();
	~Path();

	std::vector<Point3D> path() const;

	void addPointToPath(Point3D inNewPoint);

private:
	std::vector<Point3D> mPathPoints;
};
