#include "piece.h"

bool Knight::checkMove(int newX, int newY, int curX, int curY)
{
    if (isWithinBounds(newX, newY))
    {
        if (newY == curY + 2 || newY == curY - 2)
        {
            if (newX == curX + 1 | newX == curX - 1)
            {
                return true;
            }
            else
                return false;
        }
        else if (newY == curY + 1 || newY == curY - 1)
        {
            if (newX == curX + 2 | newX == curX - 2)
            {
                return true;
            }
            else
                return false;
        }
    }
}