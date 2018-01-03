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
 * @file main.cpp
 * Driver class for chepp. Handles interaction with the user, and interfaces between user input and the game
 * board classes.
 */

#include <cstdlib>
#include <iostream>
#include <regex>
#include "piece.h"
#include "board.h"

using namespace std;

void printBoard(Board* board);

void printDanger(Board* board);

///Controls operation of the game
int main() {
    ///Game board
    auto* board = new Board();
    bool isWhiteTurn = false;

    ///Regex for move notation: <letter><number><spaces><optional '-'><spaces><letter><number>
    regex rgx1(R"(^([a-hA-H][1-8])\s*-?\s*([a-hA-H][1-8])\s*$)");

    //Primary game loop
    while (true) {
        printBoard(board);
        isWhiteTurn = !isWhiteTurn;

        ///Input string.
        string input;

        //Check for input validity
        bool isValid = false;
        while (!isValid) {
            Square* p = board->isCheckmate(); // Check for checkmate
            if (p) {
                cout << (p->getPiece()->isWhite ? "White" : "Black") << " checkmate! Game over.";
                exit(0); // Game over
            }
            // Prompt user for input
            cout << "> ";
            cin >> input;
            // Semantic validity
            cout << "RECEIVED INPUT " << input << endl;
            cout << "TESTING SEMANTIC VALIDITY..." << endl;
            smatch sm;
            if (input == "exit") {
                exit(0);
            } else if (!regex_match(input, sm, rgx1)) {
                cout << "Invalid input, please try again." << endl;
            } else {
                cout << "SEMANTICALLY VALID!" << endl;
                // Logical validity
                cout << "TESTING LOGICAL VALIDITY..." << endl;
                int posX = tolower(sm.str(1)[0]) - 'a';
                int posY = tolower(sm.str(1)[1]) - '1';
                int newX = tolower(sm.str(2)[0]) - 'a';
                int newY = tolower(sm.str(2)[1]) - '1';
                cout << posX << ", " << posY << endl;
                cout << newX << ", " << newY << endl;
                if (!board->p_squares[posY][posX]->hasPiece()) {
                    cout << "No piece on square " << input.substr(0, 1) << ", please try again." << endl;
                } else if (board->p_squares[posY][posX]->getPiece()->isWhite != isWhiteTurn) {
                    cout << "Incorrect piece color, please try again." << endl;
                } else {
                    //Move validity
                    cout << "LOGICALLY VALID!" << endl;
                    cout << "TESTING MOVE VALIDITY..." << endl;
                    if (!board->move(posX, posY, newX, newY)) {
                        cout << "Invalid move, try again." << endl;
                    } else {
                        cout << "MOVE VALID!" << endl;
                        isValid = true;
                    }
                }
            }
        }

        board->updateDanger();

    }

}

/**
 * @brief Given a Board object, prints the chessboard it contains in a human-readable display.
 * @param Board Board Board object to print.
 *
 * Loops through the board and prints chess piece characters depending on piece type.
 *
 */
void printBoard(Board* board) {
    int start = BOARD_SIZE;
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        cout << start-- << " ";
        for (auto &j : board->p_squares[i]) {
            if (j->hasPiece()) {
                Square* cur = j;
                piece_t type = cur->getPiece()->type;

                if (cur->getPiece()->isWhite) {
                    switch (type) {
                        case pawn :
                            cout << "♟";
                            break;
                        case rook :
                            cout << "♜";
                            break;
                        case knight :
                            cout << "♞";
                            break;
                        case bishop :
                            cout << "♝";
                            break;
                        case queen :
                            cout << "♛";
                            break;
                        case king :
                            cout << "♚";
                            break;
                    }
                } else {
                    switch (type) {
                        case pawn :
                            cout << "♙";
                            break;
                        case rook :
                            cout << "♖";
                            break;
                        case knight :
                            cout << "♘";
                            break;
                        case bishop :
                            cout << "♗";
                            break;
                        case queen :
                            cout << "♕";
                            break;
                        case king :
                            cout << "♔";
                            break;
                    }
                }
            } else {
                cout << "\u2001";
            }
        }
        cout << endl;
    }
    printDanger(board);
}


//Outputs danger
void printDanger(Board* board)
{
    for (int i = BOARD_SIZE - 1; i >= 0; i--)
    {
        for (auto &j : board->p_squares[i])
        {
            Square* cur = j;
            bool inDanger = (!cur->inDangerFrom.empty());
            if (inDanger) {
                cout << "x ";
            } else cout << "o ";
        }
        cout << endl;
    }
}

