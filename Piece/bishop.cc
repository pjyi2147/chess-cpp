#include "bishop.h"

Bishop::Bishop(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

PieceName Bishop::getPieceName() const
{
    return PieceName::B;
}

bool Bishop::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;

    return (abs(pos.r-to.r) == abs(pos.c-to.c));
}
