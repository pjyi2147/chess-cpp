#ifndef TUI_H
#define TUI_H

#include <curses.h>
#include <string>
#include <sstream>
#include "UI.h"

class TUI : public UI
{
private:
    WINDOW* chessB;
    WINDOW* inputB;
    int chessBh;
    int chessBw;

public:
    TUI();
    ~TUI();

    bool getCMD(std::string& cmd);

    void printTurn(Colour c);
    void printError(std::string e);
    void printStatus(std::string s);
    void printCMD();
    void printInputE(std::string e);
    void printInput(Colour c, std::string s, std::string e);

    virtual void render() override;
    virtual void updateBoard(const Board& b) override;
    virtual void updateCell(Move) override;
    
    virtual void notify(Subject<Move>& b) override;
};

#endif /* TUI_H */