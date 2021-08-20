#ifndef ROOK_H_
#define ROOK_H_
#include "piece.h"

class Rook : public Piece
{
private:

public:
    Rook(Colour, Cell*);
    ~Rook();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* ROOK_H_ */
