// Rectangular Prism
// Writtem by Anita Smirnov
// 02/09/18

#include "RectangularPrism.hpp"

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


RectangularPrism::RectangularPrism() {
	x = y = z = 0.0;
	x_l = y_l = z_l = 1.0;
	rotation = 0.0;
	red = green = blue = 1.0;
};

RectangularPrism::~RectangularPrism() {
}

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double x_length, double y_length, double z_length, double rotation_, float red_, float green_, float blue_) {
	x = x_;
	y = y_;
	z = z_;
	
	x_l = x_length;
	y_l = y_length;
	z_l = z_length;

	rotation = rotation_;
	red = red_;
	green = green_;
	blue = blue_;
}

float RectangularPrism::getXLen(){
    return (float)x_l;
}

float RectangularPrism::getYLen(){
    return (float)y_l;
}

float RectangularPrism::getZLen(){
    return (float)z_l;
}

void RectangularPrism::draw() {
	glColor3f(red, green, blue);
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotation, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	// top
	glNormal3d(0.0, 1.0, 0.0);
	glVertex3d(x_l / 2, y_l, z_l / 2);
	glVertex3d(-x_l / 2, y_l, z_l / 2);
	glVertex3d(-x_l / 2, y_l, -z_l / 2);
	glVertex3d(x_l / 2, y_l, -z_l / 2);

	// front
	glNormal3d(0.0, 0.0, 1.0);
	glVertex3d(x_l / 2, 0.0, z_l / 2);
	glVertex3d(x_l / 2, y_l, z_l / 2);
	glVertex3d(x_l / 2, y_l, z_l / 2);
	glVertex3d(x_l / 2, 0.0, z_l / 2);

	// right
	glNormal3d(1.0, 0.0, 0.0);
	glVertex3d(x_l / 2, 0.0, -z_l / 2);
	glVertex3d(x_l / 2, 0.0, z_l / 2);
	glVertex3d(x_l / 2, y_l, z_l / 2);
	glVertex3d(x_l / 2, y_l, -z_l / 2);

	// left
	glNormal3d(-1.0, 0.0, 0.0);
	glVertex3d(-x_l / 2, 0.0, -z_l / 2);
	glVertex3d(-x_l / 2, 0.0, z_l / 2);
	glVertex3d(-x_l / 2, y_l, z_l / 2);
	glVertex3d(-x_l / 2, y_l, -z_l / 2);

	// bottom
	glNormal3d(0.0, -1.0, 0.0);
	glVertex3d(x_l/2, 0.0, z_l/2);
	glVertex3d(-x_l / 2, 0.0, z_l / 2);
	glVertex3d(-x_l / 2, 0.0, -z_l / 2);
	glVertex3d(x_l / 2, 0.0, -z_l / 2);

	// back
	glNormal3d(0.0, 0.0, -1.0);
	glVertex3d(-x_l / 2, 0.0, -z_l / 2);
	glVertex3d(-x_l / 2, y_l, -z_l / 2);
	glVertex3d(x_l / 2, y_l, -z_l / 2);
	glVertex3d(x_l / 2, 0.0, -z_l / 2);

	glEnd();
	glPopMatrix();
}
