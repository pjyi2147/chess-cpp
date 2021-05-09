#include "piece.h"
#include "Board/cell.h"
#include "Board/board.h"

Piece::Piece(Coord p, Colour c, Cell* ce) 
: pos{p}, colour{c}, cell{ce}, moveCount{0} {}

Colour Piece::getColour() const
{
    return colour;
}

Coord Piece::getPostion() const
{
    return pos;
}

void Piece::setPosition(Coord c)
{
    pos = c;
}

bool Piece::isValidMove(Coord to) const
{
    // not connected to any cell
    if (!cell) return false;

    // is the same location?
    if (pos == to) return false;

    // check out of bounds
    Coord bsize = cell->getBoard()->getSize();
    // is this piece inside the board?
    if (pos.r < 0 || pos.c < 0 || pos.r >= bsize.r || pos.c >= bsize.c)
        return false;
    
    // is destination inside the board?
    if (to.r < 0 || to.c < 0 || to.r >= bsize.r || to.c >= bsize.c)
        return false;
    
    // is tocell has a same colour piece?
    auto topiece = cell->getBoard()->getPiece(to);
    if (!topiece || colour == topiece->getColour()) return false;

    // check blockage
    DIR d = getDIR(pos, to);
    if (!cell->getBoard()->isBlocked(pos, to)) return false;

    // what else?
    
    // upto here it is valid
    return true;
}

bool Piece::isMoved() const
{
    return moveCount > 0;
}

void Piece::addMoveCount()
{
    moveCount += 1;
}

void Piece::decMoveCount()
{
    if (moveCount > 0) moveCount -= 1;
}
