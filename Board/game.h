#ifndef GAME_H_
#define GAME_H_
#include <memory>
#include "board.h"
#include "../Player/player.h"

class TUI;
class UI;

class Game
{
private:
    std::unique_ptr<Board> b;
    std::unique_ptr<Player> wp;
    std::unique_ptr<Player> bp;
    std::vector<std::unique_ptr<UI>> vUI;

    TUI* tui;

    int wScore;
    int bScore;
    bool inited;

    void displayScore();
    void endGame(int, bool checkmate = false);
    void initializePlayer(Colour, const int);

public:
    Game();
    ~Game();
    void newGame(const int, const int);
    void setup();
};

#endif /* GAME_H_ */