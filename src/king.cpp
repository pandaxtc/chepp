#include "piece.h"

King::King(bool isWhite) : Piece(isWhite) {
    type = king;
}

void King::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{

}