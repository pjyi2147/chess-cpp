#ifndef PAWN_H_
#define PAWN_H_
#include "piece.h"

class Pawn : public Piece
{
private:

public:
    Pawn(Colour, Cell*);
    ~Pawn();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* PAWN_H_ */
