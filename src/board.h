#ifndef CHEPP_BOARD_H
#define CHEPP_BOARD_H
#define BOARD_SIZE 8

#include <unordered_set>

using namespace std;

class Piece; //Forward declaration

//Board contains Square contains Piece

struct Square
{
public:
    const int posX;
    const int posY;
    unordered_set<Square*> inDangerFrom;

    Square(int posX, int posY);
    void moveHere(Piece* piece);
    Piece* getPiece();
    bool hasPiece();
private:
    Piece* m_piece = nullptr;
};

class Board
{
public:
    //p_squares[y][x]
    Square* p_squares[BOARD_SIZE][BOARD_SIZE];
    unordered_set<Piece*> p_takenPieces;

    Board();
    void initBoard();
    void updateDanger();
    void move(int posX, int posY, int newX, int newY);

};


#endif //CHEPP_BOARD_H
