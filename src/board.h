#ifndef CHEPP_BOARD_H
#define CHEPP_BOARD_H
#define BOARD_SIZE 8

#include <unordered_set>

using namespace std;

class Piece;

struct Square {
public:
    Square(int posX, int posY);
    void moveHere(Piece* piece);
    Piece* getPiece();
    unordered_set<Square*> inDangerFrom;
    const int m_posX;
    const int m_posY;
private:
    Piece* m_piece;
};

class Board {
public:
    Board();
    void initBoard();
    void updateDanger();
    Square** getBoardState();
    //board[y][x]
    Square* board[BOARD_SIZE][BOARD_SIZE];
};


#endif //CHEPP_BOARD_H
