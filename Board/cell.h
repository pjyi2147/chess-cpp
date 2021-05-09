#ifndef CELL_H_
#define CELL_H_
#include "../enum.h"
#include "../Observer/observer.h"
#include "../Observer/subject.h"

class Piece;
class Board;

class Cell
{
private:
    Coord pos;
    Piece* p;
    Board* b;
    std::vector<Piece*> accessW;
    std::vector<Piece*> accessB;

public:
    Cell(Coord, Board*, Piece* p = nullptr);
    ~Cell();

    void setPiece(Piece* p);

    Piece* getPiece() const;
    std::vector<Piece*>& getAccessW() const;
    std::vector<Piece*>& getAccessB() const;
    Board* getBoard() const;
};

#endif /* CELL_H_ */
