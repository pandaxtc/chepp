#include "piece.h"

bool Rook::checkMove(int newX, int newY, int curX, int curY)
{
    if (newX == curX && newY == curY)
    {
        return true;
    }
    else
        return false;
}