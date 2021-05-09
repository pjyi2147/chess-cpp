#include "board.h"
#include "cell.h"

Board::Board() {}
Board::Board(int y, int x) {}
Board::~Board() {}

void Board::initStandardChess() {}

// get functions
Colour Board::getTurn() const {}
Coord Board::getSize() const {}
Piece* Board::getPiece(Coord) const {}
Piece* Board::getFirst2PawnW() const {}
Piece* Board::getFirst2PawnB() const {}

// set functions
bool Board::setPiece(Coord t, PieceName p, Colour c) {}
void Board::setPlayerW(Player*) {}
void Board::setPlayerB(Player*) {}
void Board::setTurn(Colour) {}

// is private
bool Board::isCheckW() const {}
bool Board::isCheckB() const {}
bool Board::isCheckmateW() const {}
bool Board::isCheckmateB() const {}

bool Board::isValidMove(Coord f, Coord t) const {}
bool Board::isThreatened(Coord t, Colour c) const {}
bool Board::isCheck() const {}
bool Board::isCheckmate() const {}
bool Board::isStalemate() const 
{

}

bool Board::isBlocked(Coord f, Coord t) const 
{
    auto dir = getDIR(f, t);
    switch (dir)
    {
    case DIR::N:
        for (int i = 1; f.r + i < t.r; i++)
            if (!board[f.r + i][f.c]->getPiece()) return false;
        break;
    case DIR::S:
        for (int i = -1; f.r + i > t.r; i--)
            if (!board[f.r + i][f.c]->getPiece()) return false;
        break;
    case DIR::E:
        for (int i = 1; f.c + i < t.c; i++)
            if (!board[f.r][f.c + i]->getPiece()) return false;
        break;
    case DIR::W:
        for (int i = -1; f.c+ i > t.c; i--)
            if (!board[f.r][f.c + i]->getPiece()) return false;
        break;
    case DIR::NE:
        for (int i = 1; f.r + i < t.r; i++)
            if (!board[f.r + i][f.c + i]->getPiece()) return false;
        break;
    case DIR::NW:
        for (int i = 1; f.r + i < t.r; i++)
            if (!board[f.r + i][f.c - i]->getPiece()) return false;
        break;
    case DIR::SE:
        for (int i = -1; f.r + i > t.r; i--)
            if (!board[f.r + i][f.c - i]->getPiece()) return false;
        break;
    case DIR::SW:
        for (int i = -1; f.r + i > t.r; i--)
            if (!board[f.r + i][f.c + i]->getPiece()) return false;
        break;
    default:
        return true;
        break;
    }
}
