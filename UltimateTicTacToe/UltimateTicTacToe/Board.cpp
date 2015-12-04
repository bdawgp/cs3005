//
//  Board.cpp
//  UltimateTicTacToe
//
//  Created by Bradyn Poulsen on 5/1/15.
//  Copyright (c) 2015 Bradyn Poulsen. All rights reserved.
//

#include "Board.h"

//////////////////
// Constructors //
//////////////////

Board::Board(double xIn, double yIn, double sizeIn)
: Grid(xIn, yIn, sizeIn), mOccupied(0), mClaimedBy(-1), mPlayable(true), mLatestTile(-1)
{
    std::vector<Square *> locations = Grid::getLocations();
    std::vector<Square *>::iterator it;
    
    Tile * tilePtr;
    for(it = locations.begin(); it != locations.end(); it++)
    {
        tilePtr = new Tile(**it);
        mTiles.push_back(tilePtr);
    }
    
    Square::destroy(locations);
}

Board::Board(Square squareIn)
: Board(squareIn.getX(), squareIn.getY(), squareIn.getSize())
{}

////////////////
// Destructor //
////////////////

Board::~Board()
{
    std::vector<Tile *>::iterator it;
    for(it = mTiles.begin(); it != mTiles.end(); ++it)
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

bool Board::isFull() const
{
    return mOccupied >= 9;
}

int Board::getLatestTile() const
{
    return mLatestTile;
}

int Board::getClaimedBy() const
{
    return mClaimedBy;
}

void Board::draw(bool skipColorsIn) const
{
    if(mPlayable || skipColorsIn)
    {
        switch(mClaimedBy)
        {
            case 0:
            case 1:
                glColor3d(mClaimedBy,!mClaimedBy,0); // forground color
                break;
            default:
                glColor3d(skipColorsIn,1,1); // forground color
                break;
        }
    }
    else if(!skipColorsIn)
    {
        glColor3d(0,0,0); // forground color
    }
    
    Grid::draw();
    
    std::vector<Tile *>::const_iterator it;
    for(it = mTiles.begin(); it != mTiles.end(); it++)
    {
        (*it)->draw(mClaimedBy);
    }
}

void Board::setPlayable(bool playableIn)
{
    mPlayable = playableIn && mOccupied < 9;
}

bool Board::click(double xIn, double yIn, int currentPlayerIn)
{
    if(mPlayable && mOccupied < 9 && Square::contains(xIn, yIn))
    {
        std::vector<Tile *>::iterator it;
        for(it = mTiles.begin(); it != mTiles.end(); it++)
        {
            if((*it)->click(xIn, yIn, currentPlayerIn))
            {
                mOccupied++;
                mPlayable = mOccupied < 9;
                mLatestTile = (int)(it - mTiles.begin());
                this->checkWinner();
                return true;
            }
        }
    }
    
    mLatestTile = -1;
    
    return false;
}

void Board::checkWinner()
{
    if(mClaimedBy < 0)
    {
        Tile * tile1Ptr, * tile2Ptr, * tile3Ptr;
        
        int i;
        for(i = 0; i < 8; i++)
        {
            tile1Ptr = mTiles.at(mWinningCombos[i][0]);
            tile2Ptr = mTiles.at(mWinningCombos[i][1]);
            tile3Ptr = mTiles.at(mWinningCombos[i][2]);
            
            if(tile1Ptr->getOccupiedBy() >= 0 && tile1Ptr->getOccupiedBy() == tile2Ptr->getOccupiedBy() && tile2Ptr->getOccupiedBy() == tile3Ptr->getOccupiedBy())
            {
                mClaimedBy = tile1Ptr->getOccupiedBy();
                break;
            }
        }
    }
}