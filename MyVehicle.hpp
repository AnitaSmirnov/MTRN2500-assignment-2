#pragma once
#include "Vehicle.hpp"
#include "Shape.hpp"

class MyVehicle : public Vehicle {
public:
	MyVehicle();
	~MyVehicle();
	void draw();
};