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

void printBoard(Board *board);

void printDanger(Board* board);

///Controls operation of the game
int main() {
    ///Game board
    auto *board = new Board();
    bool isWhiteTurn = false;

    ///Regex for move notation: <letter><number><spaces><optional '-'><spaces><letter><number>
    regex moveRgx(R"(^\s*([a-h][1-8])\s*-?\s*([a-h][1-8])\s*$)", regex::icase);
    regex castleRgx(R"(^\s*castle\s*(k|q)\s*$)");
    regex promotionRgx(R"(^\s*([Q,R,B,K,q,r,b,k])\s*$)");

    //Primary game loop
    while (true) {
        printBoard(board);
        isWhiteTurn = !isWhiteTurn;

        ///Input string.
        string input;

        //Check for input validity
        bool isValid = false;
        while (!isValid) {
            Square *pieceInCheckmate = board->inCheckmate(); // Check for checkmate
            if (pieceInCheckmate) {
                cout << (pieceInCheckmate->getPiece()->isWhite ? "White" : "Black") << " checkmate! Game over.";
                exit(0); // Game over
            }
            Square *pieceInCheck = board->inCheck();
            if (pieceInCheck) {
                cout << (pieceInCheck->getPiece()->isWhite ? "White" : "Black") << " king in check!";
            }
            // Prompt user for input
            cout << (isWhiteTurn ? "White" : "Black") << "> ";
            getline(cin, input);
            // Semantic validity
            smatch moveMatch;
            smatch castleMatch;
            if (input == "exit" || input == "quit") {
                exit(0);
            } else if (!regex_match(input, moveMatch, moveRgx)) { // If move regex does not match
                if (regex_match(input, castleMatch, castleRgx)) { // If castle regex matches
                    cout << castleMatch.str(0);
                    if (!board->castle(isWhiteTurn, castleMatch.str(1)[0] == 'k')) { // If castle is invalid
                        cout << "Invalid move, please try again." << endl;
                    } else { //Else if castle valid
                        isValid = true; // Move was valid
                    }
                } else { // If castle regex does not match
                    cout << "Invalid input, please try again." << endl; // No regexes matched
                }
            } else {
                // Logical validity
                int posX = tolower(moveMatch.str(1)[0]) - 'a';
                int posY = tolower(moveMatch.str(1)[1]) - '1';
                int newX = tolower(moveMatch.str(2)[0]) - 'a';
                int newY = tolower(moveMatch.str(2)[1]) - '1';
                //cout << posX << ", " << posY << endl;
                //cout << newX << ", " << newY << endl;
                if (!board->p_squares[posY][posX]->hasPiece()) {
                    cout << "No piece on square " << moveMatch.str(1) << ", please try again." << endl;
                } else if (board->p_squares[posY][posX]->getPiece()->isWhite != isWhiteTurn) {
                    cout << "Incorrect piece color, please try again." << endl;
                } else {
                    //Move validity
                    if (!board->move(posX, posY, newX, newY)) {
                        cout << "Invalid move, try again." << endl;
                    } else {
                        isValid = true;
                        if (board->canPromote(isWhiteTurn)) {
                            cout << "Promote pawn at (" << newX << ", " << newY << ") to what piece?" << endl;
                            cout << "(Q)ueen (R)ook (B)ishop (K)night" << endl;
                            cout << (isWhiteTurn ? "White" : "Black") << ">";
                            cin >> input;
                            smatch promotionMatch;
                            while (!regex_match(input, promotionMatch, promotionRgx)) {
                                cout << "Invalid input, please try again." << endl;
                                cin >> input;
                            }
                            board->promote(newX, newY, tolower(promotionMatch.str(1)[0]));
                        }
                    }
                }
            }
        }
    }
}

/**
 * @brief Given a Board object, prints the chessboard it contains in a human-readable display.
 * @param Board Board Board object to print.
 *
 * Loops through the board and prints chess piece characters depending on piece type.
 *
 */
void printBoard(Board *board) {
    int start = BOARD_SIZE;
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        cout << start-- << " ";
        for (auto &j : board->p_squares[i]) {
            if (j->hasPiece()) {
                Square *cur = j;
                piece_t type = cur->getPiece()->type;

                if (cur->getPiece()->isWhite) {
                    switch (type) {
                        case pawn :
                            cout << "P ";
                            break;
                        case rook :
                            cout << "R ";
                            break;
                        case knight :
                            cout << "N ";
                            break;
                        case bishop :
                            cout << "B ";
                            break;
                        case queen :
                            cout << "Q ";
                            break;
                        case king :
                            cout << "K ";
                            break;
                    }
                } else {
                    switch (type) {
                        case pawn :
                            cout << "p ";
                            break;
                        case rook :
                            cout << "r ";
                            break;
                        case knight :
                            cout << "n ";
                            break;
                        case bishop :
                            cout << "b ";
                            break;
                        case queen :
                            cout << "q ";
                            break;
                        case king :
                            cout << "k ";
                            break;
                    }
                }
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << "  a b c d e f g h " << endl;
    //printDanger(board);
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