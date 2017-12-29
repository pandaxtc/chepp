#include "piece.h"

Rook::Rook(bool isWhite) : Piece(isWhite) {};

bool Rook::checkMove(int posX, int posY, int curX, int curY) {
    return posX == curX && posY == curY;
};