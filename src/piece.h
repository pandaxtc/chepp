#ifndef CHEPP_PIECE_H
#define CHEPP_PIECE_H
#define BOARD_SIZE 8

#include <cstdlib>

using namespace std;

struct Square; //Forward declaration

enum piece_t {
    king,
    queen,
    bishop,
    knight,
    rook,
    pawn
};

//<Pawn,King,Queen,Bishop,Knight,Rook> is Piece
//Square contains Piece

class Piece
{
public:
    bool isWhite;
    bool firstMove;
    piece_t type = rook;

    explicit Piece(bool isWhite) {
        this->isWhite = isWhite;
        firstMove = true;
    }
    virtual void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) = 0;
};

class Pawn : public Piece
{
public:
    explicit Pawn(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class King : public Piece
{
public:
    explicit King(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Queen : public Piece
{
public:
    explicit Queen(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Bishop : public Piece
{
public:
    explicit Bishop(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Knight : public Piece
{
public:
    explicit Knight(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};

class Rook : public Piece
{
public:
    explicit Rook(bool isWhite);
    void checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE]) override;
};


#endif //CHEPP_PIECE_H
