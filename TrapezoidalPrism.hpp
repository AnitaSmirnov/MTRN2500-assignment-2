// Trapezoidal Prism
// Writtem by Anita Smirnov
// 02/09/18

#pragma once
#include "Shape.hpp"
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class TrapezoidalPrism : public Shape
{
public:
	TrapezoidalPrism();
	TrapezoidalPrism(double a_length, double b_length, double depth, double height, double offset, double rotation_);
	void draw();
	~TrapezoidalPrism();
protected:
	double a_l, b_l, d, h, o; // a_length, b_length, depth, height, offset  
}; 
