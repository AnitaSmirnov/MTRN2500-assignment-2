//
//  Cylinder.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
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

#include "Cylinder.hpp"

Cylinder::Cylinder() : Shape(0,0,0){
    radius = 5.0;
    depth = 1.0;
};

Cylinder::Cylinder(double x_, double y_, double z_, double radius_, double depth_) : Shape(x_,y_,z_){
    radius = radius_;
    depth = depth_;
};

Cylinder::~Cylinder(){
};

void Cylinder::draw(){
    glPushMatrix();
    positionInGL();
    glColor3d(red, green, blue);
    
    GLUquadricObj *q = gluNewQuadric();
    
    glTranslated(0, radius, -depth/2);
    int n = 30;
    
    gluCylinder(q, radius, radius, depth, n, n);
    gluDisk(q, 0, radius, n, n);
};