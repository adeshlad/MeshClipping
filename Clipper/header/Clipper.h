#pragma once

#include "pch.h"

#include "Point3D.h"
#include "Plane.h"
#include "Mesh.h"
#include "Boundary.h"

#include <vector>

class CLIPPER_API Clipper
{
public:
	Clipper();
	~Clipper();

	Mesh clipMeshWithPlane(Mesh inTriangles, Plane inPlane);

	Boundary meshPlaneIntersection(Mesh inMesh, Plane inPlane);

private:
	Point3D linePlaneIntersection(Point3D inP1, Point3D inP2, Plane inPlane);

	bool isAbove(Plane inPlane, Point3D inPoint);

	double dot(const Point3D inP1, const Point3D inP2);
};
