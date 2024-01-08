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

	Boundary generatePath(Mesh inMesh, Plane inPlane, double inInterval);

};
