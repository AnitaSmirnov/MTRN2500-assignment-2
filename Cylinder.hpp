//
//  Cylinder.hpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <stdio.h>
#include "Shape.hpp"

class Cylinder : public Shape{
protected:
    double radius;
    double depth;
    
public:
    Cylinder();
    Cylinder(double x, double y, double z, double radius_, double depth_, double rotation_);
    ~Cylinder();
    void draw();
};
#endif /* Cylinder_hpp */
