//
// Created by Anita Smirnov on 04/09/18
// 

#include "MyVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"


MyVehicle::MyVehicle() {
	speed = steering = 0;
}

MyVehicle::MyVehicle(double x_, double y_, double z_, double rotation_) {
	Shape *s = new Cylinder(-8.0, 1.0, 5, 1.0, 0.3, 0, 1.0, 0.2, 0.6);
	shapes.push_back(s);

}

MyVehicle::~MyVehicle() {
	// clean-up added shapes
	for (int i = 0; i < shapes.size(); i++) {
		shapes.pop_back();
	}
}


void MyVehicle::draw() {
	// move to the vehicle’s local frame of reference
	glPushMatrix();
	positionInGL();
	// all the local drawing code
	Cylinder w1(-8.0, 1.0, 5, 1.0, 0.3, 0, 1.0, 1.0, 0.0);
	w1.draw();
	Cylinder w2(-4.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w2.draw();
	Cylinder w3(-8.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w3.draw();
	Cylinder w4(-4.0, 1.0, 5, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w4.draw();
	glRotated(-90.0, 0.0, 1.0, 0.0);

	RectangularPrism body(2.5, 1.0, 5.5, 5.0, 2.0, 8.0, 0.0, 0.0, 1.0, 0.0);
	body.draw();

	TrapezoidalPrism top(2.5, 3.0, 4.0, 3.0, 2.0, 4.0, 1.3, 0.5, 0.0);
	top.setColor(0.0, 1.0, 1.0);
	top.setColorInGL();
	top.draw();
	
	TriangularPrism trig(2.5, 4.3, 4.1, 1.0, 0.5, 30.0, 1.5, 0.0);
	trig.setColor(1.0, 1.0, 0.1);
	trig.setColorInGL();
	trig.draw();

	// move back to global frame of reference
	glPopMatrix();
}