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

	void movePlaneToPoint(const Point3D inPoint);
	void setPlaneNormal(const Point3D inNormal);
	void shiftPlaneBy(const double inBy);

private:
	void setConstant();
	void setConstant(const double inConstant);

private:
	Point3D mPointOnPlane;
	Point3D mNormal;
	double mConstant;
};
