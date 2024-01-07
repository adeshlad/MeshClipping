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

//Boundary PathGenerator::generatePath(Mesh inMesh, Plane inPlane, double inInterval)
//{
//	Boundary path;
//	Clipper clipper;
//	
//	Plane positivePlane = inPlane;
//	Plane negativePlane = inPlane;
//
//	Boundary forPositivePlane = clipper.meshPlaneIntersection(inMesh, positivePlane);
//	Boundary forNegativePlane = clipper.meshPlaneIntersection(inMesh, negativePlane);
//
//	while (forPositivePlane.boundary().size() == 0 && forNegativePlane.boundary().size() == 0)
//	{
//		positivePlane.shiftPlane(inInterval);
//		negativePlane.shiftPlane(-inInterval);
//	}
//
//	if (forPositivePlane.boundary().size() > 0 && forNegativePlane.boundary().size() > 0)
//	{
//		while (forPositivePlane.boundary().size() > 0)
//		{
//			for (Point3D point : clipper.meshPlaneIntersection(inMesh, positivePlane).boundary())
//			{
//
//			}
//		}
//	}
//
//}
