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

/**
 * @file piece.h
 * Header file for the Piece class and its subclasses. Contains Piece, Pawn, King, Queen, Bishop, Knight, Rook.
 */

#ifndef CHEPP_PIECE_H
#define CHEPP_PIECE_H
#define BOARD_SIZE 8 // Size of chessboard. DO NOT CHANGE!

#include <cstdlib>

using namespace std;

struct Square; // Forward declaration for Square struct

enum piece_t { /**< Enum for piece type identifier */
    king,
    queen,
    bishop,
    knight,
    rook,
    pawn
};

//<Pawn,King,Queen,Bishop,Knight,Rook> is Piece
//Square contains Piece

/**
 * @class Piece
 * @brief Virtual base class for the individual piece classes.
 */
struct Piece {
public:
    const bool isWhite; /**< Piece color identifier. */
    const piece_t type; /**< Piece type identifier. */
    bool firstMove; /**< True if is first move. Used for pawn movement/castling. */
    int posX = 0; /**< x position of Square Piece is on */
    int posY = 0; /**< y position of Square Piece is on */

    /**
     * @brief Piece base class constructor.
     * @param isWhite bool
     * @param type piece_t Piece type.
     */
    explicit Piece(bool isWhite, piece_t type) : isWhite(isWhite), type(type) {
        firstMove = true;
    }

    /**
     * @brief Given board state, mark all squares that piece at position (curX,curY) are capable of moving to.
     * @param board Square*[][] Array of Square class pointers representing board state.
     *
     * This function passes the Square the piece is on to all Squares in board[][] that the Piece on said
     * Square is capable of moving to. This allows an unordered_set on every Square to maintain a list of all Squares
     * containing pieces capable of moving to it (essentially a list of all potential moves). This behavior of move
     * validity detection is in reverse from how a human would likely consider a chess move. The compilation of all
     * potential moves from a given board state is useful because it allows for the easy validation of any given moves
     * (check if given move is also a potential move) and automatic checkmate detection.
     */
    virtual void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) = 0;
};

/**
 * @class Pawn
 * @brief Represents Pawn piece.
 */
struct Pawn : public Piece {
public:
    explicit Pawn(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;
};

/**
 * @class King
 * @brief Represents King piece.
 */
struct King : public Piece {
public:
    explicit King(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;

};

/**
 * @class Bishop
 * @brief Represents Bishop piece.
 */
struct Bishop : public Piece {
public:
    explicit Bishop(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;
};

/**
 * @class Knight
 * @brief Represents Knight piece.
 */
struct Knight : public Piece {
private:
    bool checkKnightMove(int newX, int newY, Square* board[BOARD_SIZE][BOARD_SIZE]);

public:
    explicit Knight(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;
};

/**
 * @class Rook
 * @brief Represents Rook piece.
 */
struct Rook : public Piece {
public:
    explicit Rook(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;
};

/**
 * @class Queen
 * @brief Represents Queen piece.
 */
struct Queen : public Piece {
public:
    explicit Queen(bool isWhite);

    void markDanger(Square *board[BOARD_SIZE][BOARD_SIZE]) override;
};


#endif //CHEPP_PIECE_H
