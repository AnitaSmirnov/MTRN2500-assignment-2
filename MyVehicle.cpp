//
// Created by Anita Smirnov on 04/09/18
// 

#include "MyVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"


MyVehicle::MyVehicle() {
	//front right wheel
	Shape *s = new Cylinder(-4.0, 1.0, 5.0, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3);
	shapes.push_back(s);
	//front left wheel
	s = new Cylinder(-4.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3);
	shapes.push_back(s);

	s = new Cylinder(-8.0, 1.0, -0.2, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3);
	shapes.push_back(s);
	
	s = new Cylinder(-8.0, 1.0, 5.0, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3);
	shapes.push_back(s);

	s = new RectangularPrism(2.5, 1.0, 5.5, 5.0, 2.0, 8.0, -90.0, 1.0, 0.3, 0.3);
	shapes.push_back(s);
	
	s = new TrapezoidalPrism(2.5, 3.0, 4.0, 3.0, 2.0, 4.0, 1.3, 0.5, -90.0, 0.4, 0.6, 1.0);
	shapes.push_back(s);

	s = new TriangularPrism(2.5, 4.3, 4.1, 1.0, 0.5, 30.0, 1.5, -90.0, 0.7, 0.7, 0.9);
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
	for (int i = 0; i < shapes.size(); i++) {
		glPushMatrix();
		positionInGL();

		Cylinder *c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c != nullptr) { 
			// !(steer)
			c->setRotation(steering);

		}
		

		shapes[i]->draw();
		glPopMatrix();
	}

	//std::cout << shapes.size() << std::endl;
	/*
	Cylinder w1(-8.0, 1.0, 5, 1.0, 0.3, 0, 1.0, 1.0, 0.0);
	w1.draw();
	Cylinder w2(-4.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w2.draw();
	Cylinder w3(-8.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w3.draw();
	Cylinder w4(-4.0, 1.0, 5, 1.0, 0.3, 0.0, 1.0, 1.0, 0.0);
	w4.draw();*/
	//glRotated(-90.0, 0.0, 1.0, 0.0);

	//RectangularPrism body(2.5, 1.0, 5.5, 5.0, 2.0, 8.0, 0.0, 0.0, 1.0, 0.0);
	//body.draw();
	/*
	TrapezoidalPrism top(2.5, 3.0, 4.0, 3.0, 2.0, 4.0, 1.3, 0.5, 0.0);
	top.setColor(0.4, 0.5, 1.0);
	top.setColorInGL();
	top.draw();
	
	TriangularPrism trig(2.5, 4.3, 4.1, 1.0, 0.5, 30.0, 1.5, 0.0);
	trig.setColor(1.0, 0.3, 0.1);
	trig.setColorInGL();
	trig.draw();
	*/
	// move back to global frame of reference
	glPopMatrix();
}