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

Cylinder::Cylinder() {
	x = z = rotation = 0.0;
	y = 0.5;
	radius = 5.0;
	depth = 1.0;
	red = blue = green = 1.0;
}

Cylinder::Cylinder(double x_, double y_, double z_, double radius_, double depth_, double rotation_) {
	x = x_;
	y = y_;
	z = z_;
	rotation = rotation_;
	radius = radius_;
	depth = depth_;
	//red = blue = green = 1.0;
}

Cylinder::~Cylinder() {
}

void Cylinder::draw() {
	//glTranslated(x, y, z);
	glRotated(rotation, 0.0, 1.0, 0.0);
	//glColor3d(red, green, blue);
	
	static GLUquadric * q = gluNewQuadric();
	int n = 50; // amount of straight lines connecting the disks
	
	// translating to the most -ve value of z
	glPushMatrix();
	glTranslated(x, y + radius, z - depth / 2);
	glBegin(GL_QUADS);
	gluCylinder(q, radius, radius, depth / 2, n, n);
	glEnd();
	glPopMatrix();
	// translating back to the original z centre
	glPushMatrix();
	glTranslated(x, y + radius, 0);
	glBegin(GL_QUADS);
	gluCylinder(q, radius, radius, depth / 2, n, n);
	glEnd();
	glPopMatrix();
	

	glPushMatrix();
	glTranslated(0, y + radius, z - depth / 2);
	glBegin(GL_QUADS);
	gluDisk(q, 0, radius, n, n);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(x, y + radius, z + depth / 2);
	glBegin(GL_QUADS);
	gluDisk(q, 0, radius, n, n);
	glEnd();
	glPopMatrix();
}