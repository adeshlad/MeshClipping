#include "pch.h"
#include "framework.h"
#include "Boundary.h"

Boundary::Boundary()
{

}

Boundary::~Boundary()
{

}

std::vector<Point3D> Boundary::boundary() const
{
	return mBoundary;
}

void Boundary::addPointToBoundary(const Point3D inNewPoint)
{
	mBoundary.push_back(inNewPoint);
}
