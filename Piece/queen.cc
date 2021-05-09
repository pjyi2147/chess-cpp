#include "queen.h"

Queen::Queen(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

Queen::~Queen() {}

PieceName Queen::getPieceName() const
{
    return PieceName::Q;
}

bool Queen::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;

    DIR dir = getDIR(pos, to);
    // any dir other than NA is good
    return dir != DIR::NA;
}
