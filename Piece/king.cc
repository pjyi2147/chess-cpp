#include "king.h"
#include "../Board/cell.h"
#include "../Board/board.h"


King::King(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

King::~King() {}

PieceName King::getPieceName() const
{
    return PieceName::K;
}

bool King::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;
    
    // 2 things to check: original move & castling
    // 1. original move
    if (abs(pos.r - to.r) <= 1 && abs(pos.c - to.c) <= 1) return true;
    // 2. castling
    else if (abs(pos.c - to.c) == 2 && abs(pos.r - to.r) == 0 && !isMoved())
    {
        auto bo = cell->getBoard();
        Coord bsize = bo->getSize();
        // kingside 
        if (pos.c - to.c < 0)
        {
            auto rk = bo->getPiece(Coord{pos.r, bsize.c-1});
            // 1. rook exists 2. rook not moved 3. no pieces between rook and king
            if (rk && !rk->isMoved() && rk->getColour() == colour && bo->isBlocked(pos, rk->getPostion()))
            {
                // 4. no checkes
                if (!bo->isThreatened(Coord{pos.r, pos.c+1}, colour) 
                    && !bo->isThreatened(Coord{pos.r, pos.c+2}, colour)) return true;
            }
            return false;
        }
        // queenside
        else 
        {
            auto rk = bo->getPiece(Coord{pos.r, 0});
            if (rk && !rk->isMoved() && rk->getColour() == colour && bo->isBlocked(pos, rk->getPostion()))
            {
                // 4. no checkes
                if (!bo->isThreatened(Coord{pos.r, pos.c-1}, colour) 
                    && !bo->isThreatened(Coord{pos.r, pos.c-2}, colour)) return true;
            }
            return false;
        }
    }
    // otherwise not valid
    else false;
}
