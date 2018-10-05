// Rectangular Prism
// Written by Anita Smirnov and Alex Trung Vo
// 02/09/18

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
	RectangularPrism();
	RectangularPrism(double x_, double y_, double z_, double x_length, double y_length, double z_length, double rotation_, float red_, float green_, float blue_);
	void draw();
	~RectangularPrism();
	float getXLen();
	float getYLen();
	float getZLen();
protected:
	double x_l, y_l, z_l;		  // lengths
};