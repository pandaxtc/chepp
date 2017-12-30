#include "piece.h"
#include "board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    m_firstMove = true;
}

void Pawn::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    Square* cur = cur;
    int dir = (m_isWhite) ? 1 : -1; //if white go up else go down
    if (!board[curY + dir][curX]->getPiece())
    {
        board[curY + dir][curX]->inDangerFrom.insert(cur);
    }
    if (m_firstMove && !board[curY + dir*2][curX]->getPiece())
    {
        board[curY + dir*2][curX]->inDangerFrom.insert(cur);
    }
    if (curX != 7 && board[curY + dir][curX + 1]->getPiece())
    {
        board[curY + dir][curX + 1]->inDangerFrom.insert(cur);
    }
    if (curX != 0 && board[curY + dir][curX - 1]->getPiece())
    {
        board[curY + dir][curX - 1]->inDangerFrom.insert(cur);
    }
};