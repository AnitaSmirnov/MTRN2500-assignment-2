//
//  TriangularPrism.hpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifndef TriangularPrism_hpp
#define TriangularPrism_hpp
#include "Shape.hpp"

class TriangularPrism : public Shape{
    
protected:
    
    double side_1;
    double side_2;
    double angle; // angle between side 1 and side 2
    double depth;
    double rotation;

    
public:
    TriangularPrism();
    TriangularPrism(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_, double rotation_,float red_, float green_, float blue_);
    ~TriangularPrism();
    void draw();
    
    float getALen();
    float getBLen();
    float getAngle();
    float getDepth();
};

#endif /* TriangularPrism_hpp */
