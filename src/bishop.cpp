#include "piece.h"
#include "board.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) {
    type = bishop;
}

void Bishop::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    int tmpX = curX;
    int tmpY = curY;
    Square* cur = board[curY][curX];
    while (tmpX < 7 && tmpY < 7) //up right
    {
        tmpX++;
        tmpY++;
        if (board[tmpY][tmpX]->hasPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->isWhite != cur->getPiece()->isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX > 0 && tmpY < 7) //up left
    {
        tmpX--;
        tmpY++;
        if (board[tmpY][tmpX]->hasPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->isWhite != cur->getPiece()->isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX > 0 && tmpY > 0)
    { //down left
        tmpX--;
        tmpY--;
        if (board[tmpY][tmpX]->hasPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->isWhite != cur->getPiece()->isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX < 7 && tmpY > 0)  //down right
    {
        tmpX++;
        tmpY--;
        if (board[tmpY][tmpY]->hasPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->isWhite != cur->getPiece()->isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
}