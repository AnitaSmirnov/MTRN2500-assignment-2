//
//  FlipTriangle.hpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 10/10/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifndef FlipTriangle_hpp
#define FlipTriangle_hpp

#include "Shape.hpp"

class FlipTriangle : public Shape{
    
protected:
    
    double side_1;
    double side_2;
    double angle; // angle between side 1 and side 2
    double depth;
    double rotation;
    
public:
    FlipTriangle();
    FlipTriangle(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_, double rotation_, float red_, float green_, float blue_);
    ~FlipTriangle();
    void draw();
    
    float getALen();
    float getBLen();
    float getAngle();
    float getDepth();
};

#endif /* FlipTriangle_hpp */
