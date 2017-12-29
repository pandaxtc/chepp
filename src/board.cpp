#include "board.h"

Square::Square(int posX, int posY) : m_posX(posX), m_posY(posY) {};

void Square::moveHere(Piece* piece) {
    m_piece = piece;
}

Piece* Square::getPiece() {
    return m_piece;
}

Board::Board() {
    initBoard();
}

void Board::initBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = new Square(i, j);
        }
    }
    for (Square* p : board[1]) {
        p->moveHere(new Pawn(true));
    }
}