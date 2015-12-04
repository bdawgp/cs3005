//
//  Game.cpp
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include "Game.h"

//////////////////
// Constructors //
//////////////////

Game::Game(double xIn, double yIn, double sizeIn)
: Grid(xIn, yIn, sizeIn), mActive(true), mCurrentPlayer(0)
{
    std::vector<Square *> locations = Grid::getLocations();
    std::vector<Square *>::iterator it;
    
    Board * boardPtr;
    for(it = locations.begin(); it != locations.end(); it++)
    {
        boardPtr = new Board(**it);
        boardPtr->adjust(1, 1, -2);
        mBoards.push_back(boardPtr);
    }
    
    Square::destroy(locations);
}

Game::Game(Square squareIn)
: Game(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{}

////////////////
// Destructor //
////////////////

Game::~Game()
{
    // Delete board pointers
    std::vector<Board *>::iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); ++it)
    {
        delete *it;
    }
}

/////////////
// Private //
/////////////

////////////
// Public //
////////////

void Game::draw() const
{
    if(mActive)
    {
        glColor3d(0,0,0); // forground color
        
        std::string title = "Player ";
        title += mCurrentPlayer == 0 ? 'O' : 'X';
        title += "'s Turn";
        glutSetWindowTitle(title.c_str());
    }
    else
    {
        glColor3d(mCurrentPlayer,!mCurrentPlayer,0);
        
        if(mCurrentPlayer >= 0)
        {
            std::string title = "PLAYER ";
            title += mCurrentPlayer == 0 ? 'O' : 'X';
            title += " WINS";
            glutSetWindowTitle(title.c_str());
        }
        else
        {
            glutSetWindowTitle("PLAYERS TIED");
        }
    }
    
    Grid::draw();
    
    std::vector<Board *>::const_iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); ++it)
    {
        (*it)->draw(!mActive);
    }
}

void Game::setPlayableBoard(int indexIn)
{
    Board * targetBoardPtr = mBoards.at(indexIn);
    bool allBoardsPlayable = targetBoardPtr->isFull();
    
    std::vector<Board *>::iterator it;
    for(it = mBoards.begin(); it != mBoards.end(); it++)
    {
        (*it)->setPlayable(allBoardsPlayable);
    }
    
    targetBoardPtr->setPlayable(!allBoardsPlayable);
}

bool Game::click(double xIn, double yIn)
{
    std::cout << std::endl;
    
    if(mActive && Square::contains(xIn, yIn))
    {
        std::vector<Board *>::iterator it;
        for(it = mBoards.begin(); it != mBoards.end(); it++)
        {
            if((*it)->click(xIn, yIn, mCurrentPlayer))
            {
                mCurrentPlayer = (++mCurrentPlayer) % 2;
                this->setPlayableBoard((*it)->getLatestTile());
                this->checkWinner();
                return true;
            }
        }
    }
    
    return false;
}

void Game::checkWinner()
{
    if(mActive)
    {
        // Check Winning Patterns
        
        Board * board1Ptr, * board2Ptr, * board3Ptr;
        int i;
        for(i = 0; i < 8; i++)
        {
            board1Ptr = mBoards.at(mWinningCombos[i][0]);
            board2Ptr = mBoards.at(mWinningCombos[i][1]);
            board3Ptr = mBoards.at(mWinningCombos[i][2]);
            
            if(board1Ptr->getClaimedBy() >= 0 && board1Ptr->getClaimedBy() == board2Ptr->getClaimedBy() && board2Ptr->getClaimedBy() == board3Ptr->getClaimedBy())
            {
                mActive = false;
                mCurrentPlayer = board1Ptr->getClaimedBy();
                return;
            }
        }
        
        // Check for a tie
        
        std::vector<Board *>::iterator it;
        for(it = mBoards.begin(); it != mBoards.end(); it++)
        {
            if(!(*it)->isFull())
            {
                // if any of the boards aren't full, game can continue
                return;
            }
        }
        
        mActive = false;
        mCurrentPlayer = -1;
    }
}