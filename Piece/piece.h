#ifndef PIECE_H_
#define PIECE_H_
#include "../enum.h"

class Cell;

class Piece 
{
protected:
    Coord pos;
    Colour colour;
    Cell* cell;
    int moveCount;
public:
    Piece(Coord, Colour, Cell*);
    virtual ~Piece();

    virtual PieceName getPieceName() const = 0;
    Colour getColour() const;
    Coord getPostion() const;

    void setPosition(Coord c);

    bool isValidMove(Coord to) const;
    bool isMoved() const;

    void addMoveCount();
    void decMoveCount();
};

#endif /* PIECE_H_ */
