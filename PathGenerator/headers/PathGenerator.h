#pragma once

#include "pch.h"

#include "Boundary.h"
#include "Mesh.h"
#include "Plane.h"


class PATHGENERATOR_API PathGenerator
{
public:
	PathGenerator();
	~PathGenerator();
	
	// generate multiple boundaries (as single Boundary object), seperated by given Interval, returns Boundary object.
	Boundary generatePath(const Mesh& inMesh, const Plane& inPlane, const double inInterval);
};
