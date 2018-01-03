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

Bishop::Bishop(bool isWhite) : Piece(isWhite, rook) {}

/**
 * @brief Given board state, mark all squares that the piece is capable of moving to.
 * @param board Square*[][] Array of Square class pointers representing board state.
 * @see Piece::markDanger
 * @see Board::p_squares
 *
 * Iterates over the board diagonally in all 4 directions until another piece or the edge of the board is encountered.
 * Every Square object iterated over is marked. If an enemy piece is encountered, the enemy piece's location is marked.
 * If a friendly piece is encountered, the friendly piece's location is not marked. Either case results in a break.
 *
 */
void Bishop::markDanger(Square* board[BOARD_SIZE][BOARD_SIZE]) {
    int tmpX = posX; // Used to store position of Square being iterated over
    int tmpY = posY;
    Square* cur = board[posY][posX]; // Square piece is on
    Square* tmp; // Square under inspection
    while (tmpX < BOARD_SIZE - 1 && tmpY < BOARD_SIZE - 1) { // Iterate up & right
        tmpX++; // Change position variables to iterate to upper-right square
        tmpY++;
        tmp = board[tmpY][tmpX]; // Inspect upper-right square
        if (tmp->hasPiece()) { // If piece encountered
            // If enemy piece, mark square as in danger
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur);
            }
            break; // Stop iteration
        }
    }
    tmpX = posX; // Reset position variables
    tmpY = posY;
    while (tmpX > 0 && tmpY < BOARD_SIZE - 1) { // Iterate up & left
        tmpX--;
        tmpY++;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) {
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = posX;
    tmpY = posY;
    while (tmpX > 0 && tmpY > 0) { // Iterate down & left
        tmpX--;
        tmpY--;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) {
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur);
            }
            break;
        }
    }
    tmpX = posX;
    tmpY = posY;
    while (tmpX < BOARD_SIZE - 1 && tmpY > 0) { // Iterate down & right
        tmpX++;
        tmpY--;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) {
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur);
            }
            break;
        }
    }
}