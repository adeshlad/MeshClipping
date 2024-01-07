#include "Reader.h"
#include "Writer.h"
#include "Clipper.h"
#include "Triangle.h"
#include "Plane.h"
#include "Point3D.h"
#include "Boundary.h"
#include "Mesh.h"


#include <iostream>
#include <vector>

int main()
{
	std::vector<Triangle> triangles;

	Reader reader;
	reader.readSTL("F://adesh_workspace//MeshClipping//Reader//resources//flowerpot.stl", triangles);

	Mesh mesh(triangles);

	Plane plane;
	plane.moveToPoint(Point3D(2, 2, 1));
	plane.setNormal(Point3D(2, 3, -1));

	Clipper clipper;

	Mesh clippedMesh = clipper.clipMeshWithPlane(mesh, plane);
	Boundary boundary = clipper.meshPlaneIntersection(mesh, plane);

	Writer writer;
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op1.txt", clippedMesh);
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op2.txt", boundary);

	std::cout << "done";
}
