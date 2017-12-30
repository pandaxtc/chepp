#include "piece.h"

bool Bishop::checkMove(int newX, int newY, int curX, int curY)
{
    if (isWithinBounds(newX, newY))
    {
        if (curY - newY == curX - newX)
        {
            return true;
        }
    }
}