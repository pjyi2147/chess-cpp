#ifndef UI_H_
#define UI_H_

#ifndef UI_H
#define UI_H

#include "../enum.h"
#include "../Observer/observer.h"
#include "../Board/board.h"

class UI : public Observer<Move>
{
public:
    // renders the changes in the window
    virtual void render() = 0;
    // update the whole Board
    virtual void updateBoard(const Board& b) = 0; 
    // update the cell base on the move
    virtual void updateCell(Move m) = 0;

    virtual void notify(Subject<Move>& b)
    {
        updateCell(b.getState());
    }
};

#endif /* UI_H */
