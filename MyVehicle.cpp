//
//  MyVehicle.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 5/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif

#include "MyVehicle.hpp"
#include "MyVehicle.hpp"
#include "RectangularPrism.hpp"
#include "TriangularPrism.hpp"
#include "TrapezoidalPrism.hpp"
#include "Cylinder.hpp"


MyVehicle::MyVehicle() {
    speed = steering = 0;
    
}

MyVehicle::MyVehicle(double x_, double y_, double z_, double rotation_) {
    //something
}

MyVehicle::~MyVehicle() {};


void MyVehicle::draw() {
    // move to the vehicle’s local frame of reference
    glPushMatrix();
    positionInGL();
    // all the local drawing code
    Cylinder w1(4.0, 0.0, -4.0, 1.0, 0.3, 0);
    w1.setColor(1.0, 0.0, 0.0);
    w1.setColorInGL();
    w1.draw();
//
//    Cylinder w2(-2.0, 0.0, 4.0, 1.0, 0.3, 0);
//    w2.setColor(1.0, 0.0, 0.0);
//    w2.setColorInGL();
//    w2.draw();

//    Cylinder w3(-4.0, 0.0, -4.0, 1.0, 0.3, 0);
//    w3.setColor(1.0, 0.0, 0.0);
//    w3.setColorInGL();
//    w3.draw();
//
//    Cylinder w4(4.0, 0.0, -4.0, 1.0, 0.3, 0);
//    w4.setColor(1.0, 0.0, 0.0);
//    w4.setColorInGL();
//    w4.draw();
    
    RectangularPrism body(0.0, 0.0, 0.0, 10.0, 6.0, 8.0, 0.0);
    body.setColor(0.0, 0.0, 1.0);
    body.setColorInGL();
    body.draw();
    
//    TrapezoidalPrism top(1.0, 6.0, 2.0, 1.0, 3.0, 0.0);
//    top.setColor(0.0, 1.0, 1.0);
//    top.setColorInGL();
//    top.draw();

    TriangularPrism trig(-10.0, 0.0, 0.0, 10.0, 4.0, 90.0, 8.0, 0.0);
    trig.setColor(1.0, 1.0, 0.0);
    trig.setColorInGL();
    trig.draw();
    
    
    
    // move back to global frame of reference
    glPopMatrix();
}
