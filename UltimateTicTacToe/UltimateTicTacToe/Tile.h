//
//  Tile.h
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#ifndef __UltimateTicTacToe__Tile__
#define __UltimateTicTacToe__Tile__

#include "Square.h"

class Tile : public Square
{
    int mOccupiedBy;
    
public:
    Tile(double xIn, double yIn, double sizeIn);
    Tile(Square squareIn);
    void draw(int claimedPlayerIn) const;
    int getOccupiedBy() const;
    
    bool click(double xIn, double yIn, int currentPlayerIn);
};

#endif /* defined(__UltimateTicTacToe__Tile__) */
