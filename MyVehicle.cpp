//
// Created by Anita Smirnov on 04/09/18
// 

#include "MyVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"

#define PI 3.14159
#define RAD 3.1415926535 / 180.0

// constructs a MyVehicle object
MyVehicle::MyVehicle() {
	//front right wheel
	Shape *s = new Cylinder(1.5, 0.5, 2.5, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);
	//front left wheel
	s = new Cylinder(1.5, 0.5, -2.8, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);

	s = new Cylinder(-2, 0.5, -2.8, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
	shapes.push_back(s);
	
	s = new Cylinder(-2, 0.5, 2.5, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
	shapes.push_back(s);

	s = new RectangularPrism(0, 0, 0, 5, 2.0, 8.0, -90.0, 1.0, 0.3, 0.3);
	shapes.push_back(s);
	
	s = new TrapezoidalPrism(0, 2.0, -0.5, 3.0, 2.0, 4.0, 1.3, 0.5, -90.0, 0.4, 0.6, 1.0);
	shapes.push_back(s);

	s = new TriangularPrism(0, 3.3, -0.9, 1.0, 0.5, 30.0, 1.5, -90.0, 0.7, 0.7, 0.9);
	shapes.push_back(s);
	
}

// destructs a MyVehicle object
MyVehicle::~MyVehicle() {
	// clean-up added shapes
	for (int i = 0; i < shapes.size(); i++) {
		shapes.pop_back();
	}
}

// draws a MyVehicle object
void MyVehicle::draw() {
	double x_, y_, z_;
	for (int i = 0; i < shapes.size(); i++) {
		// move to the vehicle’s local frame of reference
		glPushMatrix();
		positionInGL();
		Cylinder *c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c != nullptr) { 
			x_ = c->getX();
			y_ = c->getY();
			z_ = c->getZ();	
			if (speed != 0 && c->getRoll()) {
				glTranslated(x_, y_, z_);
				glRotated(wheelAngle, 0, 0, 1);
				glTranslated(-x_, -y_, -z_);
			}

			if ((c->getSteer())) c->setRotation(steering);
		}

		shapes[i]->draw();
		glPopMatrix();
	}
}

void MyVehicle::update(double speed_, double steering_, double dt) {
	Vehicle::update(speed_, steering_, dt);
	wheelAngle = wheelAngle - 6*PI*speed_*dt;
	while (wheelAngle > 1000) wheelAngle -= 1000;
	while (wheelAngle < 1000) wheelAngle += 1000;
}