//
//  Board.h
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#ifndef __UltimateTicTacToe__Board__
#define __UltimateTicTacToe__Board__

#include <vector>
#include "Grid.h"
#include "Tile.h"

class Board : public Grid
{
    std::vector<Tile *> mTiles;
    bool mPlayable;
    int mOccupied;
    int mLatestTile;
    int mClaimedBy;
    
    void checkWinner();
    
public:
    Board(double xIn, double yIn, double sizeIn);
    Board(Square squareIn);
    ~Board();
    bool isFull() const;
    int getLatestTile() const;
    int getClaimedBy() const;
    void draw(bool skipColorsIn) const;
    
    void setPlayable(bool playableIn);
    bool click(double xIn, double yIn, int currentPlayerIn);
};

#endif /* defined(__UltimateTicTacToe__Board__) */
