#include "pch.h"
#include "framework.h"

#include "Plane.h"

Plane::Plane() : mPointOnPlane(0, 0, 0), mNormal(Point3D(0, 0, 1)), mConstant(0)
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

void Plane::moveUp(const double inBy)
{
	double newX = mPointOnPlane.x() + (mNormal.x() * inBy);
	double newY = mPointOnPlane.y() + (mNormal.y() * inBy);
	double newZ = mPointOnPlane.z() + (mNormal.z() * inBy);

	mPointOnPlane = Point3D(newX, newY, newZ);

	updateConstant();
}

void Plane::moveDown(const double inBy)
{
	double newX = mPointOnPlane.x() - (mNormal.x() * inBy);
	double newY = mPointOnPlane.y() - (mNormal.y() * inBy);
	double newZ = mPointOnPlane.z() - (mNormal.z() * inBy);

	mPointOnPlane = Point3D(newX, newY, newZ);

	updateConstant();
}

void Plane::tiltFront(const double inBy)
{
	double by = (1.0 / 90.0) * inBy;

	double normalX = mNormal.x();
	double normalY = mNormal.y() - by;
	double normalZ = mNormal.z() - by;

	mNormal = Point3D(normalX, normalY, normalZ);

	updateConstant();
}

void Plane::tiltBack(const double inBy)
{
	double by = (1.0 / 90.0) * inBy;

	double normalX = mNormal.x();
	double normalY = mNormal.y() + by;
	double normalZ = mNormal.z() - by;

	mNormal = Point3D(normalX, normalY, normalZ);

	updateConstant();
}

void Plane::tiltLeft(const double inBy)
{
	double by = (1.0 / 90.0) * inBy;

	double normalX = mNormal.x() - by;
	double normalY = mNormal.y();
	double normalZ = mNormal.z() - by;

	mNormal = Point3D(normalX, normalY, normalZ);

	updateConstant();
}

void Plane::tiltRight(const double inBy)
{
	double by = (1.0 / 90.0) * inBy;

	double normalX = mNormal.x() + by;
	double normalY = mNormal.y();
	double normalZ = mNormal.z() - by;

	mNormal = Point3D(normalX, normalY, normalZ);

	updateConstant();
}

void Plane::updateConstant()
{
	mConstant = (mNormal.x() * mPointOnPlane.x()) + (mNormal.y() * mPointOnPlane.y()) + (mNormal.z() * mPointOnPlane.z());
}
