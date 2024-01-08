#include "pch.h"
#include "framework.h"
#include "PathGenerator.h"
#include "Clipper.h"

PathGenerator::PathGenerator()
{

}

PathGenerator::~PathGenerator()
{

}

Boundary PathGenerator::generatePath(const Mesh& inMesh, const Plane& inPlane, const double inInterval)
{
	Boundary path;
	Clipper clipper;
	
	Plane positivePlane = inPlane;
	Plane negativePlane = inPlane;

	Boundary forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
	Boundary forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);

	while (forPositivePlane.boundary().size() == 0 && forNegativePlane.boundary().size() == 0)
	{
		positivePlane.shiftPlaneBy(inInterval);
		negativePlane.shiftPlaneBy(-inInterval);

		forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
		forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);
	}

	while (forPositivePlane.boundary().size() > 0)
	{
		for (Point3D point : forPositivePlane.boundary())
		{
			path.addPointToBoundary(point);
		}
		positivePlane.shiftPlaneBy(inInterval);
		forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
	}

	while (forNegativePlane.boundary().size() > 0)
	{
		for (Point3D point : forNegativePlane.boundary())
		{
			path.addPointToBoundary(point);
		}
		negativePlane.shiftPlaneBy(-inInterval);
		forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);
	}

	return path;
}
