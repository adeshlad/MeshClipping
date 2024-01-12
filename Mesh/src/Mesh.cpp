#include "pch.h"
#include "framework.h"

#include "Mesh.h"

#include <cmath>

Mesh::Mesh(const std::vector<Triangle>& inTriangles)
{
    mTriangles = inTriangles;
    updateBBox();
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

Point3D Mesh::BBoxMinPoint() const
{
    return mMin;
}


Point3D Mesh::BBoxMaxPoint() const
{
    return mMax;
}


Point3D Mesh::BBoxCenterPoint() const
{
    return mCenter;
}

void Mesh::updateBBox()
{
    double minX = 9999999;
    double minY = 9999999;
    double minZ = 9999999;

    double maxX = -9999999;
    double maxY = -9999999;
    double maxZ = -9999999;

    for (Triangle triangle : mTriangles)
    {
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();

        minX = std::min<double>(mMin.x(), std::min<double>(p1.x(), std::min<double>(p2.x(), p3.x())));
        minY = std::min<double>(mMin.y(), std::min<double>(p1.y(), std::min<double>(p2.y(), p3.y())));
        minZ = std::min<double>(mMin.z(), std::min<double>(p1.z(), std::min<double>(p2.z(), p3.z())));

        maxX = std::max<double>(mMax.x(), std::max<double>(p1.x(), std::max<double>(p2.x(), p3.x())));
        maxY = std::max<double>(mMax.y(), std::max<double>(p1.y(), std::max<double>(p2.y(), p3.y())));
        maxZ = std::max<double>(mMax.z(), std::max<double>(p1.z(), std::max<double>(p2.z(), p3.z())));
    }

    double centerX = (mMin.x() + mMax.x()) / 2.0;
    double centerY = (mMin.y() + mMax.y()) / 2.0;
    double centerZ = (mMin.z() + mMax.z()) / 2.0;

    mMin = Point3D(minX, minY, minZ);
    mMax = Point3D(maxX, maxY, maxZ);
    mCenter = Point3D(centerX, centerY, centerZ);
}
