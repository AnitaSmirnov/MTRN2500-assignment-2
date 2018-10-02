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
	double x_, y_, z_;
	double wheelRotate = 0;
	// move to the vehicle’s local frame of reference
	for (int i = 0; i < shapes.size(); i++) {
		glPushMatrix();
		positionInGL();
		Cylinder *c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c != nullptr) { 
			x_ = c->getX();
			y_ = c->getY();
			z_ = c->getZ();	
			double rotation = getRotation();
			double speed = getSpeed();
			if (speed != 0 && c->getRoll()) {
				static double previousTime = getTime();
				const double currTime = getTime();
				const double elapsedTime = currTime - previousTime;
				double distance = speed * elapsedTime;
				//double distance = speed * 0.2;
				wheelRotate = wheelRotate - distance*4;
				glTranslated(x_, y_, z_);
				glRotated(wheelRotate, 0, 0, 1);
				glTranslated(-x_, -y_, -z_);
			}

			if ((c->getSteer())) c->setRotation(steering);
			}
		

		shapes[i]->draw();
		glPopMatrix();
	}
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