#include "board.h"
#define IS_WHITE true
#define IS_BLACK false

Square::Square(int posX, int posY) : m_posX(posX), m_posY(posY) {};

void Square::moveHere(Piece* piece)
{
    m_piece = piece;
}

Piece* Square::getPiece()
{
    return m_piece;
}

Board::Board()
{
    initBoard();
}

void Board::initBoard()
{
    //Initialize Square objects
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = new Square(i, j);
            board[i][j]->moveHere(nullptr);
        }
    }
    // Populate pawn starting positions
    for (Square* p : board[1])
    {
        p->moveHere(new Pawn(IS_WHITE));
    }
    for (Square* p : board[6])
    {
        p->moveHere(new Pawn(IS_BLACK));
    }
    //Populate other pieces
    board[0][0]->moveHere(new Rook(IS_WHITE));
    board[0][1]->moveHere(new Knight(IS_WHITE));
    board[0][2]->moveHere(new Bishop(IS_WHITE));
    board[0][3]->moveHere(new Queen(IS_WHITE));
    board[0][4]->moveHere(new King(IS_WHITE));
    board[0][5]->moveHere(new Bishop(IS_WHITE));
    board[0][6]->moveHere(new Knight(IS_WHITE));
    board[0][7]->moveHere(new Rook(IS_BLACK));
    board[7][0]->moveHere(new Rook(IS_BLACK));
    board[7][1]->moveHere(new Knight(IS_BLACK));
    board[7][2]->moveHere(new Bishop(IS_BLACK));
    board[7][3]->moveHere(new Queen(IS_BLACK));
    board[7][4]->moveHere(new King(IS_BLACK));
    board[7][5]->moveHere(new Bishop(IS_BLACK));
    board[7][6]->moveHere(new Knight(IS_BLACK));
    board[7][7]->moveHere(new Rook(IS_BLACK));
}

void Board::updateDanger() { //Update board danger.
    for (auto &i : board) { //Wipe all current danger values.
        for (auto &j : i) {
            j->inDangerFrom.clear();
        }
    }

    //Iterate over all pieces
    //i: y, j: x
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j]->getPiece()) { //If piece is present on current square, check danger.
                Square* s = board[i][j];

                //Iterate over board again to update squares in danger from this piece.
                // k: y, m: x
                for (int k = 0; k < BOARD_SIZE; k++)
                {
                    for (int m = 0; m < BOARD_SIZE; m++)
                    {
                        if (s->getPiece()->checkMove(k, m, i, j)) //If piece can legally move here, update danger.
                        {
                            board[k][m]->inDangerFrom.insert(s);
                        }
                    }
                }
            }
        }
    }
}