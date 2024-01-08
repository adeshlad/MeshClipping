#include "Reader.h"
#include "Writer.h"
#include "Clipper.h"
#include "Triangle.h"
#include "Plane.h"
#include "Point3D.h"
#include "Boundary.h"
#include "Mesh.h"
#include "PathGenerator.h"


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

	PathGenerator pathGenerator;
	Boundary path = pathGenerator.generatePath(mesh, plane, 50);

	Writer writer;
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op1.txt", mesh);
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op2.txt", clippedMesh);
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//op3.txt", path);

	std::cout << "done";
}
