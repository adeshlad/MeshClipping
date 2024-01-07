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

void Plane::moveToPoint(Point3D inPoint)
{
	mPointOnPlane = inPoint;
	setConstant();
}

void Plane::setNormal(Point3D inNormal)
{
	mNormal = inNormal;
	setConstant();
}

void Plane::shiftPlane(double inBy)
{
	mConstant = mConstant + inBy;
}

void Plane::setConstant()
{
	mConstant = (mNormal.x() * mPointOnPlane.x()) + (mNormal.y() * mPointOnPlane.y()) + (mNormal.z() * mPointOnPlane.z());
}

void Plane::setConstant(double inConstant)
{
	mConstant = inConstant;
}