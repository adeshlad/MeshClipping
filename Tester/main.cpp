#include "Reader.h"
#include "Writer.h"
#include "Clipper.h"
#include "Triangle.h"
#include "Plane.h"
#include "Point3D.h"

#include <iostream>
#include <vector>

int main()
{
	//std::vector<Triangle> triangles;

	//Reader reader;
	//reader.readOBJ("F://adesh_workspace//MeshClipping//Reader//resources//bunny.obj", triangles);
	//reader.readSTL("F://adesh_workspace//MeshClipping//Reader//resources//flowerpot.stl", triangles);

	//Triangulation triangulation(triangles);

	Plane plane;
	plane.setPointOnPlane(Point3D(1, 2, 1));
	plane.setNormal(Point3D(2, 3, -1));
	//plane.setConstant(7);

	Point3D p1(6.56375, -4.9381, 5);
	Point3D p2(8.78539, 3.7166, 4.52403);

	Clipper clipper;	
 	Point3D	pt = clipper.linePlaneIntersection(p1, p2, plane);
	//Triangulation newTriangulation = clipper.clipWithPlane(triangulation, plane);

	//Writer writer;
	//writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op1.txt", triangulation);
	//writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op2.txt", newTriangulation);

	std::cout << pt.x() << " " << pt.y() << " " << pt.z();
}