#ifndef CHEPP_PIECE_H
#define CHEPP_PIECE_H

#include <cstdlib>
#include "board.h"

using namespace std;

class Piece
{
public:
    Piece(bool isWhite)
    {
        m_isWhite = isWhite;
    }

    virtual bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) = 0;
    bool m_isWhite;
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
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
    bool m_firstMove;
};

class King : public Piece
{
public:
    using Piece::Piece;
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Queen : public Piece
{
public:
    using Piece::Piece;
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Bishop : public Piece
{
public:
    using Piece::Piece;
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Knight : public Piece
{
public:
    using Piece::Piece;
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Rook : public Piece
{
public:
    using Piece::Piece;
    bool checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

#endif //CHEPP_PIECE_H
