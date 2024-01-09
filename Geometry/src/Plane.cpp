#include "pch.h"
#include "framework.h"

#include "Plane.h"

Plane::Plane() : mPointOnPlane(0, 0, 0), mNormal(Point3D(0, 0, 0)), mConstant(0)
{

}

Plane::~Plane()
{

}

Point3D Plane::normal() const
{
	return mNormal;
}

double Plane::constant() const
{
	return mConstant;
}

void Plane::movePlaneToPoint(const Point3D inPoint)
{
	mPointOnPlane = inPoint;
	updateConstant();
}

void Plane::setPlaneNormal(const Point3D inNormal)
{
	mNormal = inNormal;
	updateConstant();
}

void Plane::shiftPlaneBy(const double inBy)
{
	mConstant = mConstant + inBy;
}

void Plane::updateConstant()
{
	mConstant = (mNormal.x() * mPointOnPlane.x()) + (mNormal.y() * mPointOnPlane.y()) + (mNormal.z() * mPointOnPlane.z());
}

void Plane::updateConstant(const double inConstant)
{
	mConstant = inConstant;
}
