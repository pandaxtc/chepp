#include <cstdlib>
#include <iostream>
#include <regex>
#include "piece.h"
#include "board.h"

using namespace std;

void printBoard(Board* board);
void printDanger(Board* board);

int main()
{
    //Game p_squares initialization
    auto * board = new Board();
    bool isWhiteTurn = false;

    //Regex for move notation: <letter><number><spaces><optional '-'><spaces><letter><number>
    regex rgx1(R"(^([a-hA-H][1-8])\s*-?\s*([a-hA-H][1-8])\s*$)");

    //Primary game loop
    while (true)
    {
        printBoard(board);
        isWhiteTurn = !isWhiteTurn;

        //Prompt user for input.
        cout << "> ";
        string input;

        //Check for input validity
        bool isValid = false;
        while (!isValid)
        {
            cin >> input;
            //Semantic validity
            cout << "RECEIVED INPUT " << input << endl;
            cout << "TESTING SEMANTIC VALIDITY..." << endl;

            smatch sm;
            if (input == "exit")
            {
                exit(1);
            }
            else if (!regex_match(input, sm, rgx1))
            {
                cout << "Invalid input, please try again." << endl << "> ";
            }
            else {
                cout << "SEMANTICALLY VALID!" << endl;
                //Logical validity
                /* backup regexer
                regex rgx2("([a-hA-H])([1-8])");
                sregex_iterator match(input.begin(), input.end(), rgx2);
                int posX = match->[0];
                int posY = match->[1];
                match++;
                int newX = match->[0];
                int newY = match->[1];
                */
                cout << "TESTING LOGICAL VALIDITY..." << endl;
                int posX = tolower(sm.str(1)[0]) - 'a';
                int posY = tolower(sm.str(1)[1]) - '1';
                int newX = tolower(sm.str(2)[0]) - 'a';
                int newY = tolower(sm.str(2)[1]) - '1';
                cout << posX << ", " << posY << endl;
                cout << newX << ", " << newY << endl;
                if (!board->p_squares[posY][posX]->hasPiece()) {
                    cout << "No piece on square " << input.substr(0, 1) << ", please try again." << endl << "> ";
                }
                else if (board->p_squares[posY][posX]->getPiece()->isWhite != isWhiteTurn) {
                    cout << "Incorrect piece color, please try again." << endl << "> ";
                }
                else {
                    //Move validity
                    cout << "LOGICALLY VALID!" << endl;
                    cout << "TESTING MOVE VALIDITY..." << endl;
                    ///* debug statements
                    cout << "POINTERS ON NEW SQUARE: " << endl;
                    for (Square* s : board->p_squares[newY][newX]->inDangerFrom) {
                        cout << s << endl;
                    }
                    cout << "CURRENT SQUARE POINTER:" << board->p_squares[posY][posX] << endl;
                    //*/
                    if (board->p_squares[newY][newX]->inDangerFrom.count(board->p_squares[posY][posX]) == 0) {
                        cout << "Invalid move, please try again." << endl << "> ";
                    }
                    else
                    {
                        cout << "MOVE VALID!" << endl;
                        board->move(posX, posY, newX, newY);
                        isValid = true;
                    }
                }
            }
        }

        board->updateDanger();

    }

}

//Outputs p_squares
void printBoard(Board* board)
{
    for (int i = BOARD_SIZE - 1; i >= 0; i--)
    {
        for (auto &j : board->p_squares[i])
        {
            if (j->hasPiece())
            {
                Square *cur = j;
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
            }
            else {
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
            bool inDanger = (cur->inDangerFrom.empty());
            if (inDanger)
            {
                cout << "x ";
            }
            else cout << "o ";
        }
        cout << endl;
    }
}

