#ifndef KING_H_
#define KING_H_
#include "piece.h"

class King : public Piece
{
private:

public:
    King(Coord, Colour, Cell*);
    ~King();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* KING_H_ */
