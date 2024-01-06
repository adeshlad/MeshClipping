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
					Point3D unclippedP2 = triangle.p2();
				}
				else
				{
					Point3D unclippedP2 = triangle.p3();
				}
			}
			else
			{
				Point3D unclippedP1 = triangle.p2();
				Point3D unclippedP2 = triangle.p3();
			}
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

