//  TriangularPrism.cpp
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
#endif
/*#else
#include <unistd.h>
#include <sys/time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <math.h>*/
#include <cmath>
#include "TriangularPrism.hpp"

#define RAD 3.14159/180

TriangularPrism::TriangularPrism() { // default setters :)
	x = y = z = rotation = 0.0;
	angle = 60.0;
    side_1 = side_2 = 10.0;
    depth = 0.0;
}

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_, double rotation_) {
	x = x_;
	y = y_;
	z = z_;
	rotation = rotation_;
	side_1 = side1;
    side_2 = side2;
    angle = angle_;
    depth = depth_;
}

TriangularPrism::~TriangularPrism() {
}

void TriangularPrism::draw() {
    
    glPushMatrix();
    //positionInGL();
    
    // x+ to the left , y+ up in the air , z+ into screen
    //setColorInGL();
    
    glBegin(GL_TRIANGLES);
    
    // front
    glVertex3d(x + side_1/2, y, z + depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD), y + side_2*sin(angle*RAD), z + depth/2);
	glVertex3d(x - side_1 / 2, y, z + depth / 2);

    // back
    glVertex3d(x + side_1/2, y, z - depth/2);
    glVertex3d(x - side_1/2, y, z - depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD),y + side_2*sin(angle*RAD),z - depth/2);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
    // bottom
    glVertex3d(x + side_1/2, y, z - depth/2);
    glVertex3d(x + side_1/2, y, z + depth/2);
    glVertex3d(x - side_1/2, y, z + depth/2);
    glVertex3d(x - side_1/2, y, z - depth/2);

    // roof 1
    glVertex3d(x + side_1/2, y, z - depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD), y + side_2*sin(angle*RAD), z - depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD), y + side_2*sin(angle*RAD), z + depth/2);
	glVertex3d(x + side_1 / 2, y, z + depth/2);
    
    // roof 2
    glVertex3d(x - side_1/2, y, z + depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD), y + side_2*sin(angle*RAD), z + depth/2);
    glVertex3d(x - side_1/2 + side_2*cos(angle*RAD), y + side_2*sin(angle*RAD), z - depth/2);
	glVertex3d(x - side_1 / 2, y, z - depth/2);

    glEnd();
    
    glPopMatrix();
}