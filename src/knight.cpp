#include "piece.h"
#include "board.h"

Knight::Knight(bool isWhite) : Piece(isWhite) {
    type = knight;
}

void move(int x, int y, Square* cur, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        bool hasPiece = board[y][x]->hasPiece();
        if (hasPiece && board[y][x]->getPiece()->isWhite != cur->getPiece()->isWhite) {
            board[y][x]->inDangerFrom.insert(cur); //Mark square as in danger from original square
        } else if (!hasPiece) {
            board[y][x]->inDangerFrom.insert(cur);
        }
    }
}

void Knight::checkMove(int curX, int curY, Square* board[BOARD_SIZE][BOARD_SIZE])
{
    Square* cur = board[curY][curX];
    move(curX + 1, curY + 2, cur, board);
    move(curX - 1, curY + 2, cur, board);
    move(curX - 2, curY + 1, cur, board);
    move(curX - 2, curY - 1, cur, board);
    move(curX - 1, curY - 2, cur, board);
    move(curX + 1, curY - 2, cur, board);
    move(curX + 2, curY - 1, cur, board);
    move(curX + 2, curY + 1, cur, board);
}

