#include "pch.h"
#include "framework.h"
#include "Path.h"

Path::Path()
{

}

Path::~Path()
{

}

std::vector<Point3D> Path::path() const
{
	return mPathPoints;
}

void Path::addPointToPath(Point3D inNewPoint)
{
	mPathPoints.push_back(inNewPoint);
}

