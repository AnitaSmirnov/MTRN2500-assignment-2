#pragma once
#include "Vehicle.hpp"
#include "Shape.hpp"
#include "Messages.hpp"

class MyVehicle : public Vehicle {
public:
	MyVehicle();
	MyVehicle(VehicleModel vm); 
	~MyVehicle();
	void draw();
	virtual void update(double speed_, double steering_, double dt);
	std::vector<Shape*> shapeVector();
protected:
	double wheelAngle = 0;
};