//
//  Game.h
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#ifndef __UltimateTicTacToe__Game__
#define __UltimateTicTacToe__Game__

#include <vector>
#include "Grid.h"
#include "Board.h"

class Game : public Grid
{
    std::vector<Board *> mBoards;
    bool mActive;
    int mCurrentPlayer;
    
public:
    Game(double xIn, double yIn, double sizeIn);
    Game(Square squareIn);
    ~Game();
    void draw() const;
    void checkWinner();
    
    void setPlayableBoard(int indexIn);
    bool click(double xIn, double yIn);
};

#endif /* defined(__UltimateTicTacToe__Game__) */
