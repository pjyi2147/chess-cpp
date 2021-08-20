#include "rook.h"

Rook::Rook(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

Rook::~Rook() {}

PieceName Rook::getPieceName() const
{
    return PieceName::R;
}

bool Rook::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;
    auto pos = cell->getPos();
    
    DIR dir = getDIR(pos, to);
    // NESW then it is good
    return dir == DIR::N || dir == DIR::E || dir == DIR::S || dir == DIR::W;
}
