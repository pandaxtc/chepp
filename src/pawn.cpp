#include "piece.h"
#include "board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    firstMove = true;
    type = pawn;
}

void Pawn::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    Square* cur = board[curY][curX];
    int dir = (isWhite) ? 1 : -1; //If white go up else go down.
    //If forwards square is empty, mark.
    if (!board[curY + dir][curX]->hasPiece())
    {
        board[curY + dir][curX]->inDangerFrom.insert(cur);
    }
    //If is first move and 2 spaces forwards are empty, mark.
    if (firstMove && !board[curY + dir][curX]->hasPiece() && !board[curY + dir*2][curX]->hasPiece())
    {
        board[curY + dir*2][curX]->inDangerFrom.insert(cur);
    }
    //If front left has enemy piece, mark.
    if (curX != BOARD_SIZE - 1 && board[curY + dir][curX + 1]->hasPiece() &&
            board[curY + dir][curX + 1]->getPiece()->isWhite != board[curY][curX]->getPiece()->isWhite)
    {
        board[curY + dir][curX + 1]->inDangerFrom.insert(cur);
    }
    //If front right has enemy piece, mark.
    if (curX != 0 && board[curY + dir][curX - 1]->hasPiece() &&
            board[curY + dir][curX - 1]->getPiece()->isWhite != board[curY][curX]->getPiece()->isWhite)
    {
        board[curY + dir][curX - 1]->inDangerFrom.insert(cur);
    }
};