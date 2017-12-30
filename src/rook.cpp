#include "piece.h"

void Rook::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    int tmpX = curX;
    int tmpY = curY;
    Square* cur = cur;
    while (tmpY < 8) //up
    {
        tmpY++;
        if (!board[tmpY][curX]->getPiece())
        {
            if (board[tmpY][curX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][curX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpY = curY;
    while (tmpX >= 0) //left
    {
        tmpX--;
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
    while (tmpY >= 0) //down
    {
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
    tmpY = curY;
    while (tmpX < 8) //right
    {
        tmpX++;
        if (!board[tmpY][tmpX]->getPiece())
        {
            if (board[tmpY][tmpX]->getPiece()->m_isWhite != cur->getPiece()->m_isWhite)
            {
                board[tmpY][tmpX]->inDangerFrom.insert(cur);
            }
            break;
        }
    }
}