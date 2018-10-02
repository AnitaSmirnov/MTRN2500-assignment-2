//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//
#pragma once
#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Shape.hpp"

class Cylinder : public Shape {
protected:
	double radius;
	double depth;
	bool roll;
	bool steer;
public:
	Cylinder();
	Cylinder(double x, double y, double z, double radius_, double depth_, double rotation_, float red_, float green_, float blue_, bool roll_, bool steer_);
	~Cylinder();
	void draw();
	bool getSteer();
	bool getRoll();
	double getRadius();
	//bool getSteer(Cylinder *c);
	//bool getRoll(Cylinder *c);
};
#endif
