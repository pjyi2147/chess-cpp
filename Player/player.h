#ifndef PLAYER_H_
#define PLAYER_H_
#include "../enum.h"

class Board;

class Player 
{
private:
    Board* board;
public:
    Player();
    ~Player();

    virtual Coord getNextMove();
};

#endif /* PLAYER_H_ */
