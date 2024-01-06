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

	bool isAbove(Plane inPlane, Point3D inPoint);
};
