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

MyVehicle::MyVehicle() {
	//front right wheel
	Shape *s = new Cylinder(-4.0, 1.0, 5.0, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);
	//front left wheel
	s = new Cylinder(-4.0, 1.0, -0.2, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);

	s = new Cylinder(-8.0, 1.0, -0.2, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
	shapes.push_back(s);
	
	s = new Cylinder(-8.0, 1.0, 5.0, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
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
				
				/*
				if (c->getRoll()) {
					static double previousTime = getTime();
					const double currTime = getTime();
					const double elapsedTime = currTime - previousTime;
					double distance = speed * elapsedTime;
					double wheelRotate = distance / (2 * PI);
					glPushMatrix();
					glTranslated(5, 1, 5);
					glRotated(wheelRotate, .7, 0, .4);
					glPopMatrix();
				}*/

				if ((c->getSteer())) c->setRotation(steering);
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

double MyVehicle::getTime() {
#if defined(WIN32)
	LARGE_INTEGER freqli;
	LARGE_INTEGER li;
	if (QueryPerformanceCounter(&li) && QueryPerformanceFrequency(&freqli)) {
		return double(li.QuadPart) / double(freqli.QuadPart);
	}
	else {
		static ULONGLONG start = GetTickCount64();
		return (GetTickCount64() - start) / 1000.0;
	}
#else
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec + (t.tv_usec / 1000000.0);
#endif
}