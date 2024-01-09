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
	
	// copy given plane into 2 seperate Planes, positive and negative directions.
	Plane positivePlane = inPlane;
	Plane negativePlane = inPlane;

	// get Boundary for both Planes.
	Boundary positivePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, positivePlane);
	Boundary negativePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, negativePlane);

	// if both Boundaries are empty, means given Plane lies outside of the given Mesh.
	// shift both Planes by given Interval until it reaches the Mesh.
	// after this loop either positivePlane or negativePlane will reach the Mesh.
	while (positivePlaneBoundary.points().size() == 0 && negativePlaneBoundary.points().size() == 0)
	{
		positivePlane.shiftPlaneBy(inInterval);
		negativePlane.shiftPlaneBy(-inInterval);

		positivePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, positivePlane);
		negativePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, negativePlane);
	}

	// add positivePlaneBoundary points to path till it reaches beyound mesh.
	while (positivePlaneBoundary.points().size() > 0)
	{
		for (Point3D point : positivePlaneBoundary.points())
		{
			path.addPointToBoundary(point);
		}
		positivePlane.shiftPlaneBy(inInterval);
		positivePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, positivePlane);
	}

	// add negativePlaneBoundary points to path till it reaches beyound mesh.
	while (negativePlaneBoundary.points().size() > 0)
	{
		for (Point3D point : negativePlaneBoundary.points())
		{
			path.addPointToBoundary(point);
		}
		negativePlane.shiftPlaneBy(-inInterval);
		negativePlaneBoundary = clipper.getMeshPlaneIntersection(inMesh, negativePlane);
	}

	return path;
}
