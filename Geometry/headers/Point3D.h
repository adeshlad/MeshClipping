#pragma once

#include "pch.h"

class GEOMETRY_API Point3D
{
public:
	Point3D();
	Point3D(const double inX, const double inY, const double inZ);
	~Point3D();

	double x() const;
	double y() const;
	double z() const;

	void setX(const double inX);
	void setY(const double inY);
	void setZ(const double inZ);

private:
	double mX;
	double mY;
	double mZ;
};
