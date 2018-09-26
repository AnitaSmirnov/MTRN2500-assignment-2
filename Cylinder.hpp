//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright 2018 Anita & Alex. All rights reserved.
//
#pragma once
#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <stdio.h>
#include "Shape.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class Cylinder : public Shape {
protected:
	double radius;
	double depth;
    bool roll;
    bool steer;

public:
	Cylinder();
	Cylinder(double x, double y, double z, double radius_, double depth_, double rotation_,float red_, float green_, float blue_, bool roll_, bool steer_);
	~Cylinder();
    
    void set_roll(bool roll_);
    void set_steer(bool steer_);
    
    bool get_roll();
    bool get_steer();
    
	void draw();
};
#endif
