#ifndef ENUM_H_
#define ENUM_H_
#include <string>
#include <vector>

// {r, c}
struct Coord
{
    int r;
    int c;
    static Coord stoc(std::string s)
    {
        // string must be in the 8x8 coordinate to [a-h][1-8]
        // need to impl extended one
        char col = s[0];
        char row = s[1];
        return Coord{'8'-row, col-'a'};
    }

    bool operator==(Coord t) const
    {
        return (r == t.r && c == t.c);
    }
};

enum class Colour { B, W };
enum class DIR { N=0, NE, E, SE, S, SW, W, NW, POS, NA };
enum class PieceName { K, Q, N, B, R, P };
enum class MoveType { Move, Castle, Enpassant, Capture, Promotion, Undo, UCapture, UPromotion};

// returns DIR from f to t
DIR getDIR(Coord f, Coord t)
{
    if (f == t) return DIR::POS;
    
    if (f.r < t.r && f.c == t.c) return DIR::N;
    if (f.r == t.r && f.c < t.c) return DIR::E;
    if (f.r > t.r && f.c == t.c) return DIR::S;
    if (f.r == t.r && f.c > t.c) return DIR::W;

    if (abs(f.r - t.r) != abs(f.c - t.c)) return DIR::NA;

    if (f.r < t.r && f.c < t.c) return DIR::NE;
    if (f.r > t.r && f.c < t.c) return DIR::SE;
    if (f.r > t.r && f.c > t.c) return DIR::SW;
    if (f.r < t.r && f.c > t.c) return DIR::NW;

    return DIR::NA;
}

class Piece;
struct Move
{
    Piece* origin;
    Piece* to;
    bool captured;
    bool enpassant;
    bool castling;
    bool promotion;
    bool undo;
    Piece* promoted;
};

typedef std::vector<Move> vMove;

#endif /* ENUM_H_ */
