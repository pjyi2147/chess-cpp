#ifndef BISHOP_H_
#define BISHOP_H_
#include "piece.h"

class Bishop : public Piece
{
private:

public:
    Bishop(Colour, Cell*);
    ~Bishop();

    virtual PieceName getPieceName() const override;
    bool isValidMove(Coord to) const;
};

#endif /* BISHOP_H_ */
