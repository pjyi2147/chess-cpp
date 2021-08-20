#include "pawn.h"
#include "../Board/board.h"

Pawn::Pawn(Coord p, Colour c, Cell* ce)
: Piece(p, c, ce) {}

Pawn::~Pawn() {}

PieceName Pawn::getPieceName() const
{
    return PieceName::P;
}

bool Pawn::isValidMove(Coord to) const
{
    // check basics 
    if (!Piece::isValidMove(to)) return false;
    auto pos = cell->getPos();
    // 2 cases
    DIR dir = getDIR(pos, to);
    // 1. forward
    if (dir == DIR::S || dir == DIR::N)
    {
        if (!isMoved() && abs(pos.r - to.r) == 2)
        {
            if (colour == Colour::B && dir == DIR::S) return true;
            else if (colour == Colour::W && dir == DIR::N) return true;
            else return false;
        }
        else if (abs(pos.r - to.r) == 1)
        {
            if (colour == Colour::B && dir == DIR::S) return true;
            else if (colour == Colour::W && dir == DIR::N) return true;
            else return false;
        }
        else return false;
    }
    // 2. capturing
    else if (abs(to.c - pos.c) == 1 && abs(to.r - pos.r) == 1)
    {
        // 2.1 enpassent (null)
        if (!cell->getBoard()->getPiece(to))
        {
            if (colour == Colour::B && (dir == DIR::SW || dir == DIR::SE))
            {
                auto f2PW = cell->getBoard()->getFirst2PawnW();
                if (!f2PW) return false;
                if (f2PW->getPostion() == Coord{pos.r, to.c}) return true;
                return false;
            }
            else if (colour == Colour::W && (dir == DIR::NW || dir == DIR::NE))
            {
                auto f2PB = cell->getBoard()->getFirst2PawnB();
                if (!f2PB) return false;
                if (f2PB->getPostion() == Coord{pos.r, to.c}) return true;
                return false;
            }
        }
        // 2.2 normal capture
        else if (colour == Colour::B && (dir == DIR::SW || dir == DIR::SE)) return true;
        else if (colour == Colour::W && (dir == DIR::NE || dir == DIR::NE)) return true;
    }
    return false;
}
