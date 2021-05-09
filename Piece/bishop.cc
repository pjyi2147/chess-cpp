#include "bishop.h"

Bishop::Bishop(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

Bishop::~Bishop() {}

PieceName Bishop::getPieceName() const
{
    return PieceName::B;
}

bool Bishop::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;

    // diagonal then it is good
    return (abs(pos.r-to.r) == abs(pos.c-to.c));
}
