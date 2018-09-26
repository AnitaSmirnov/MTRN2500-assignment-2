// Rectangular Prism
// Writtem by Anita Smirnov
// 02/09/18

#include "RectangularPrism.hpp"

RectangularPrism::RectangularPrism() {
	x = y = z = 0.0;
	x_l = y_l = z_l = 1.0;
	rotation = 0.0;
	red = green = blue = 1.0;
};

RectangularPrism::~RectangularPrism() {
}

RectangularPrism::RectangularPrism(double x_, double y_, double z_, double x_length, double y_length, double z_length, double rotation_) {
	x = x_;
	y = y_;
	z = z_;
	
	x_l = x_length;
	y_l = y_length;
	z_l = z_length;

	rotation = rotation_;
	red = green = blue = 1.0;
}

void RectangularPrism::draw() {
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