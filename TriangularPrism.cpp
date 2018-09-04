//
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
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif

#define RAD 3.14159/180
#include <math.h>
#include "TriangularPrism.hpp"

TriangularPrism::TriangularPrism() : Shape(0,0,0) { // default setters :)
    angle = 90.0;
    side_1 = side_2 = 10.0;
    depth = rotation = 0.0;
};

TriangularPrism::TriangularPrism(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_, double rotation_) : Shape(x_,y_,z_){
    side_1 = side1;
    side_2 = side2;
    angle = angle_;
    depth = depth_;
    rotation = rotation_;
};

TriangularPrism::~TriangularPrism(){
};

void TriangularPrism::draw(){
    
    glTranslated(0.0, 0.0 , 0.0);
    glRotated(rotation, 0.0, 0.0, 0.0);
    
    glPushMatrix();
    positionInGL();
    
    // x+ to the left , y+ up in the air , z+ into screen
    setColorInGL();
    
    glBegin(GL_TRIANGLES);
    
    //front
    glVertex3d( side_1/2,0,-depth/2);
    glVertex3d(-side_1/2,0,-depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth/2);
    
    //back
    glVertex3d(side_1/2,0,depth/2);
    glVertex3d(-side_1/2,0,depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth/2);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
    //bottom
    glVertex3d(-side_1/2,0,depth/2);
    glVertex3d(-side_1/2,0,-depth/2);
    glVertex3d(side_1/2,0,-depth/2);
    glVertex3d(side_1/2,0,depth/2);
    
    //roof1
    glVertex3d((side_1)/2,0,-depth/2);
    glVertex3d(side_1/2,0,depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth/2);
    
    //roof2
    glVertex3d(-side_1/2,0,-depth/2);
    glVertex3d(-side_1/2,0,depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth/2);
    glEnd();
    
    glPopMatrix();
};
