//
//  TriangularPrism.cpp
//  Assignment 2
//
//  Created by Alex Trung Vo on 4/9/18.
//  Copyright © 2018 Anita & Alex. All rights reserved.
//

#define RAD 3.14159/180

#include "TriangularPrism.hpp"

Triangular_Prism::Triangular_Prism() : Shape(0,0,0) { // default setters :)
    angle = 60.0;
    side_1 = side_2 = 10.0;
    depth = 0.0;
}

Triangular_Prism::TriangularPrism(double x_, double y_, double z_, double side1, double side2, double angle_, double depth_) : Shape(x,y,z){
    side_1 = side1;
    side_2 = side2;
    angle = angle_;
    depth = depth_;
};

TriangularPrism::~TriangularPrism(){
};

void Triangular_Prism::draw(){
    
    glPushMatrix();
    positionInGL();
    
    // x+ to the left , y+ up in the air , z+ into screen
    setColorInGL();
    
    glBegin(GL_TRIANGLES);
    
    //front
    glVertex3d( side_1/2,0,-depth_prism/2);
    glVertex3d(-side_1/2,0,-depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth_prism/2);
    
    //back
    glVertex3d(side_1/2,0,depth_prism/2);
    glVertex3d(-side_1/2,0,depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth_prism/2);
    
    glEnd();
    
    glBegin(GL_QUADS);
    
    //bottom
    glVertex3d(-side_1/2,0,depth_prism/2);
    glVertex3d(-side_1/2,0,-depth_prism/2);
    glVertex3d(side_1/2,0,-depth_prism/2);
    glVertex3d(side_1/2,0,depth_prism/2);
    
    //roof1
    glVertex3d((side_1)/2,0,-depth_prism/2);
    glVertex3d(side_1/2,0,depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth_prism/2);
    
    //roof2
    glVertex3d(-side_1/2,0,-depth_prism/2);
    glVertex3d(-side_1/2,0,depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),depth_prism/2);
    glVertex3d(side_1/2 + side_2*cos(angle*RAD),side_2*sin(angle*RAD),-depth_prism/2);
    glEnd();
    
    glPopMatrix();
};
