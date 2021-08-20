#ifndef QUEEN_H_
#define QUEEN_H_
#include "piece.h"

class Queen : public Piece
{
private:

public:
    Queen(Colour, Cell*);
    ~Queen();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* QUEEN_H_ */
