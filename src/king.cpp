#include "piece.h"

bool King::checkMove(int newX, int newY, int curX, int curY)
{
    if ((abs(newX - curX) == 1 || newX == curX) && (abs(newY - curY) || newY == curY))
    {
        return true;
    }
    else
        return false;
}