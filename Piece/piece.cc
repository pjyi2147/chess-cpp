#include "piece.h"
#include "../Board/cell.h"
#include "../Board/board.h"

Piece::Piece(Colour c, Cell* ce) 
: colour{c}, cell{ce}, moveCount{0} {}

Colour Piece::getColour() const
{
    return colour;
}

void Piece::setCell(Cell* c)
{
    cell = c;
}
bool Piece::isValidMove(Coord to) const
{
    // not connected to any cell
    if (!cell) return false;
    Coord pos = cell->getPos();
    
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
    if (!cell->getBoard()->isBlocked(pos, to)) return false;

    // what else?
    
    // if passes all then it is valid
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
