#include "knight.h"

Knight::Knight(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

Knight::~Knight() {}

PieceName Knight::getPieceName() const
{
    return PieceName::N;
}

bool Knight::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;

    // 2 cases
    if ((abs(pos.r - to.r) == 2 && abs(pos.c - to.c) == 1)
        || (abs(pos.r - to.r) == 1 && abs(pos.c - to.c) == 2))
        return true;
    
    return false;
}
