#include "piece.h"
#include "board.h"

Bishop::Bishop(bool isWhite) : Piece(isWhite) {
    type = pawn;
}

void Bishop::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    int tmpX = curX;
    int tmpY = curY;
    Square* cur = board[curY][curX];
    while (tmpX < 8 && tmpY < 8) //up right
    {
        tmpX++;
        tmpY++;
        if (!board[tmpY][tmpX]->getPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX >= 0 && tmpY < 8)
    { //up left
        tmpX--;
        tmpY++;
        if (!board[tmpY][tmpX]->getPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX >= 0 && tmpY >= 0) { //down left
        tmpX--;
        tmpY--;
        if (!board[tmpY][tmpX]->getPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = curX;
    tmpY = curY;
    while (tmpX < 8 && tmpY >= 0) { //down right
        tmpX++;
        tmpY--;
        if (!board[tmpY][tmpY]->getPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
}