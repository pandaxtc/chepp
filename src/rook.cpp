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


#include <iostream>
#include "piece.h"
#include "board.h"

Rook::Rook(bool isWhite) : Piece(isWhite, rook) {}

/**
 * @brief Given board state, mark all squares that the piece is capable of moving to.
 * @param board Square*[][] Array of Square class pointers representing board state.
 * @see Piece::markDanger
 * @see Board::p_squares
 *
 * Iterates over the board upwards, downwards, leftwards, and rightwards until another piece or the edge of the board is
 * encountered. Every Square object iterated over is marked. If an enemy piece is encountered, the enemy piece's
 * location is marked. If a friendly piece is encountered, the friendly piece's location is not marked. Either case
 * results in a break.
 *
 */
void Rook::markDanger(Square* board[BOARD_SIZE][BOARD_SIZE]) {
    int tmpX = posX; // Used to store position of Square being iterated over
    int tmpY = posY;
    Square* cur = board[posY][posX]; // Square piece is on
    Square* tmp; // Square under inspection
    while (tmpY < BOARD_SIZE - 1) { // Iterates upwards
        tmpY++;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) { // If piece encountered
            // If enemy piece, mark Square as in danger and break
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur); // Mark square as in danger from cur
                break;
            } else { // If not enemy piece, break
                break;
            }
        } else { // If no piece encountered, mark square as in danger from cur and continue.
            tmp->inDangerFrom.insert(cur);
        }
    }
    tmpY = posY; // Reset tmpY
    while (tmpX > 0) { // Iterate leftwards
        tmpX--;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) {
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur);
                break;
            } else {
                break;
            }
        } else {
            tmp->inDangerFrom.insert(cur);
        }
    }
    tmpX = posX;
    while (tmpY > 0) { // Iterate downwards
        tmpY--;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) { // If piece encountered
            // If enemy piece, mark square as in danger
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur); // Mark square as in danger from cur
            }
            break; // Stop iteration
        } else { // If no piece encountered, mark square as in danger from cur and continue.
            tmp->inDangerFrom.insert(cur);
        }
    }
    tmpY = posY;
    while (tmpX < BOARD_SIZE - 1) { // Iterate rightwards
        tmpX++;
        tmp = board[tmpY][tmpX];
        if (tmp->hasPiece()) { // If piece encountered
            // If enemy piece, mark Square as in danger and break
            if (tmp->getPiece()->isWhite != isWhite) {
                tmp->inDangerFrom.insert(cur); // Mark square as in danger from cur
                break;
            } else { // If not enemy piece, break
                break;
            }
        } else { // If no piece encountered, mark square as in danger from cur and continue.
            tmp->inDangerFrom.insert(cur);
        }
    }
}