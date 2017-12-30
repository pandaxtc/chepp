#include <cstdlib>
#include <iostream>
#include <regex>
#include "piece.h"
#include "board.h"

using namespace std;



int main()
{
    Board* board = new Board();
    bool whiteTurn = true;
    while (true)
    {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board->board[i][j]->getPiece()) {
                    Square *cur = board->board[i][j];
                    piece_t type = cur->getPiece()->type;
                    if (cur->getPiece()->m_isWhite) {
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
                            default :
                                cout << "..  ";
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
                            default :
                                cout << "..  ";
                        }
                    }
                }
            }
            cout << endl;
        }
        regex r("([a-h]|[A-H])[1-8]\\s*+-?\\s*+([a-h]|[A-H])[1-8]"); //regex is love regex is life
        string input;
        cin >> input; //notation: a6-a7 (move from a6 to a7) OR a6 a7 with any number of spaces in between OR a6 - a7 with any number of spaces in between
        if (input == "exit") exit(1);
        while (1) {
            if (!regex_match(input, r) || board->board[(int)input[1] - 1][(input[0] - 'H' <= 0) ? input[0] - 'A' : input[0] - 'a']->getPiece() == NULL) {
                //check if regex matches and if there is a piece on specified location
                //R E A D A B I L I T Y B O Y S
                cout << "Invalid input, please try again." << endl;
                cin >> input;
                if (input == "exit") exit(1);
            } else {
                break;
            }
        }
        if (board->board[(int)input[1] - 1][(input[0] - 'H' <= 0) ? input[0] - 'A' : input[0] - 'a']->getPiece()->m_isWhite != whiteTurn) {
            //check if and moving piece is of right color
            cout << "Wrong color" << endl;
        }
        //parsing input
        Square* from = board->board[(int)input[1] - 1][(input[0] - 'H' <= 0) ? input[0] - 'A' : input[0] - 'a'];
        Square* to = board->board[(int)input[input.size()]][(input[input.size() - 1] - 'H' <= 0) ? input[input.size() - 1] - 'A' : input[input.size() - 1] - 'a'];
        unordered_set<Square*>::const_iterator got = to->inDangerFrom.find(from);
        if (got == to->inDangerFrom.end()) {
            //TODO Print error message and go back to cin!
            cout << "Invalid input, please try again." << endl;
        } else {
            //TODO MOVE THE PIECE
            cout << "Yay!" << endl;
        }


        //TODO implement moving!
        break; //for debug purposes
    }
}