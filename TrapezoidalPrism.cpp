// Trapezoidal Prism
// Writtem by Anita Smirnov
// 02/09/18

#include "TrapezoidalPrism.hpp"

TrapezoidalPrism::TrapezoidalPrism() {
	x = y = z = 0.0;
	a_l = b_l = d = h = 1.0;
	o = 0.0;
	rotation = 0.0;
	red = green = blue = 1.0;
};

TrapezoidalPrism::~TrapezoidalPrism() {
}

TrapezoidalPrism::TrapezoidalPrism(double a_length, double b_length, double depth, double height, double offset, double rotation_) {
	x = a_length/2;
	y = 0.0;
	z = depth/2;

	a_l = a_length;
	b_l = b_length;
	d = depth;
	h = height;
	o = offset;
	rotation = rotation_;

	red = green = blue = 1.0;
}

void TrapezoidalPrism::draw() {
	//glTranslated(10.0, 0, 10.0);
	//glRotated(rotation, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	// top
	glNormal3d(0.0, 1.0, 0.0);
	glVertex3d(x - a_l / 2 + o, y + h, z + d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z + d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z - d / 2);
	glVertex3d(x - a_l / 2 + o, y + h, z - d / 2);

	// front
	glNormal3d(0.0, 0.0, 1.0);
	glVertex3d(x + a_l / 2, y, z + d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z + d / 2);
	glVertex3d(x - a_l / 2 + o, y + h, z + d / 2);
	glVertex3d(x - a_l / 2, y, z + d / 2);

	// right
	glNormal3d(1.0, 0.0, 0.0);
	glVertex3d(x + a_l / 2, y, z + d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z + d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z - d / 2);
	glVertex3d(x - a_l / 2, y, z - d / 2);

	// left
	glNormal3d(-1.0, 0.0, 0.0);
	glVertex3d(x - a_l / 2, y, z + d / 2);
	glVertex3d(x - a_l / 2 + o, y + h, z + d / 2);
	glVertex3d(x - a_l / 2 + o, y + h, z - d / 2);
	glVertex3d(x - a_l / 2, y, z - d / 2);

	// bottom
	glNormal3d(0.0, -1.0, 0.0);
	glVertex3d(x + a_l / 2, y, z - d / 2);
	glVertex3d(x - a_l / 2, y, z - d / 2);
	glVertex3d(x - a_l / 2, y, z + d / 2);
	glVertex3d(x + a_l / 2, y, z + d / 2);

	// back
	glNormal3d(0.0, 0.0, -1.0);
	glVertex3d(x + a_l / 2, y, z - d / 2);
	glVertex3d(x - a_l / 2, y, z - d / 2);
	glVertex3d(x - a_l / 2 + o, y + h, z - d / 2);
	glVertex3d(x - a_l / 2 + o + b_l, y + h, z - d / 2);

	glEnd();
}