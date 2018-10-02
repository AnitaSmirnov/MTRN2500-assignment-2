// Trapezoidal Prism
// Writtem by Anita Smirnov
// 02/09/18

#pragma once
#include "Shape.hpp"

class TrapezoidalPrism : public Shape
{
public:
	TrapezoidalPrism();
	TrapezoidalPrism(double x_, double y_, double z_, double a_length, double b_length, double depth, double height, double offset, double rotation_,float red_, float green_, float blue_);
	void draw();
	~TrapezoidalPrism();
    
    float getALen();
    float getBLen();
    float getOffset();
    float getDepth();
    
protected:
	double a_l, b_l, d, h, o; // a_length, b_length, depth, height, offset  
}; 
