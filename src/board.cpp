#include <iostream>
#include "board.h"
#include "piece.h"
#define IS_WHITE true
#define IS_BLACK false

Square::Square(int posX, int posY) : posX(posX), posY(posY){
    m_piece = nullptr;
};

void Square::moveHere(Piece* piece)
{
    m_piece = piece;
}

Piece* Square::getPiece()
{
    return m_piece;
}

bool Square::hasPiece() {
    //cout << "hasPiece(): CHECKING FOR PIECE..." << endl;
    //cout << m_piece << endl;
    //cout << (m_piece == nullptr) << endl;
    return (bool) m_piece;
}

Board::Board()
{
    initBoard();
    updateDanger();
}

void Board::initBoard()
{
    //Initialize Square objects
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            p_squares[i][j] = new Square(i, j);
            p_squares[i][j]->moveHere(nullptr);
        }
    }
    // Populate pawn starting positions
    for (Square* p : p_squares[1])
    {
        p->moveHere(new Pawn(IS_WHITE));
    }
    for (Square* p : p_squares[6])
    {
        p->moveHere(new Pawn(IS_BLACK));
    }
    //Populate other pieces
    p_squares[0][0]->moveHere(new Rook(IS_WHITE));
    p_squares[0][1]->moveHere(new Knight(IS_WHITE));
    p_squares[0][2]->moveHere(new Bishop(IS_WHITE));
    p_squares[0][3]->moveHere(new Queen(IS_WHITE));
    p_squares[0][4]->moveHere(new King(IS_WHITE));
    p_squares[0][5]->moveHere(new Bishop(IS_WHITE));
    p_squares[0][6]->moveHere(new Knight(IS_WHITE));
    p_squares[0][7]->moveHere(new Rook(IS_WHITE));

    p_squares[7][0]->moveHere(new Rook(IS_BLACK));
    p_squares[7][1]->moveHere(new Knight(IS_BLACK));
    p_squares[7][2]->moveHere(new Bishop(IS_BLACK));
    p_squares[7][3]->moveHere(new Queen(IS_BLACK));
    p_squares[7][4]->moveHere(new King(IS_BLACK));
    p_squares[7][5]->moveHere(new Bishop(IS_BLACK));
    p_squares[7][6]->moveHere(new Knight(IS_BLACK));
    p_squares[7][7]->moveHere(new Rook(IS_BLACK));
}

void Board::updateDanger() { //Update p_squares danger.
    //cout << "STARTED DANGER CHECK..." << endl;
    for (auto &i : p_squares) { //Wipe all current danger values.
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
            //cout << "updateDanger(): INSPECTING " << i << ", " << j << endl;
            if (p_squares[i][j]->hasPiece())
            {
                //cout << "updateDanger(): PIECE FOUND! MOVING INTO PIECE" << endl;
                Piece* p = p_squares[i][j]->getPiece();
                p->checkMove(j ,i, p_squares);
            }
        }
    }
}

void Board::move(int posX, int posY, int newX, int newY) {
    if (p_squares[newY][newX]->hasPiece()) {
        p_takenPieces.insert(p_squares[newY][newX]->getPiece());
    }
    p_squares[newY][newX]->moveHere(p_squares[posY][posX]->getPiece());
    p_squares[posY][posX]->moveHere(nullptr);
}
