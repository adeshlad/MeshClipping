#include "pch.h"
#include "framework.h"
#include "Mesh.h"

Mesh::Mesh(const std::vector<Triangle>& inTriangles)
{
    mTriangles = inTriangles;
}

Mesh::~Mesh()
{

}

std::vector<Point3D> Mesh::points() const
{
    std::vector<Point3D> points;

    for (Triangle triangle : mTriangles)
    {
        points.push_back(triangle.p1());
        points.push_back(triangle.p2());
        points.push_back(triangle.p3());
    }

    return points;
}

std::vector<Triangle> Mesh::triangles() const
{
    return mTriangles;
}
