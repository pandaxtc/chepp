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

/**
 * @brief Given board state, mark all squares that the piece is capable of moving to.
 * @param board Square*[][] Array of Square class pointers representing board state.
 * @see Piece::markDanger
 * @see Board::p_squares
 *
 * Checks 8 squares around it (less if on an edge). If square is not in check by an enemy piece and the move is
 * valid, mark.
 *
 */

King::King(bool isWhite) : Piece(isWhite, king) {}

void King::markDanger(Square* board[BOARD_SIZE][BOARD_SIZE]) {
    Square* cur = board[posY][posX];
    // Inspect top row
    if (posY < BOARD_SIZE - 1) { // If not at top edge of the board
        if (posX > 0) { // If not at left edge of board
            bool isUnderCheck = false;
            // Inspect top left square
            Square* tmp = board[posY + 1][posX - 1];
            // Iterate over danger markers and check if square being inspected is in danger from an enemy piece
            for (Square* s : tmp->inDangerFrom) {
                if (s->getPiece()->isWhite != isWhite) {
                    isUnderCheck = true;
                    break;
                }
            }
            if (!isUnderCheck) { // If square is not in check
                if (tmp->hasPiece()) { // If square has piece
                    if (tmp->getPiece()->isWhite != isWhite) { // If square is enemy piece
                        tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
                    }
                } else { // If square does not have piece
                    tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
                }
            }
        }
        if (posX < BOARD_SIZE - 1) { // If not at right edge of board
            bool isUnderCheck = false;
            // Inspect top right square
            Square* tmp = board[posY + 1][posX + 1];
            // Iterate over danger markers and check if square being inspected is in danger from an enemy piece
            for (Square* s : tmp->inDangerFrom) {
                if (s->getPiece()->isWhite != isWhite) {
                    isUnderCheck = true;
                    break;
                }
            }
            if (!isUnderCheck) { // If square is not in check
                if (tmp->hasPiece()) { // If square has piece
                    if (tmp->getPiece()->isWhite != isWhite) { // If square is enemy piece
                        tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
                    }
                } else { // If square does not have piece
                    tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
                }
            }
        }
        bool isUnderCheck = false;
        // Inspect top square
        Square* tmp = board[posY + 1][posX + 1];
        // Iterate over danger markers and check if square being inspected is in danger from an enemy piece
        for (Square* s : tmp->inDangerFrom) {
            if (s->getPiece()->isWhite != isWhite) {
                isUnderCheck = true;
                break;
            }
        }
        if (!isUnderCheck) { // If square is not in check
            if (tmp->hasPiece()) { // If square has piece
                if (tmp->getPiece()->isWhite != isWhite) { // If square is enemy piece
                    tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
                }
            } else { // If square does not have piece
                tmp->inDangerFrom.insert(cur); // Mark square as in danger from piece
            }
        }
    }
    //Inspect bottom row
    if (posY > 0) { // If not at bottom edge of the board
        if (posX > 0) { // If not at left edge of board
            bool isUnderCheck = false;
            // Inspect bottom left square
            Square* tmp = board[posY - 1][posX - 1];
            for (Square* s : tmp->inDangerFrom) {
                if (s->getPiece()->isWhite != isWhite) {
                    isUnderCheck = true;
                    break;
                }
            }
            if (!isUnderCheck) {
                if (tmp->hasPiece()) {
                    if (tmp->getPiece()->isWhite != isWhite) {
                        tmp->inDangerFrom.insert(cur);
                    }
                } else {
                    tmp->inDangerFrom.insert(cur);
                }
            }
        }
        if (posX < BOARD_SIZE - 1) { // If not at right edge of board
            bool isUnderCheck = false;
            // Inspect bottom right square
            Square* tmp = board[posY - 1][posX + 1];
            for (Square* s : tmp->inDangerFrom) {
                if (s->getPiece()->isWhite != isWhite) {
                    isUnderCheck = true;
                    break;
                }
            }
            if (!isUnderCheck) {
                if (tmp->hasPiece()) {
                    if (tmp->getPiece()->isWhite != isWhite) {
                        tmp->inDangerFrom.insert(cur);
                    }
                } else {
                    tmp->inDangerFrom.insert(cur);
                }
            }
        }
        bool isUnderCheck = false;
        // Inspect bottom square
        Square* tmp = board[posY - 1][posX];
        for (Square* s : tmp->inDangerFrom) {
            if (s->getPiece()->isWhite != isWhite) {
                isUnderCheck = true;
                break;
            }
        }
        if (!isUnderCheck) {
            if (tmp->hasPiece()) {
                if (tmp->getPiece()->isWhite != isWhite) {
                    tmp->inDangerFrom.insert(cur);
                }
            } else {
                tmp->inDangerFrom.insert(cur);
            }
        }
    }
    if (posX > 0) {
        bool isUnderCheck = false;
        //Inspect left square
        Square* tmp = board[posY][posX - 1];
        for (Square* s : tmp->inDangerFrom) {
            if (s->getPiece()->isWhite != isWhite) {
                isUnderCheck = true;
                break;
            }
        }
        if (!isUnderCheck) {
            if (tmp->hasPiece()) {
                if (tmp->getPiece()->isWhite != isWhite) {
                    tmp->inDangerFrom.insert(cur);
                }
            } else {
                tmp->inDangerFrom.insert(cur);
            }
        }
    }
    if (posX < BOARD_SIZE - 1) {
        bool isUnderCheck = false;
        //Inspect right square
        Square* tmp = board[posY][posX + 1];
        for (Square* s : tmp->inDangerFrom) {
            if (s->getPiece()->isWhite != isWhite) {
                isUnderCheck = true;
                break;
            }
        }
        if (!isUnderCheck) {
            if (tmp->hasPiece()) {
                if (tmp->getPiece()->isWhite != isWhite) {
                    tmp->inDangerFrom.insert(cur);
                }
            } else {
                tmp->inDangerFrom.insert(cur);
            }
        }
    }
}