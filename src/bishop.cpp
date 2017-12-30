#include "piece.h"
#include "board.h"

void Bishop::checkMove(int curx, int cury, Square* squares[8][8])
{
    int tempx = curx;
    int tempy = cury;
    while (tempx < 8 && tempy < 8) { //up right
        tempx++;
        tempy++;
        if (!squares[tempy][tempx]->getPiece()) {
            if (squares[tempy][tempx]->getPiece()->m_isWhite != squares[cury][curx]->getPiece()->m_isWhite) {
                squares[tempy][tempx]->inDangerFrom.insert(squares[curx][cury]);
            }
            break;
        }
    }
    tempx = curx;
    tempy = cury;
    while (tempx >= 0 && tempy < 8) { //up left
        tempx--;
        tempy++;
        if (!squares[tempy][tempx]->getPiece()) {
            if (squares[tempy][tempx]->getPiece()->m_isWhite != squares[cury][curx]->getPiece()->m_isWhite) {
                squares[tempy][tempx]->inDangerFrom.insert(squares[curx][cury]);
            }
            break;
        }
    }
    tempx = curx;
    tempy = cury;
    while (tempx >= 0 && tempy >= 0) { //down left
        tempx--;
        tempy--;
        if (!squares[tempy][tempx]->getPiece()) {
            if (squares[tempy][tempx]->getPiece()->m_isWhite != squares[cury][curx]->getPiece()->m_isWhite) {
                squares[tempy][tempx]->inDangerFrom.insert(squares[curx][cury]);
            }
            break;
        }
    }
    tempx = curx;
    tempy = cury;
    while (tempx < 8 && tempy >= 0) { //down right
        tempx++;
        tempy--;
        if (!squares[tempy][tempy]->getPiece()) {
            if (squares[tempy][tempx]->getPiece()->m_isWhite != squares[cury][curx]->getPiece()->m_isWhite) {
                squares[tempy][tempx]->inDangerFrom.insert(squares[curx][cury]);
            }
            break;
        }
    }
}