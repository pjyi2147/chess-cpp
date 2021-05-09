#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "piece.h"

class Knight : public Piece
{
private:

public:
    Knight(Coord, Colour, Cell*);
    ~Knight();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* KNIGHT_H_ */