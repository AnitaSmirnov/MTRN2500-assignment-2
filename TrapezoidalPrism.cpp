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

TrapezoidalPrism::TrapezoidalPrism(double x_, double y_, double z_, double a_length, double b_length, double depth, double height, double offset, double rotation_) {
	x = x_;
	y = y_;
	z = z_;

	a_l = a_length;
	b_l = b_length;
	d = depth;
	h = height;
	o = offset;
	rotation = rotation_;

	red = green = blue = 1.0;
}

void TrapezoidalPrism::draw() {
	glPushMatrix();
	glTranslated(x, y, z);
	glRotated(rotation, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	// top
	glVertex3d(-a_l / 2 + o, h, d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, - d / 2);
	glVertex3d(-a_l / 2 + o, h, - d / 2);

	// front
	glVertex3d(a_l / 2, 0.0, d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, d / 2);
	glVertex3d(-a_l / 2 + o, h, d / 2);
	glVertex3d(-a_l / 2, 0.0, d / 2);

	// right
	glVertex3d(a_l / 2, 0.0, d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, -d / 2);
	glVertex3d(a_l / 2, 0.0, -d / 2);

	// left
	glVertex3d(-a_l / 2, 0.0, d / 2);
	glVertex3d(-a_l / 2 + o, h, d / 2);
	glVertex3d(-a_l / 2 + o, h, -d / 2);
	glVertex3d(-a_l / 2, 0.0, -d / 2);

	// bottom
	glVertex3d(a_l / 2, 0.0, -d / 2);
	glVertex3d(-a_l / 2, 0.0, -d / 2);
	glVertex3d(-a_l / 2, 0.0, d / 2);
	glVertex3d(a_l / 2, 0.0, d / 2);

	// back
	glVertex3d(a_l / 2, 0.0, -d / 2);
	glVertex3d(-a_l / 2, 0.0, -d / 2);
	glVertex3d(-a_l / 2 + o, h, -d / 2);
	glVertex3d(-a_l / 2 + o + b_l, h, -d / 2);


	glTranslated(0, 0, 0);
	glEnd();
	glPopMatrix();
}