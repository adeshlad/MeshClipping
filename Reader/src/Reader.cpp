#include "pch.h"
#include "framework.h"
#include "Reader.h"
#include "Point3D.h"

#include <fstream>
#include <sstream>

Reader::Reader()
{

}

Reader::~Reader()
{

}

void Reader::readSTL(const std::string inFilePath, std::vector<Triangle>& inTriangles)
{
	std::ifstream dataFile;
	dataFile.open(inFilePath);
	if (!dataFile.is_open())
	{
		return;
	}

	std::string line;
	while (std::getline(dataFile, line))
	{
		if (line.find("facet normal") != std::string::npos)
		{
			std::string _;
			std::istringstream issNormal(line);

			double x;
			double y;
			double z;

			issNormal >> _ >> _ >> x >> y >> z;
			Point3D normal = Point3D(x, y, z);

			std::getline(dataFile, line);
			std::getline(dataFile, line);

			std::istringstream issPoint1(line);
			issPoint1 >> _ >> x >> y >> z;
			Point3D p1 = Point3D(x, y, z);

			std::getline(dataFile, line);

			std::istringstream issPoint2(line);
			issPoint2 >> _ >> x >> y >> z;
			Point3D p2 = Point3D(x, y, z);

			std::getline(dataFile, line);

			std::istringstream issPoint3(line);
			issPoint3 >> _ >> x >> y >> z;
			Point3D p3 = Point3D(x, y, z);

			Triangle triangle = Triangle(p1, p2, p3);
			triangle.setNormal(normal);

			inTriangles.push_back(triangle);
		}
	}
}

void Reader::readOBJ(const std::string inFilePath, std::vector<Triangle>& inTriangles)
{
	std::vector<Point3D> vertices{ Point3D(0, 0, 0) };

	std::ifstream dataFile;
	dataFile.open(inFilePath);
	if (!dataFile.is_open())
	{
		return;
	}

	std::string line;
	while (std::getline(dataFile, line))
	{
		if (line.find("v ") != std::string::npos)
		{
			std::string _;
			std::stringstream issVertex(line);

			double x;
			double y;
			double z;

			issVertex >> _ >> x >> y >> z;
			vertices.push_back(Point3D(x, y, z));
		}

		if (line.find("f ") != std::string::npos)
		{
			std::string _;
			std::stringstream issFace(line);

			int indexX;
			int indexY;
			int indexZ;

			issFace >> _ >> indexX >> indexY >> indexZ;
			Triangle triangle(vertices[indexX], vertices[indexY], vertices[indexZ]);
			inTriangles.push_back(triangle);
		}
	}
}