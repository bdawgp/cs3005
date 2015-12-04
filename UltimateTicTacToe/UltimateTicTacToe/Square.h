//
//  Square.h
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#ifndef __UltimateTicTacToe__Square__
#define __UltimateTicTacToe__Square__

#ifdef _WIN32
    #include "glut.h"
#else
    #ifdef __APPLE__
        #include <GLUT/glut.h>
    #else
        #include <GL/glut.h>
    #endif
#endif

#include <vector>
#include <iostream>

class Square
{
protected:
    double mStartX;
    double mStartY;
    double mSize;
    
public:
    Square(double xIn, double yIn, double sizeIn);
    void draw() const;
    bool contains(double x, double y) const;
    void adjust(double dxIn, double dyIn, double dsizeIn);
    
    void destroy(std::vector<Square *> &squaresIn) const;
    
    double getX() const;
    double getY() const;
    double getSize() const;
    
//    virtual void click(double xIn, double yIn);
};

#endif /* defined(__UltimateTicTacToe__Square__) */
