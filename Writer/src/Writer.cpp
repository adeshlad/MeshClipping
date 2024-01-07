#include "pch.h"
#include "framework.h"
#include "Writer.h"

#include <fstream>

Writer::Writer()
{

}

Writer::~Writer()
{

}

void Writer::write(std::string filePath, Mesh& inMesh)
{
    std::ofstream dataFile;
    dataFile.open(filePath);

    for (Triangle triangle : inMesh.triangles())
    {
        dataFile << triangle.p1().x() << " " << triangle.p1().y() << " " << triangle.p1().z() << std::endl;
        dataFile << triangle.p2().x() << " " << triangle.p2().y() << " " << triangle.p2().z() << std::endl;
        dataFile << triangle.p3().x() << " " << triangle.p3().y() << " " << triangle.p3().z() << std::endl;
        dataFile << triangle.p1().x() << " " << triangle.p1().y() << " " << triangle.p1().z() << std::endl;
    }
    dataFile.close();
};

void Writer::write(std::string filePath, Boundary& inBoundary)
{
    std::ofstream dataFile;
    dataFile.open(filePath);

    for (Point3D point : inBoundary.boundary())
    {
        dataFile << point.x() << " " << point.y() << " " << point.z() << std::endl;
    }
    dataFile.close();
}