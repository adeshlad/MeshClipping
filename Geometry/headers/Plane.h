#pragma once

#include "pch.h"

#include "Point3D.h"

class GEOMETRY_API Plane
{
public:
	Plane();
	~Plane();

	//Point3D pointOnPlane() const;
	Point3D normal() const;
	double constant() const;

	void setPointOnPlane(Point3D inPoint);
	void setNormal(Point3D inNormal);

//private:
	void setConstant();
	void setConstant(double c);

private:
	Point3D mPointOnPlane;
	Point3D mNormal;
	double mConstant;
};
