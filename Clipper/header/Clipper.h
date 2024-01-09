#pragma once

#include "pch.h"

#include "Boundary.h"
#include "Mesh.h"
#include "Plane.h"
#include "Point3D.h"

#include <vector>

class CLIPPER_API Clipper
{
public:
	Clipper();
	~Clipper();

	// clips/cuts Mesh with Plane, returns new Mesh object
	Mesh clipMeshWithPlane(const Mesh& inTriangles, const Plane& inPlane);

	// finds intersection between Mesh and Plane, return new Boundary object
	Boundary getMeshPlaneIntersection(const Mesh& inMesh, const Plane& inPlane);


private:

	// finds Point where line between 2 Points intersects Plane
	Point3D linePlaneIntersection(const Point3D& inP1, const Point3D& inP2, const Plane& inPlane);

	// check if Point is above the Plane
	bool isAbove(const Plane& inPlane, const Point3D& inPoint);

	// dot product
	double dot(const Point3D& inP1, const Point3D& inP2);
};
