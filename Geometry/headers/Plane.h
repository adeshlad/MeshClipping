#pragma once

#include "pch.h"

#include "Point3D.h"

class GEOMETRY_API Plane
{
public:
	Plane();
	~Plane();

	Point3D normal() const;
	double constant() const;

	void moveToPoint(Point3D inPoint);
	void setNormal(Point3D inNormal);
	void shiftPlane(double inBy);

private:
	void setConstant();
	void setConstant(double inConstant);

private:
	Point3D mPointOnPlane;
	Point3D mNormal;
	double mConstant;
};
