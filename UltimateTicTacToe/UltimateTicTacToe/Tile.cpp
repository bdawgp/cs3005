//
//  Tile.cpp
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include "Tile.h"

//////////////////
// Constructors //
//////////////////

Tile::Tile(double xIn, double yIn, double sizeIn)
: Square(xIn, yIn, sizeIn), mOccupiedBy(-1)
{
    
}

Tile::Tile(Square squareIn)
: Tile(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{}

/////////////
// Private //
/////////////

////////////
// Public //
////////////

int Tile::getOccupiedBy() const
{
    return this->mOccupiedBy;
}

void Tile::draw(int claimedPlayerIn) const
{
    if(mOccupiedBy >= 0)
    {
        char letter = mOccupiedBy == 0 ? 'O' : 'X';
        if(claimedPlayerIn < 0)
        {
            glColor3d(mOccupiedBy, !mOccupiedBy, 0);
        }
        else
        {
            glColor3d(claimedPlayerIn, !claimedPlayerIn, 0);
        }
        
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);
        
        double offset = (mSize - 20) / 2;
        
        glRasterPos2d(mStartX + offset, mStartY + offset);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        
        glDisable(GL_BLEND);
    }
}

bool Tile::click(double xIn, double yIn, int currentPlayerIn)
{
    if(mOccupiedBy < 0 && Square::contains(xIn, yIn))
    {
        mOccupiedBy = currentPlayerIn;
        return true;
    }
    
    return false;
}