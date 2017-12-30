#include "piece.h"
#include "board.h"

Queen::Queen(bool isWhite) : Piece(isWhite) {
    type = queen;
}

void Queen::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    /*
    if (isWithinBounds(curX, newY))
    {
        if (curY - newY == curX - newX)
        {
            return true;
        }
        else if (newX == curX && newY == curY)
        {
            return true;
        }
    }
     */
}