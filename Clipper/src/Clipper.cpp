#include "pch.h"
#include "framework.h"
#include "Clipper.h"
#include "Triangle.h"
#include "Point3D.h"

#include <vector>

Clipper::Clipper()
{

}

Clipper::~Clipper()
{

}

Triangulation Clipper::clipWithPlane(Triangulation inTriangles, Plane inPlane)
{
	std::vector<Triangle> clippedTriangulation;

	for (Triangle triangle : inTriangles.triangles())
	{
		int count = isAbove(inPlane, triangle.p1()) + isAbove(inPlane, triangle.p2()) + isAbove(inPlane, triangle.p3());

		if (count == 3)
		{
			clippedTriangulation.push_back(triangle);
		}

		if (count == 2)
		{
			Point3D unclippedP1(0, 0, 0);
			Point3D unclippedP2(0, 0, 0);

			if (isAbove(inPlane, triangle.p1()))
			{
				unclippedP1 = triangle.p1();

				if (isAbove(inPlane, triangle.p2()))
				{
					unclippedP2 = triangle.p2();
				}
				else
				{
					unclippedP2 = triangle.p3();
				}
			}
			else
			{
				unclippedP1 = triangle.p2();
				unclippedP2 = triangle.p3();
			}

			// i am here now
		}

		if (count == 1)
		{

		}
	}

	return Triangulation(clippedTriangulation);
}

bool Clipper::isAbove(Plane inPlane, Point3D inPoint)
{

	double value = (inPlane.normal().x() * inPoint.x()) + (inPlane.normal().y() * inPoint.y()) + (inPlane.normal().z() * inPoint.z());

	return value >= inPlane.constant();
}

Point3D Clipper::linePlaneIntersection(Point3D inP1, Point3D inP2, Plane inPlane)
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

double Clipper::dot(const Point3D inP1, const Point3D inP2)
{
	return inP1.x() * inP2.x() + inP1.y() * inP2.y() + inP1.z() * inP2.z();
}


// Old code that might be needed later

//Point3D normal = inPlane.normal();
//double constant = inPlane.constant();
//
//double d = dot(normal, inPlane.pointOnPlane());
//Point3D diff(inP2.x() - inP1.x(), inP2.y() - inP1.y(), inP2.z() - inP1.z());
//
//double t1 = planeConstant - (planeNormal.x() * inP1.x()) - (planeNormal.y() * inP1.y()) - (planeNormal.z() * inP1.z());
//double t2 = (planeNormal.x() * (inP2.x() - inP1.x())) + (planeNormal.y() * (inP2.y() - inP1.y())) + (planeNormal.z() * (inP2.z() - inP1.z()));
//
//double t = (d - dot(normal, inP1)) / dot(normal, diff);
//
//double x = inP1.x() + t * (inP2.x() - inP1.x());
//double y = inP1.y() + t * (inP2.y() - inP1.y());
//double z = inP1.z() + t * (inP2.z() - inP1.z());
//
//return Point3D(x, y, z);