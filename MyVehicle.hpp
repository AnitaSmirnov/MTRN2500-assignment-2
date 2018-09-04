//
//  MyVehicle.hpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 5/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifndef MyVehicle_hpp
#define MyVehicle_hpp

#include <stdio.h>
#include "Vehicle.hpp"

class MyVehicle : public Vehicle {
public:
    MyVehicle();
    MyVehicle(double x_, double y_, double z_, double rotation_);
    ~MyVehicle();
    void draw();
    //protected:
    
};
#endif /* MyVehicle_hpp */
