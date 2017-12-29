#ifndef CHEPP_BOARD_H
#define CHEPP_BOARD_H
#define BOARD_SIZE 8

#include "piece.h"
#include <vector>

struct Square {
public:
    Square(int posX, int posY);
    void moveHere(Piece* piece);
    Piece* getPiece();

private:
    const int m_posX;
    const int m_posY;
    Piece* m_piece;
    vector<Square*> inDangerFrom;
};

class Board {
public:
    Board();
    void updateDanger();
    void initBoard();
private:
    Square* board[BOARD_SIZE][BOARD_SIZE];
};


#endif //CHEPP_BOARD_H
