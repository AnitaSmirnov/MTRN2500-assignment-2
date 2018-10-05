//
//  Wheels.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 5/10/18.
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
#endif

#include "Cylinder.hpp"
#include "Wheels.hpp"

#include "KeyManager.hpp"

Wheels::Wheels() {
    x = z = rotation = 0.0;
    y = 0.5;
    radius = 5.0;
    depth = 1.0;
    red = blue = green = 1.0;
    roll = steer = true;
}

Wheels::Wheels(double x_, double y_, double z_, double radius_, double depth_, double rotation_, float red_, float green_, float blue_, bool roll_, bool steer_, int spoke_, int sides_) {
    x = x_;
    y = y_;
    z = z_;
    rotation = rotation_;
    radius = radius_;
    depth = depth_;
    red = red_;
    green = green_;
    blue = blue_;
    roll = true;
    steer = true;
    spoke = spoke_;
    sides = sides_;
    
}

Wheels::~Wheels() {
}

void Wheels::draw() {
    glColor3f(red, green, blue);
    int n = sides;
    glPushMatrix();
    glTranslated(x, y + radius, z);
    glRotated(rotation, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    GLUquadric * q = gluNewQuadric();
    gluCylinder(q, radius, radius, depth, n, n);
    gluDisk(q, 0, radius, n, n);
    glTranslated(0, 0, depth);
    gluDisk(q, 0, radius, n, n);
    glEnd();
    glPopMatrix();
}

int Wheels::getSpoke(){
    return spoke;
}
int Wheels::getSides(){
    return sides;
}
