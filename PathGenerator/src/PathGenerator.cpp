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

Boundary PathGenerator::generatePath(Mesh inMesh, Plane inPlane, double inInterval)
{
	Boundary path;
	Clipper clipper;
	
	Plane positivePlane = inPlane;
	Plane negativePlane = inPlane;

	Boundary forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
	Boundary forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);

	while (forPositivePlane.boundary().size() == 0 && forNegativePlane.boundary().size() == 0)
	{
		positivePlane.shiftPlane(inInterval);
		negativePlane.shiftPlane(-inInterval);
	}

	while (forPositivePlane.boundary().size() > 0)
	{
		for (Point3D point : forPositivePlane.boundary())
		{
			path.addPointToBoundary(point);
		}
		positivePlane.shiftPlane(inInterval);
		forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
	}

	while (forNegativePlane.boundary().size() > 0)
	{
		for (Point3D point : forNegativePlane.boundary())
		{
			path.addPointToBoundary(point);
		}
		negativePlane.shiftPlane(-inInterval);
		forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);
	}

	return path;
}
