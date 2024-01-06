#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Plane.h"
#include "Triangulation.h"

class CLIPPER_API Clipper
{
public:
	Clipper();
	~Clipper();

	Triangulation clipWithPlane(Triangulation inTriangles, Plane inPlane);

private:
	bool isAbove(Plane inPlane, Point3D inPoint);

	Point3D linePlaneIntersection(Point3D inP1, Point3D inP2, Plane inPlane);

	double dot(const Point3D inP1, const Point3D inP2);
};
