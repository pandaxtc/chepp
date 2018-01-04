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

Pawn::Pawn(bool isWhite) : Piece(isWhite, pawn) {
    firstMove = true;
}

void Pawn::markDanger(Square* board[BOARD_SIZE][BOARD_SIZE]) {
    Square *cur = board[posY][posX];
    int dir = (isWhite) ? 1 : -1; //If white go up else go down
    //If forwards square is empty, mark square as in danger from cur
    if (!board[posY + dir][posX]->hasPiece()) {
        board[posY + dir][posX]->inDangerFrom.insert(cur);
        //If is first move and 2 spaces forwards are both empty, mark square 2 spaces forwards as in danger from cur
        if (posY + dir * 2 < 8 && posY + dir * 2 >= 0 && firstMove && !board[posY + dir * 2][posX]->hasPiece()) {
            board[posY + dir * 2][posX]->inDangerFrom.insert(cur); // Mark square as in danger from cur
        }
    }
    //If front left has enemy piece, mark square as in danger from cur
    if (posX != BOARD_SIZE - 1 && board[posY + dir][posX + 1]->hasPiece() &&
            board[posY + dir][posX + 1]->getPiece()->isWhite != isWhite) {
        board[posY + dir][posX + 1]->inDangerFrom.insert(cur);
    }
    //If front right has enemy piece, mark square as in danger from cur
    if (posX != 0 && board[posY + dir][posX - 1]->hasPiece() &&
            board[posY + dir][posX - 1]->getPiece()->isWhite != isWhite) {
        board[posY + dir][posX - 1]->inDangerFrom.insert(cur);
    }
};