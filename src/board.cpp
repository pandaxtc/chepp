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
#include "board.h"
#include "piece.h"

#define IS_WHITE true
#define IS_BLACK false

Square::Square(int posX, int posY) : posX(posX), posY(posY) {
    m_piece = nullptr;
};

void Square::moveHere(Piece *piece) {
    m_piece = piece;
    if (m_piece != nullptr) {
        m_piece->posY = posY;
        m_piece->posX = posX;
    }
}

Piece *Square::getPiece() {
    return m_piece;
}

bool Square::hasPiece() {
    return (bool) m_piece;
}

Board::Board() {
    initBoard();
    updateDanger();
}

void Board::initBoard() {
    // Initialize Square objects
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            p_squares[i][j] = new Square(j, i);
            p_squares[i][j]->moveHere(nullptr);
        }
    }
    // Hardcoded.
    // Populate pawn starting positions
    for (Square *p : p_squares[1]) {
        p->moveHere(new Pawn(IS_WHITE));
    }
    for (Square *p : p_squares[6]) {
        p->moveHere(new Pawn(IS_BLACK));
    }
    // Populate other pieces
    p_squares[0][0]->moveHere(new Rook(IS_WHITE));
    p_squares[0][1]->moveHere(new Knight(IS_WHITE));
    p_squares[0][2]->moveHere(new Bishop(IS_WHITE));
    p_squares[0][3]->moveHere(new Queen(IS_WHITE));
    p_squares[0][4]->moveHere(new King(IS_WHITE));
    p_squares[0][5]->moveHere(new Bishop(IS_WHITE));
    p_squares[0][6]->moveHere(new Knight(IS_WHITE));
    p_squares[0][7]->moveHere(new Rook(IS_WHITE));

    p_squares[7][0]->moveHere(new Rook(IS_BLACK));
    //p_squares[7][1]->moveHere(new Knight(IS_BLACK));
    //p_squares[7][2]->moveHere(new Bishop(IS_BLACK));
    //p_squares[7][3]->moveHere(new Queen(IS_BLACK));
    p_squares[7][4]->moveHere(new King(IS_BLACK));
    p_squares[7][5]->moveHere(new Bishop(IS_BLACK));
    p_squares[7][6]->moveHere(new Knight(IS_BLACK));
    p_squares[7][7]->moveHere(new Rook(IS_BLACK));
}

void Board::updateDanger() { // Update board danger markers
    for (auto &row : p_squares) { // Wipe all current danger markers
        for (auto &piece : row) {
            piece->inDangerFrom.clear();
        }
    }

    // Iterate over all pieces and populate danger markers. Non-king pieces go first.
    // i: y, j: x
    unordered_set<Square *> kings;
    for (auto &row : p_squares) {
        for (auto &square : row) {
            if (square->hasPiece()) {
                Piece *p = square->getPiece();
                if (p->type != king) {
                    p->markDanger(p_squares);
                } else if (p->type == king) {
                    kings.insert(square);
                }
            }
        }
    }
    for (auto &king : kings) {
        king->getPiece()->markDanger(p_squares);
    }
}

bool Board::move(int posX, int posY, int newX, int newY) {
    if (p_squares[newY][newX]->inDangerFrom.count(p_squares[posY][posX]) == 0) {
        return false;
    } else {
        Piece* taken = nullptr;
        if (p_squares[newY][newX]->hasPiece()) {
            taken = p_squares[newY][newX]->getPiece();
            p_takenPieces.insert(taken);
        }
        p_squares[newY][newX]->moveHere(p_squares[posY][posX]->getPiece());
        p_squares[posY][posX]->moveHere(nullptr);

        updateDanger();

        Square* king = nullptr;
        for (auto &row : p_squares) { // Find king
            for (auto &square : row) {
                if (square->hasPiece() &&
                    square->getPiece()->type == piece_t::king &&
                    square->getPiece()->isWhite == p_squares[newY][newX]->getPiece()->isWhite) {
                    king = square;
                }
            }
        }

        bool isInCheck = false;
        if (king != nullptr) { // Check if king is in check
            for (auto &s : king->inDangerFrom) {
                if (s->getPiece()->isWhite != king->getPiece()->isWhite) {
                    isInCheck = true;
                }
            }
        }

        if (isInCheck) { // If king still in check after move, invalidate move
            p_squares[posY][posX]->moveHere(p_squares[newY][newX]->getPiece());
            p_squares[newY][newX]->moveHere(taken);
            updateDanger();
            return false;
        }

        return true;
    }
}

bool Board::castle(bool isWhiteTurn, bool kingSide) {
    Square *king = nullptr;
    for (auto &row : p_squares) {
        for (auto &square : row) {
            if (square->hasPiece()) {
                if (square->getPiece()->type == piece_t::king && square->getPiece()->isWhite == isWhiteTurn) {
                    king = square;
                    break;
                }
            }
        }
        if (king != nullptr) {
            break;
        }
    }

    bool inCheck = false;
    for (auto *s : king->inDangerFrom) {
        if (s->getPiece()->isWhite != king->getPiece()->isWhite) {
            inCheck = true;
        }
    }

    if (king != nullptr && king->getPiece()->firstMove && !inCheck) {
        int kingX = king->posX;
        int kingY = king->posY;
        if (kingSide && p_squares[kingY][BOARD_SIZE - 1]->hasPiece() &&
            p_squares[kingY][BOARD_SIZE - 1]->getPiece()->type == rook &&
            p_squares[kingY][BOARD_SIZE - 1]->getPiece()->firstMove) {
            for (int posX = kingX + 1; posX < BOARD_SIZE - 1; posX++) {
                if (p_squares[kingY][posX]->hasPiece()) {
                    return false;
                }
                else {
                    for (auto *s : p_squares[kingY][posX]->inDangerFrom) {
                        if (s->getPiece()->isWhite != isWhiteTurn) {
                            return false;
                        }
                    }
                }
            }
            p_squares[kingY][kingX + 2]->moveHere(king->getPiece());
            p_squares[kingY][kingX]->moveHere(nullptr);
            p_squares[kingY][kingX + 1]->moveHere(p_squares[kingY][BOARD_SIZE - 1]->getPiece());
            p_squares[kingY][BOARD_SIZE - 1]->moveHere(nullptr);
            return true;
        } else if (!kingSide && p_squares[kingY][0]->hasPiece() &&
                   p_squares[kingY][0]->getPiece()->type == rook &&
                   p_squares[kingY][0]->getPiece()->firstMove) {
            for (int posX = kingX - 1; posX > 0; posX--) {
                if (p_squares[kingY][posX]->hasPiece()) {
                    return false;
                }
                else {
                    for (auto *s : p_squares[kingY][posX]->inDangerFrom) {
                        if (s->getPiece()->isWhite != isWhiteTurn) {
                            return false;
                        }
                    }
                }
            }
            p_squares[kingY][kingX - 3]->moveHere(king->getPiece());
            p_squares[kingY][kingX]->moveHere(nullptr);
            p_squares[kingY][kingX - 2]->moveHere(p_squares[kingY][0]->getPiece());
            p_squares[kingY][0]->moveHere(nullptr);
            return true;
        }

    } else {
        return false;
    }
}


bool Board::canPromote(bool isWhiteTurn) {
    if (isWhiteTurn) {
        for (auto &square : p_squares[BOARD_SIZE - 1]) {
            if (square->hasPiece() && square->getPiece()->isWhite && square->getPiece()->type == pawn) {
                return true;
            }
        }
    } else {
        for (auto &square : p_squares[0]) {
            if (square->hasPiece() && !square->getPiece()->isWhite && square->getPiece()->type == pawn) {
                return true;
            }
        }
    }
    return false;
}

void Board::promote(int posX, int posY, int input) {
    bool isWhite = p_squares[posY][posX]->getPiece()->isWhite;
    switch (input) {
        case ('q') :
            p_squares[posY][posX]->moveHere(new Queen(isWhite));
            break;
        case ('r') :
            p_squares[posY][posX]->moveHere(new Rook(isWhite));
            break;
        case ('b') :
            p_squares[posY][posX]->moveHere(new Bishop(isWhite));
            break;
        case ('k') :
            p_squares[posY][posX]->moveHere(new Knight(isWhite));
            break;
        default:
            break;
    }
    updateDanger();
}

Square *Board::inCheckmate() {
    unordered_set<Square *> kings;
    for (auto &row : p_squares) {
        for (auto &square : row) {
            if (square->hasPiece() && square->getPiece()->type == king) {
                kings.insert(square);
            }
        }
    }
    for (auto &king : kings) {
        bool inDefiniteCheck = false; // Whether or not the King is in check & checking pieces are not in danger
        bool canMove = false;
        for (auto &row : p_squares) {
            for (auto &square : row) {
                for (Square *s : square->inDangerFrom) {
                    if (s == king) canMove = true;
                }
            }
        }
        for (auto &checkingPiece : king->inDangerFrom) {
            if (checkingPiece->getPiece()->isWhite != king->getPiece()->isWhite) { // If enemy piece is checking king
                bool checkingPieceIsSafe = true;
                for (auto &saviour : checkingPiece->inDangerFrom) {
                    if (saviour->getPiece()->isWhite == king->getPiece()->isWhite) { // If enemy piece is not in danger
                        checkingPieceIsSafe = false;
                    }
                }
                if (checkingPieceIsSafe) { // If even a single checking piece is safe, the checkmate requirements are fulfilled
                    inDefiniteCheck = true;
                }
            }
        }
        if (inDefiniteCheck && !canMove) { // If the king is in undeniable check and cannot move, return pointer to it.
            return king;
        }
    }
    return nullptr; // If no kings are in checkmate, return nullptr.
}

Square *Board::inCheck() {
    unordered_set<Square *> kings;
    for (auto &row : p_squares) {
        for (auto &square : row) {
            if (square->hasPiece() && square->getPiece()->type == king) {
                kings.insert(square);
            }
        }
    }
    for (auto &king : kings) {
        bool inCheck = false;
        for (auto &checkingPiece : king->inDangerFrom) {
            if (checkingPiece->getPiece()->isWhite != king->getPiece()->isWhite) { // If enemy piece is checking king
                inCheck = true;
            }
        }
        if (inCheck) {
            return king;
        }
    }
    return nullptr;
}
