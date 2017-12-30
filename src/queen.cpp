#include "piece.h"

bool Queen::checkMove(int newX, int newY, int curX, int curY)
{
    if (isWithinBounds(newX, newY))
    {
        if (curY - newY == curX - newX)
        {
            return true;
        }
        else if (newX == curX && newY == curY)
        {
            return true;
        }
    }
}