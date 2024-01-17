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

std::vector<Triangle> Mesh::triangles() const
{
    return mTriangles;
}

Point3D Mesh::BBoxMinPoint() const
{
    return mBBoxMinPoint;
}


Point3D Mesh::BBoxMaxPoint() const
{
    return mBBoxMaxPoint;
}


Point3D Mesh::BBoxCenterPoint() const
{
    return mBBoxCenterPoint;
}

void Mesh::updateBBox()
{
    double minX = DBL_MAX;
    double minY = DBL_MAX;
    double minZ = DBL_MAX;

    double maxX = DBL_MIN;
    double maxY = DBL_MIN;
    double maxZ = DBL_MIN;

    for (Triangle triangle : mTriangles)
    {
        Point3D p1 = triangle.p1();
        Point3D p2 = triangle.p2();
        Point3D p3 = triangle.p3();

        minX = std::min<double>({ minX, p1.x(), p2.x(), p3.x() });
        minY = std::min<double>({ minY, p1.y(), p2.y(), p3.y() });
        minZ = std::min<double>({ minZ, p1.z(), p2.z(), p3.z() });

        maxX = std::max<double>({ maxX, p1.x(), p2.x(), p3.x() });
        maxY = std::max<double>({ maxY, p1.y(), p2.y(), p3.y() });
        maxZ = std::max<double>({ maxZ, p1.z(), p2.z(), p3.z() });
    }

    mBBoxMinPoint = Point3D(minX, minY, minZ);
    mBBoxMaxPoint = Point3D(maxX, maxY, maxZ);

    double centerX = (minX + maxX) / 2.0;
    double centerY = (minY + maxY) / 2.0;
    double centerZ = (minZ + maxZ) / 2.0;

    mBBoxCenterPoint = Point3D(centerX, centerY, centerZ);
}
