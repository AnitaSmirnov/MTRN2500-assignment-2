#pragma once
#include "Vehicle.hpp"
#include "Shape.hpp"

class MyVehicle : public Vehicle {
public:
	MyVehicle();
	~MyVehicle();
	void draw();
	virtual void update(double speed_, double steering_, double dt);
protected:
	double wheelAngle = 0;
};