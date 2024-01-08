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
	plane.movePlaneToPoint(Point3D(0, 0, 0));
	plane.setPlaneNormal(Point3D(0, 0, -1));

	Clipper clipper;

	Mesh clippedMesh = clipper.clipMeshWithPlane(mesh, plane);

	PathGenerator pathGenerator;
	Boundary path = pathGenerator.generatePath(mesh, plane, 10);

	Writer writer;
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//mesh.txt", mesh);
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//clippedMesh.txt", clippedMesh);
	writer.write("F://adesh_workspace//MeshClipping//Writer//resources//path.txt", path);

	std::cout << "done";
}
