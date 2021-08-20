#ifndef PIECE_H_
#define PIECE_H_
#include "../enum.h"
#include "../Board/cell.h"

class Piece 
{
protected:
    Colour colour;
    Cell* cell;
    int moveCount;
    
public:
    Piece(Colour, Cell*);
    virtual ~Piece();

    virtual PieceName getPieceName() const = 0;
    Colour getColour() const;
    Coord getPostion() const;

    void setCell(Cell*);

    bool isValidMove(Coord to) const;
    bool isMoved() const;

    void addMoveCount();
    void decMoveCount();
};

#endif /* PIECE_H_ */
