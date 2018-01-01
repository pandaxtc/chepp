#include <iostream>
#include "piece.h"
#include "board.h"

Rook::Rook(bool isWhite) : Piece(isWhite) {
    type = rook;
}

void Rook::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    int tmpX = curX;
    int tmpY = curY;
    //cout << "EXAMINING: " << tmpX << ", " << tmpY << endl;
    Square* cur = board[curY][curX];
    while (tmpY < BOARD_SIZE - 1) //up
    {
        tmpY++;
        //cout << "ROOK CHECKING UP: " << tmpX << ", " << tmpY << endl;
        bool hasPiece = board[tmpY][curX]->hasPiece();
        if (hasPiece && board[tmpY][curX]->getPiece()->isWhite != cur->getPiece()->isWhite)
        {
            board[tmpY][curX]->inDangerFrom.insert(cur); //Mark square as in danger from original square
            break;
        }
        else if (!hasPiece) {
            board[tmpY][curX]->inDangerFrom.insert(cur);
        }
        else {
            break;
        }
    }
    tmpY = curY;
    while (tmpX > 0) //left
    {
        tmpX--;
        //cout << "ROOK CHECKING LEFT: " << tmpX << ", " << tmpY << endl;
        bool hasPiece = board[tmpY][curX]->hasPiece();
        if (hasPiece && board[tmpY][curX]->getPiece()->isWhite != cur->getPiece()->isWhite)
        {
            board[tmpY][curX]->inDangerFrom.insert(cur); //Mark square as in danger from original square
            break;
        }
        else if (!hasPiece) {
            board[tmpY][curX]->inDangerFrom.insert(cur);
        }
        else {
            break;
        }
    }
    tmpX = curX;
    while (tmpY > 0) //down
    {
        tmpY--;
        //cout << "ROOK CHECKING DOWN: " << tmpX << ", " << tmpY << endl;
        bool hasPiece = board[tmpY][curX]->hasPiece();
        if (hasPiece && board[tmpY][curX]->getPiece()->isWhite != cur->getPiece()->isWhite)
        {
            board[tmpY][curX]->inDangerFrom.insert(cur); //Mark square as in danger from original square
            break;
        }
        else if (!hasPiece) {
            board[tmpY][curX]->inDangerFrom.insert(cur);
        }
        else {
            break;
        }
    }
    tmpY = curY;
    while (tmpX < BOARD_SIZE - 1) //right
    {
        tmpX++;
        //cout << "ROOK CHECKING RIGHT: " << tmpX << ", " << tmpY << endl;
        bool hasPiece = board[tmpY][curX]->hasPiece();
        if (hasPiece && board[tmpY][curX]->getPiece()->isWhite != cur->getPiece()->isWhite)
        {
            board[tmpY][curX]->inDangerFrom.insert(cur); //Mark square as in danger from original square
            break;
        }
        else if (!hasPiece) {
            board[tmpY][curX]->inDangerFrom.insert(cur);
        }
        else {
            break;
        }
    }
}