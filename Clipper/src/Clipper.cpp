#include "pch.h"
#include "framework.h"

#include "Clipper.h"

#include "Point3D.h"
#include "Triangle.h"

#include <vector>

Clipper::Clipper()
{

}

Clipper::~Clipper()
{

}

Mesh Clipper::clipMeshWithPlane(const Mesh& inMesh, const Plane& inPlane)
{
	std::vector<Triangle> clippedMesh;

	for (Triangle triangle : inMesh.triangles())
	{
		// count of Points above plane
		int count = isAbove(inPlane, triangle.p1()) + isAbove(inPlane, triangle.p2()) + isAbove(inPlane, triangle.p3());

		// 3 Points above, add all 3 Points (1 Triangle) to clippedMesh
		if (count == 3)
		{
			clippedMesh.push_back(triangle);
		}

		// 2 Points above, find 2 new Points intersecting the Plane, generate and add 2 new Triangles to clippedMesh
		else if (count == 2)
		{
			Point3D unclippedP1;
			Point3D unclippedP2;
			Point3D clippedP;

			if (isAbove(inPlane, triangle.p1()))
			{
				unclippedP1 = triangle.p1();

				if (isAbove(inPlane, triangle.p2()))
				{
					unclippedP2 = triangle.p2();
					clippedP = triangle.p3();
				}
				else
				{
					unclippedP2 = triangle.p3();
					clippedP = triangle.p2();
				}
			}
			else
			{
				unclippedP1 = triangle.p2();
				unclippedP2 = triangle.p3();
				clippedP = triangle.p1();
			}

			Point3D newP3 = linePlaneIntersection(unclippedP1, clippedP, inPlane);
			Point3D newP4 = linePlaneIntersection(unclippedP2, clippedP, inPlane);

			Triangle newTriangle1(unclippedP1, unclippedP2, newP3);
			Triangle newTriangle2(unclippedP1, newP3, newP4);

			clippedMesh.push_back(newTriangle1);
			clippedMesh.push_back(newTriangle2);
		}

		// 1 Point above, find 2 new Points intersecting the Plane, generate and add 1 new Triangle
		else if (count == 1)
		{
			Point3D unclippedP;
			Point3D clippedP1;
			Point3D clippedP2;

			if (isAbove(inPlane, triangle.p1()))
			{
				unclippedP = triangle.p1();
				clippedP1 = triangle.p2();
				clippedP2 = triangle.p3();
			}
			else if (isAbove(inPlane, triangle.p2()))
			{
				unclippedP = triangle.p2();
				clippedP1 = triangle.p1();
				clippedP2 = triangle.p3();
			}
			else
			{
				unclippedP = triangle.p3();
				clippedP1 = triangle.p1();
				clippedP2 = triangle.p2();
			}

			Point3D newP2 = linePlaneIntersection(unclippedP, clippedP1, inPlane);
			Point3D newP3 = linePlaneIntersection(unclippedP, clippedP2, inPlane);

			Triangle triangle(unclippedP, newP2, newP3);
			clippedMesh.push_back(triangle);
		}
	}

	return Mesh(clippedMesh);
}

Boundary Clipper::getMeshPlaneIntersection(const Mesh& inMesh, const Plane& inPlane)
{
	Boundary boundary;

	for (Triangle triangle : inMesh.triangles())
	{
		int count = isAbove(inPlane, triangle.p1()) + isAbove(inPlane, triangle.p2()) + isAbove(inPlane, triangle.p3());

		// 3 Points above, Triangle does not intersect Plane, no Point added to Boundary
		if (count == 3)
		{
			continue;
		}

		// 2 Points above, Triangle intersects Plane, 2 intersecting Points added to Boundary
		else if (count == 2)
		{
			Point3D unclippedP1;
			Point3D unclippedP2;
			Point3D clippedP;

			if (isAbove(inPlane, triangle.p1()))
			{
				unclippedP1 = triangle.p1();

				if (isAbove(inPlane, triangle.p2()))
				{
					unclippedP2 = triangle.p2();
					clippedP = triangle.p3();
				}
				else
				{
					unclippedP2 = triangle.p3();
					clippedP = triangle.p2();
				}
			}
			else
			{
				unclippedP1 = triangle.p2();
				unclippedP2 = triangle.p3();
				clippedP = triangle.p1();
			}

			Point3D boundaryP1 = linePlaneIntersection(unclippedP1, clippedP, inPlane);
			Point3D boundaryP2 = linePlaneIntersection(unclippedP2, clippedP, inPlane);

			boundary.addPointToBoundary(boundaryP1);
			boundary.addPointToBoundary(boundaryP2);
		}

		// 1 Points above, Triangle intersects Plane, 2 intersecting Points added to Boundary
		else if (count == 1)
		{
			Point3D unclippedP(0, 0, 0);
			Point3D clippedP1(0, 0, 0);
			Point3D clippedP2(0, 0, 0);

			if (isAbove(inPlane, triangle.p1()))
			{
				unclippedP = triangle.p1();
				clippedP1 = triangle.p2();
				clippedP2 = triangle.p3();
			}
			else if (isAbove(inPlane, triangle.p2()))
			{
				unclippedP = triangle.p2();
				clippedP1 = triangle.p1();
				clippedP2 = triangle.p3();
			}
			else
			{
				unclippedP = triangle.p3();
				clippedP1 = triangle.p1();
				clippedP2 = triangle.p2();
			}

			Point3D boundaryP1 = linePlaneIntersection(unclippedP, clippedP1, inPlane);
			Point3D boundaryP2 = linePlaneIntersection(unclippedP, clippedP2, inPlane);

			boundary.addPointToBoundary(boundaryP1);
			boundary.addPointToBoundary(boundaryP2);
		}
	}

	return boundary;
}

bool Clipper::isAbove(const Plane& inPlane, const Point3D& inPoint)
{

	double value = (inPlane.normal().x() * inPoint.x()) + (inPlane.normal().y() * inPoint.y()) + (inPlane.normal().z() * inPoint.z());

	return value >= inPlane.constant();
}

Point3D Clipper::linePlaneIntersection(const Point3D& inP1, const Point3D& inP2, const Plane& inPlane)
{
	Point3D planeNormal = inPlane.normal();
	double planeConstant = inPlane.constant();

	Point3D lineVector(inP2.x() - inP1.x(), inP2.y() - inP1.y(), inP2.z() - inP1.z());

	double t = (planeConstant - dot(planeNormal, inP1)) / dot(planeNormal, lineVector);

	double x = inP1.x() + t * (inP2.x() - inP1.x());
	double y = inP1.y() + t * (inP2.y() - inP1.y());
	double z = inP1.z() + t * (inP2.z() - inP1.z());

	return Point3D(x, y, z);
}

double Clipper::dot(const Point3D& inP1, const Point3D& inP2)
{
	return inP1.x() * inP2.x() + inP1.y() * inP2.y() + inP1.z() * inP2.z();
}
