#include "piece.h"

Knight::Knight(bool isWhite) : Piece(isWhite) {
    type = pawn;
}

void Knight::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
}