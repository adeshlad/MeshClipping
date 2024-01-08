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

	Mesh clipMeshWithPlane(const Mesh& inTriangles, const Plane& inPlane);

	Boundary meshPlaneIntersection(const Mesh& inMesh, const Plane& inPlane);


private:
	Point3D linePlaneIntersection(const Point3D& inP1, const Point3D& inP2, const Plane& inPlane);

	bool isAbove(const Plane& inPlane, const Point3D& inPoint);

	double dot(const Point3D& inP1, const Point3D& inP2);
};
