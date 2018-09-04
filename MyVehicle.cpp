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
	//something
}

MyVehicle::~MyVehicle() {
	// clean-up added shapes
	for (int i = 0; i < shapes.size(); i++) {
		delete shapes[i];
	}
}


void MyVehicle::draw() {
	// move to the vehicle’s local frame of reference
	glPushMatrix();
	positionInGL();
	// all the local drawing code
	RectangularPrism body(2.5, 1.0, 4.0, 5.0, 4.0, 8.0, 0.0);
	body.setColor(0.0, 1.0, 1.0);
	body.setColorInGL();
	body.draw();
	TrapezoidalPrism top(3.0, 2.0, 6.0, 2.0, 0.5, 0.0);
	top.setColor(0.0, 1.0, 1.0);
	top.setColorInGL();
	top.draw();

	TriangularPrism trig(1.7, 2.2, 4.0, 1.0, 0.5, 30.0, 2.0, 0.0);
	trig.setColor(1.0, 1.0, 0.1);
	trig.setColorInGL();
	trig.draw();

	// move back to global frame of reference
	glPopMatrix();
}