//  TriangularPrism.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright � 2018 Anita & Alex. All rights reserved.
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
/*#else
#include <unistd.h>
#include <sys/time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <math.h>*/
#include <cmath>
#include "TriangularPrism.hpp"
#define RAD 3.14159/180

TriangularPrism::TriangularPrism() { // default setters :)
	x = y = z = rotation = 0.0;
	angle = 60.0;
	side_1 = side_2 = 10.0;
	depth = 0.0;

}
TriangularPrism::TriangularPrism(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_, double rotation_, float red_, float green_, float blue_) {
	x = x_;
	y = y_;
	z = z_;
	rotation = rotation_;
	side_1 = side1;
	side_2 = side2;
	angle = angle_;
	depth = depth_;

	red = red_;
	green = green_;
	blue = blue_;
}
TriangularPrism::~TriangularPrism() {
}
float TriangularPrism::getALen() {
	return (float)side_1;
}
float TriangularPrism::getBLen() {
	return (float)side_2;
}
float TriangularPrism::getAngle() {
	return (float)angle;
}
float TriangularPrism::getDepth() {
	return (float)depth;
}
void TriangularPrism::draw() {
	glPushMatrix();
	glColor3f(red, green, blue);
	glTranslated(x, y, z);
	glRotated(rotation, 0.0, 1.0, 0.0);
	glRotated(zRotation, 0, 0, 1);
	//drawing the triangle faces of the prism
	glBegin(GL_TRIANGLES);
	// front
	glVertex3d(side_1 / 2, 0.0, depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), depth / 2);
	glVertex3d(side_1 / 2, 0.0, depth / 2);
	// back
	glVertex3d(side_1 / 2, 0.0, -depth / 2);
	glVertex3d(-side_1 / 2, 0.0, -depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), -depth / 2);

	glEnd();

	//drawing the long rectangular faces of the prism
	glBegin(GL_QUADS);

	// bottom
	glVertex3d(side_1 / 2, 0, -depth / 2);
	glVertex3d(side_1 / 2, 0, depth / 2);
	glVertex3d(-side_1 / 2, 0, depth / 2);
	glVertex3d(-side_1 / 2, 0, -depth / 2);
	// right roof
	glVertex3d(side_1 / 2, 0.0, -depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), -depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), depth / 2);
	glVertex3d(side_1 / 2, 0.0, depth / 2);

	// left roof
	glVertex3d(-side_1 / 2, 0.0, depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), depth / 2);
	glVertex3d(-side_1 / 2 + side_2 * cos(angle*RAD), side_2*sin(angle*RAD), -depth / 2);
	glVertex3d(-side_1 / 2, 0.0, -depth / 2);
	glEnd();

	glPopMatrix();
}

void TriangularPrism::setZRotation(double z_rotation) {
	zRotation = z_rotation;
}