/*
MIT License

Copyright (c) 2018 dragxtcon

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include "piece.h"
#include "board.h"

Knight::Knight(bool isWhite) : Piece(isWhite, knight) {}

/// Helper function
bool Knight::checkKnightMove(int newX, int newY, Square *board[BOARD_SIZE][BOARD_SIZE]) {
    Square *cur = board[posY][posX];
    if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
        bool hasPiece = board[newY][newX]->hasPiece();
        if (hasPiece && board[newY][newX]->getPiece()->isWhite != cur->getPiece()->isWhite) {
            return true; //Mark square as in danger from original square
        } else if (!hasPiece) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Knight::markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) {
    Square *cur = board[posY][posX];
    if (checkKnightMove(posX + 1, posY + 2, board)) {
        board[posY + 2][posX + 1]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX - 1, posY + 2, board)) {
        board[posY + 2][posX - 1]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX - 2, posY + 1, board)) {
        board[posY + 1][posX - 2]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX - 2, posY - 1, board)) {
        board[posY - 1][posX - 2]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX - 1, posY - 2, board)) {
        board[posY - 2][posX - 1]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX + 1, posY - 2, board)) {
        board[posY - 2][posX + 1]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX + 2, posY - 1, board)) {
        board[posY - 1][posX + 2]->inDangerFrom.insert(cur);
    }
    if (checkKnightMove(posX + 2, posY + 1, board)) {
        board[posY + 1][posX + 2]->inDangerFrom.insert(cur);
    }
}
