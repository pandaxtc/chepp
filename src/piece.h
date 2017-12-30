#ifndef CHEPP_PIECE_H
#define CHEPP_PIECE_H
#define BOARD_SIZE 8

#include <cstdlib>

using namespace std;

struct Square;

enum piece_t {
    king,
    queen,
    bishop,
    knight,
    rook,
    pawn
};

class Piece
{
public:
    Piece(bool isWhite)
    {
        m_isWhite = isWhite;
    }
    virtual void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) = 0;
    bool m_isWhite;
    piece_t type;
    bool isWithinBounds(int posX, int posY)
    {
        if (posX < 8 && posY < 8 && posX > 0 && posY > 0) return true;
        else return false;
    }
};

class Pawn : public Piece
{
public:
    Pawn(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
    bool m_firstMove;
};

class King : public Piece
{
public:
    King(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Queen : public Piece
{
public:
    Queen(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Bishop : public Piece
{
public:
    Bishop(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Knight : public Piece
{
public:
    Knight(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Rook : public Piece
{
public:
    Rook(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};


#endif //CHEPP_PIECE_H
