#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
#include <memory>
#include "../enum.h"
#include "../Observer/subject.h"
#include "../Piece/piece.h"

class Cell;
class Player;

class Board : public Subject<Move>
{
private:
    Coord size;
    
    std::vector<std::unique_ptr<Piece>> bPieces;
    std::vector<std::unique_ptr<Piece>> wPieces;

    std::vector<std::vector<std::unique_ptr<Cell>>> board;

    Piece* kingW;
    Piece* kingB;

    Player* playerW;
    Player* playerB;

    Piece* first2PawnW;
    Piece* first2PawnB;

    vMove moves;
    vMove recentMoves;
    vMove undos;
    Colour turn;

    bool isCheckW() const;
    bool isCheckB() const;
    bool isCheckmateW() const;
    bool isCheckmateB() const;
public:
    // standard 8x8 empty chess board
    Board();
    // empty custom board;
    Board(int y, int x);
    ~Board();

    void initStandardChess();

    Colour getTurn() const;
    Coord getSize() const;
    Piece* getPiece(Coord) const;

    bool setPiece(Coord t, PieceName p, Colour c);
    void setPlayerW(Player*);
    void setPlayerB(Player*);
    void setTurn(Colour);

    bool isValidMove(Coord f, Coord t) const;
    bool isThreatened(Coord t, Colour c) const;
    bool isCheck() const;
    bool isCheckmate() const;
    bool isStalemate() const;
    bool isBlocked(Coord f, Coord t) const;
};

#endif /* BOARD_H_ */
