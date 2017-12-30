#include <cstdlib>
#include <iostream>
#include "piece.h"
#include "board.h"

using namespace std;

int main()
{
    Board* board = new Board();
    for(int i = 0; i < BOARD_SIZE; i++)
    {
    	for(int j = 0; j < BOARD_SIZE; j++)
        {
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
}