//
//  Wheels.hpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 5/10/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifndef Wheels_hpp
#define Wheels_hpp

#pragma once

#include <stdio.h>
#include "Shape.hpp"
#include "Cylinder.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class Wheels : public Cylinder {
protected:
    int spoke;
    int sides;
    // Shapetype s;    i dont know what the type is
public:
    Wheels();
    Wheels(double x_, double y_, double z_, double radius_, double depth_, double rotation_, float red_, float green_, float blue_, bool roll_, bool steer_, int spoke_, int sides_);
    ~Wheels();
    void draw();
    
    int getSpoke();
    int getSides();
    
};

#endif /* Wheels_hpp */
