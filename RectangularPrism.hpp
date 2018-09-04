#pragma once
#include "Shape.hpp"
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class RectangularPrism : public Shape
{
public:
	RegtangularPrism();
	RectangularPrism(double x_, double y_, double z_, double x_length, double y_length, double z_length, double rotation_);
	~RectangularPrism();
	void draw();
protected:
	double x_l, y_l, z_l;		  // lengths
};