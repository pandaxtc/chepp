#include "piece.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    m_firstMove = true;
}

bool Pawn::checkMove(int posX, int posY, int curX, int curY) {
    if (posX == curX) {
        if (posY == curY + 1) {
            m_firstMove = false;
            return true;
        }
        else if (posY == curY + 2 && m_firstMove) {
            m_firstMove = false;
            return true;
        }
        else return false;
    }
    return false;
};