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

	// move Plane in the direction of normal by specified value.
	void moveUp(const double inBy);

	// move Plane against the direction of normal by specified value.
	void moveDown(const double inBy);

	// tilt Plane.
	void tiltBack(const double inBy);
	void tiltFront(const double inBy);
	void tiltLeft(const double inBy);
	void tiltRight(const double inBy);

private:

	// update Plane Constant.
	void updateConstant();

private:
	Point3D mPointOnPlane;
	Point3D mNormal;
	double mConstant;
};
