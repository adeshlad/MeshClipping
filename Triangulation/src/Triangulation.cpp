#include "pch.h"
#include "framework.h"
#include "Triangulation.h"

Triangulation::Triangulation(std::vector<Triangle> inTriangles)
{
    mTriangles = inTriangles;
}

Triangulation::~Triangulation()
{

}

std::vector<Triangle> Triangulation::triangles() const
{
    return mTriangles;
}
