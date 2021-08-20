#include "cell.h"

Cell::Cell(Coord c, Board* b_ptr, Piece* p_ptr = nullptr) : pos{c}, p{p_ptr}, b{b_ptr}
{}

Cell::~Cell()
{
    p = nullptr;
    b = nullptr;
}

void Cell::setPiece(Piece* p_ptr)
{
    p = p_ptr;
}

Piece* Cell::getPiece() const
{
    return p;
}

const std::vector<Piece*>& Cell::getAccessW() const
{
    return accessW;
}

const std::vector<Piece*>& Cell::getAccessB() const
{
    return accessB;
}

Board* Cell::getBoard() const
{
    return b;
}

Coord Cell::getPos() const
{
    return pos;
}

void Cell::clearAccess()
{
    accessW.clear();
    accessB.clear();
}

void Cell::pushAccessW(Piece* p)
{
    accessW.push_back(p);
}

void Cell::pushAccessB(Piece* p)
{
    accessB.push_back(p);
}
