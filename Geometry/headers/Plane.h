#pragma once

#include "pch.h"

#include "Point3D.h"

class GEOMETRY_API Plane
{
public:

	// Plane equation: Ax + By Cz = D
	// (A, B, C) is nomal vector of the plane and D is a constant.

	Plane();
	~Plane();

	Point3D normal() const;
	double constant() const;

	// move Plane to specified point, keeping same Normal.
	void movePlaneToPoint(const Point3D inPoint);

	// set Plane normal, keeping same Point.
	void setPlaneNormal(const Point3D inNormal);

	// shift Plane in (+ve value) or against (-ve value) the direction of normal by specified value.
	void shiftPlaneBy(const double inBy);

private:

	// private - update Plane Constant.
	void updateConstant();
	void updateConstant(const double inConstant);

private:
	Point3D mPointOnPlane;
	Point3D mNormal;
	double mConstant;
};
