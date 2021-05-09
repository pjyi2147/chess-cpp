#include "game.h"
#include "board.h"

Game::Game() 
: b{new Board()}, wp{nullptr}, bp{nullptr}, wScore{0}, bScore{0}, inited{false}
{
    vUI.push_back(new TUI());
    tui = vUI[0].get();
}

Game::~Game() {}

void Game::newGame(const int wnum, const int bnum)
{
    initializePlayer(Colour::W, wnum);
    initializePlayer(Colour::B, bnum);
    if (!inited) b->initStandardChess();
    b->updateUI();

    auto turnC = b->getTurn();
    Player* cPlayer = nullptr;
    while (true)
    {
        if (Colour::W == turnC) cPlayer = wp.get();
        else cPlayer = bp.get();

        
        std::string cmd = tui->getCMD();
        if (cmd == "move")
        {
            int result = -100;
            // try to move piece
            try 
            {
                if (!cPlayer)
                result = cPlayer->move();
            }
            catch (std::string &s)
            {
                endGame(0);
                break;
            }

            // piece moved then?
            if (result == 0) 
            {
                //draw by stalemate
                endGame(0);
                break;
            } 
            else if (result == 1) 
            {
                // legal move
                cmd = tui->getCMD();
                turnC = b->getTurn();
                continue;
            }
            else if (result == 2) {
                // win by checkmate
                if (turnC == Colour::W) {
                    endGame(1, true);
                } else {
                    endGame(2, true);
                }
                break;
            }
            else // something wrong
            {
                
            }
        }
        else if (cmd == "resign")
        {

        }
        else if (cmd == "undo")
        {

        }
        else if (cmd == "addui")
        {

        }
        else
        {

        }
    }
}

void Game::setup()
{

}

void Game::displayScore()
{

}

void Game::endGame(int, bool checkmate = false)
{

}

void Game::initializePlayer(Colour c, const int hAI)
{
    if (hAI == 0)
    {
        if (c == Colour::W) wp = std::make_unique(new Human(b, c, tui));
        else bp = std::make_unique(new Human(b, c, tui));
    }
    else 
    {
        if (c == Colour::W) wp = std::make_unique(new AI(b, c, tui));
        else bp = std::make_unique(new AI(b, c, tui));
    }
}
