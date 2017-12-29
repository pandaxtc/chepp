#ifndef CHEPP_PIECE_H
#define CHEPP_PIECE_H

#include <cstdlib>
using namespace std;

class Piece
{
public:
    Piece(bool isWhite) {
        m_isWhite = isWhite;
    }
    virtual bool checkMove(int posX, int posY, int curX, int curY) = 0;
    bool m_isWhite;
};

class Pawn : public Piece {
public:
    Pawn(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
    bool m_firstMove;
};

class King : public Piece {
public:
    King(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
};

class Queen : public Piece {
public:
    Queen(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
};

class Bishop : public Piece {
public:
    Bishop(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
};

class Knight : public Piece {
public:
    Knight(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
};

class Rook : public Piece {
public:
    Rook(bool isWhite);
    bool checkMove(int posX, int posY, int curX, int curY) override;
};

#endif //CHEPP_PIECE_H
