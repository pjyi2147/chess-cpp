#include "TUI.h"
#include "subject.h"
#include "Piece/piece.h"
#include <vector>
#include <string>

TUI::TUI() : chessB{nullptr}, chessBh{0}, chessBw{0}
{
    initscr();
    inputB = newwin(5, getmaxx(stdscr), 0, 0);
    printCMD();
}

TUI::~TUI()
{
    delwin(chessB);
    delwin(inputB);
    endwin();
}

void TUI::printTurn(Colour c)
{
    wmove(inputB, 0, 0);
    clrtoeol();
    if (c == Colour::B) wprintw(inputB, "Black Turn");
    else wprintw(inputB, "White Turn");

    printCMD();
}

void TUI::printStatus(std::string s)
{
    wmove(inputB, 1, 0);
    clrtoeol();
    wprintw(inputB, s.data());

    printCMD();
}

void TUI::printError(std::string e)
{
    wmove(inputB, 2, 0);
    clrtoeol();
    wprintw(inputB, e.data());

    printCMD();
}

void TUI::printCMD()
{
    wmove(inputB, 3, 0);
    clrtoeol();
    wprintw(inputB, "next cmd: ");
}

void TUI::printInputE(std::string e)
{
    wclear(inputB);
    printError(e);
}

void TUI::printInput(Colour c, std::string s, std::string e)
{
    wclear(inputB);
    printTurn(c);
    printStatus(s);
    printError(e);
}

bool TUI::getCMD(std::string& cmd)
{
    std::string input;
    nocbreak();
    echo();
    int ch = wgetch(inputB);

    while ( ch != '\n' && ch != ' ' && ch != 4 )
    {
        input.push_back( ch );
        ch = wgetch(inputB);
    }
    cmd = input;
    if (ch == 4) return false;
    return true;
}

void TUI::render()
{
    wrefresh(inputB);
    wrefresh(chessB);
}

char getPieceChar(PieceName pn, Colour c)
{
    char ret;
    if (c == Colour::B)
    {
        switch (pn)
        {
        case PieceName::K:
            ret = 'k';
            break;
        case PieceName::Q:
            ret = 'q';
            break;
        case PieceName::N:
            ret = 'n';
            break;
        case PieceName::B:
            ret = 'b';
            break;
        case PieceName::R:
            ret = 'r';
            break;
        case PieceName::P:
            ret = 'p';
            break;
        }
    }
    else
    {
        switch (pn)
        {
        case PieceName::K:
            ret = 'K';
            break;
        case PieceName::Q:
            ret = 'Q';
            break;
        case PieceName::N:
            ret = 'N';
            break;
        case PieceName::B:
            ret = 'B';
            break;
        case PieceName::R:
            ret = 'R';
            break;
        case PieceName::P:
            ret = 'P';
            break;
        }
    }
    return ret;
}

void TUI::updateBoard(const Board& b)
{
    Coord bs = b.getSize();
    int h = bs.r, w = bs.c;
    chessBh = h + 4; chessBw = w + 5;

    wclear(inputB);
    wrefresh(inputB);
    mvwin(inputB, chessBh+2, 0);

    std::string column = "abcdefghijklmnopqrstuvwxyz";

    chessB = newwin(chessBh, chessBw, 2, 0);
    box(chessB, 0, 0);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            auto p = b.getPiece(Coord{i,j});
            if (p != nullptr)
            {
                char c = getPieceChar(p->getRole(), p->getColour());
                mvwaddch(chessB, i+1, j+1, c);
            }
        }
    }

    mvwprintw(chessB, chessBh-2, 1, column.substr(0,w).data());
    for (int i = 1; i <= h; i++)
    {
        mvwaddstr(chessB, chessBh-i-3, chessBw-3, std::to_string(i).data());
    }
}

void TUI::updateCell(Move m)
{
}

void TUI::notify(Subject<Move>& whoFrom)
{
    updateCell(whoFrom.getState());
}