#include "piece.h"
#include "board.h"

Pawn::Pawn(bool isWhite) : Piece(isWhite) {
    m_firstMove = true;
}

bool Pawn::checkMove(int newX, int newY, int curX, int curY, Board& board)
{
    if (isWithinBounds(newX, newY))
    {
        if (newX == curX)
        {
            if (newY == curY + 1)
            {
                m_firstMove = false;
                return true;
            }
            else if (newY == curY + 2 && m_firstMove)
            {
                m_firstMove = false;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
};