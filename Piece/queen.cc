#include "queen.h"

Queen::Queen(Colour c, Cell* ce)
: Piece(c, ce) {}

Queen::~Queen() {}

PieceName Queen::getPieceName() const
{
    return PieceName::Q;
}

bool Queen::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;
    auto pos = cell->getPos();

    DIR dir = getDIR(pos, to);
    // any dir other than NA is good
    return dir != DIR::NA;
}
