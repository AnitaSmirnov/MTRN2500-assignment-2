//  Cylinder.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Edited by Anita Smirnov
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "Cylinder.hpp"

#include "KeyManager.hpp"

Cylinder::Cylinder() {
	x = z = rotation = 0.0;
	y = 0.5;
	radius = 5.0;
	depth = 1.0;
	red = blue = green = 1.0;
}

Cylinder::Cylinder(double x_, double y_, double z_, double radius_, double depth_, double rotation_, float red_, float green_, float blue_, bool roll_, bool steer_) {
	x = x_;
	y = y_;
	z = z_;
	rotation = rotation_;
	radius = radius_;
	depth = depth_;
	red = red_;
	green = green_;
	blue = blue_;
	roll = roll_;
	steer = steer_;
}

Cylinder::~Cylinder() {
}

void Cylinder::draw() {
	glColor3f(red, green, blue);
	int n = 5;
	glPushMatrix();
	glTranslated(x, y + radius, z-depth/2);
	glRotated(rotation, 0.0, 1.0, 0.0);
	glRotated(wheelRotation, 0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	GLUquadric * q = gluNewQuadric();
	gluCylinder(q, radius, radius, depth, n, n);
	gluDisk(q, 0, radius, n, n);
	glTranslated(0, 0, depth);
	gluDisk(q, 0, radius, n, n);
	glEnd();
	glPopMatrix();
}

bool Cylinder::getSteer() {
	return steer;
}

bool Cylinder::getRoll() {
	return roll;
}

float Cylinder::getRadius() {
	return (float)radius;
}

float Cylinder::getDepth() {
	return (float)depth;
}

void Cylinder::setWheelRotation(double wheel_rotate) {
	wheelRotation = wheel_rotate;
}