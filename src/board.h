/*
MIT License

Copyright (c) 2018 dragxtcon

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#ifndef CHEPP_BOARD_H
#define CHEPP_BOARD_H
#define BOARD_SIZE 8

#include <unordered_set>

using namespace std;

struct Piece; //Forward declaration for Piece struct

//Board contains Squares contains Pieces

struct Square {
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

class Board {
public:
    /**
     * Square*[][] p_squares
     * @brief 2D array of Square pointers that represents the game board.
     *
     * 2D array of Square pointers that represents the game board. Lower-left corner is (0,0).
     *
     */
    Square* p_squares[BOARD_SIZE][BOARD_SIZE];
    unordered_set<Piece*> p_takenPieces;

    Board();

    void initBoard();

    void updateDanger();

    bool canPromote(bool isWhiteTurn);

    void promote(int posX, int posY, int input);

    bool move(int posX, int posY, int newX, int newY);



    Square* isCheckmate();
};


#endif //CHEPP_BOARD_H
