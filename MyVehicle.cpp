//
// Created by Anita Smirnov on 04/09/18
// Written by Anita Smirnov and Alex Trung Vo
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
	x = y = z = 0;
	//slender car with triangles instead of front wheels
	Shape *s = new Cylinder(-1.34, 0, -0.8, 0.39, 0.22, 0, 1, 1, 1, TRUE, FALSE);
	shapes.push_back(s);
	s = new Cylinder(-1.34, 0, 0.8, 0.39, 0.22, 0, 1, 1, 1, TRUE, FALSE);
	shapes.push_back(s);
	s = new Cylinder(-1.34, 0, 1.03, 0.35, 0.06, 0, .5, .2, .2, TRUE, FALSE);
	shapes.push_back(s);
	s = new Cylinder(-1.34, 0, -1.03, 0.35, 0.06, 0, .5, .2, .2, TRUE, FALSE);
	shapes.push_back(s);
	//body
	s = new RectangularPrism(0, 0.57, 0, 3.84, 0.09, 1.28, 0, 1, 0.82, 0.51);
	shapes.push_back(s);
	// top block
	s = new RectangularPrism(-1.19, 0.66, 0, 1.18, 0.65, 1.01, 0, 1, 0.1, 0);
	shapes.push_back(s);
	// trig
	s = new TriangularPrism(1.7, 0.3, 0, 0.595, 0.34, 73.4, 0.41, 0, 0.1, 0, 1);
	TriangularPrism *t = dynamic_cast<TriangularPrism*>(s);
	t->setZRotation(-73.4);
	shapes.push_back(t);


/*
	// truck with traperoidal prism in front
	//froint wheels
	Shape *s = new Cylinder(1.5, 0, -0.8, 0.4, 0.2, 0, 1, 1, 1, TRUE, TRUE);
	shapes.push_back(s);
	s = new Cylinder(1.5, 0, 0.8, 0.4, 0.2, 0, 1, 1, 1, TRUE, TRUE);
	shapes.push_back(s);
	//back wheels
	s = new Cylinder(-1.3, 0, -0.8, 0.4, 0.2, 0, 0.3, 0.3, 0.8, TRUE, FALSE);
	shapes.push_back(s);
	s = new Cylinder(-1.3, 0, 0.8, 0.4, 0.2, 0, 0.3, 0.3, 0.8, TRUE, FALSE);
	shapes.push_back(s);
	//back body
	s = new RectangularPrism(-0.6, 0.4, 0, 2.5, 1.4, 1.8, 0, 0.5, 0, 0);
	shapes.push_back(s);
	// rect joining ladder and body
	s = new RectangularPrism(-1.3, 1.8, 0, 0.4, 0.2, 0.7, 0, 0.1, 0.1, 0.1);
	shapes.push_back(s);
	// rect joining two segments
	s = new RectangularPrism(0.65, 0.6, 0, 0.5, 0.7, 0.7, 0, 0.4, 0.25, 0.25);
	shapes.push_back(s);
	//ladder
	s = new RectangularPrism(0.4, 2, 0, 4.2, 0.4, 0.7, 0, 0.3, 0.3, 0.3);
	shapes.push_back(s);
	//front
	s = new TrapezoidalPrism(1.5, 0.4, 0, 1.2, 0.6, 1.8, 1.4, 0, 0, 0, 0.5, 0.2);
	shapes.push_back(s);*/
	/*
	// our original vehicle
	//front right wheel
	Shape *s = new Cylinder(1.5, 0, 2.5, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);
	//front left wheel
	s = new Cylinder(1.5, 0, -2.8, 1.0, 0.3, 0.0, 1.0, 1.0, 0.3, TRUE, TRUE);
	shapes.push_back(s);

	s = new Cylinder(-2, 0, -2.8, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
	shapes.push_back(s);
	
	s = new Cylinder(-2, 0, 2.5, 1.0, 0.3, 0.0, 0.3, 1.0, 0.3, TRUE, FALSE);
	shapes.push_back(s);

	s = new RectangularPrism(0, 0.5, 0, 5, 2.0, 8.0, -90.0, 1.0, 0.3, 0.3);
	shapes.push_back(s);
	
	s = new TrapezoidalPrism(0, 2.5, -0.5, 3.0, 2.0, 4.0, 1.3, 0.5, -90.0, 0.4, 0.6, 1.0);
	shapes.push_back(s);

	s = new TriangularPrism(0, 3.8, -0.9, 1.0, 0.5, 30.0, 1.5, -90.0, 0.7, 0.7, 0.9);
	shapes.push_back(s);*/
}

MyVehicle::MyVehicle(VehicleModel vm) {
	Shape *s;
	ShapeInit it;
	for (int i = 0; i < vm.shapes.size(); i++) {
		it = vm.shapes[i];
		if (it.type == TRIANGULAR_PRISM) {
			s = new TriangularPrism(it.xyz[0], it.xyz[1], it.xyz[2], it.params.tri.alen, it.params.tri.blen, it.params.tri.angle, it.params.tri.depth, it.rotation, it.rgb[0], it.rgb[1], it.rgb[2]);
		}
		if (it.type == RECTANGULAR_PRISM) {
			s = new RectangularPrism(it.xyz[0], it.xyz[1], it.xyz[2], it.params.rect.xlen, it.params.rect.ylen, it.params.rect.zlen, it.rotation, it.rgb[0], it.rgb[1], it.rgb[2]);
		}
		if (it.type == TRAPEZOIDAL_PRISM) {
			s = new TrapezoidalPrism(it.xyz[0], it.xyz[1], it.xyz[2], it.params.trap.alen, it.params.trap.blen, it.params.trap.depth, it.params.trap.height, it.params.trap.aoff, it.rotation, it.rgb[0], it.rgb[1], it.rgb[2]);
		}
		if (it.type == CYLINDER) {
			s = new Cylinder(it.xyz[0], it.xyz[1], it.xyz[2], it.params.cyl.radius, it.params.cyl.depth, it.rotation, it.rgb[0], it.rgb[1], it.rgb[2], it.params.cyl.isRolling, it.params.cyl.isSteering);
		}
		shapes.push_back(s);
	}
	
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
	double x_, y_, z_, r_;
	for (int i = 0; i < shapes.size(); i++) {
		// move to the vehicle’s local frame of reference
		glPushMatrix();
		positionInGL();
		Cylinder *c = dynamic_cast<Cylinder*>(shapes[i]);
		if (c != nullptr) { 
			x_ = c->getX();
			y_ = c->getY();
			z_ = c->getZ();	
			r_ = (double)c->getRadius();
			if (speed != 0 && c->getRoll()) {
				c->setWheelRotation(wheelAngle / r_);
				/*
				glTranslated(x_, y_ + r_, z_);
				glRotated(wheelAngle/r_, 0, 0, 1);
				glTranslated(-x_, -y_ - r_, -z_);*/
			}

			if ((c->getSteer())) c->setRotation(-steering);
		}

		shapes[i]->draw();
		glPopMatrix();
	}
}

void MyVehicle::update(double speed_, double steering_, double dt) {
	Vehicle::update(speed_, steering_, dt);
	wheelAngle = wheelAngle - 6*PI*speed_*dt;
	while (wheelAngle > 1000) wheelAngle -= 1000;
	while (wheelAngle < -1000) wheelAngle += 1000;
}

std::vector<Shape*> MyVehicle::shapeVector() {
	return shapes;
}