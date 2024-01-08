#pragma once

#include "pch.h"

class GEOMETRY_API Point3D
{
public:
	Point3D();
	Point3D(double inX, double inY, double inZ);
	~Point3D();

	Point3D(const Point3D& other);

	Point3D& operator=(const Point3D& other);

	double x() const;
	double y() const;
	double z() const;

	void setX(double inX);
	void setY(double inY);
	void setZ(double inZ);



private:
	double mX;
	double mY;
	double mZ;
};
