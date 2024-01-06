#pragma once

#include "pch.h"

#include "Triangle.h"

#include <vector>

class TRIANGULATION_API Triangulation
{
public:
	Triangulation(std::vector<Triangle> inTriangles);
	~Triangulation();

	std::vector<Triangle> triangles() const;

private:
	std::vector<Triangle> mTriangles;
};
