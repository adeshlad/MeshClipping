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
	negativePlane.shiftPlane(-1 * inInterval);

	int flag = 0;
	while (true)
	{
		Boundary forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
		Boundary forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);

		for (Point3D pt : forPositivePlane.boundary())
		{
			path.addPointToBoundary(pt);
		}
		for (Point3D pt : forNegativePlane.boundary())
		{
			path.addPointToBoundary(pt);
		}

		if (forPositivePlane.boundary().size() == 0 && forNegativePlane.boundary().size() == 0)
		{

		}
	}
}
