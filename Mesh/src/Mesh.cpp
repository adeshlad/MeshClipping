#include "pch.h"
#include "framework.h"
#include "Mesh.h"

Mesh::Mesh(std::vector<Triangle> inTriangles)
{
    mTriangles = inTriangles;
}

Mesh::~Mesh()
{

}

std::vector<Triangle> Mesh::triangles() const
{
    return mTriangles;
}
