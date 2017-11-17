//Board implementation




/*
 * KEEP THIS PART SIMPLISTIC - DO THE BRUTE WORK IN THE ChessBoard FUNCTIONS

class ChessBoardNode {
    Piece p; //stored piece
    String index; //"a1"
private:
    Piece returnPiece(); //returns piece stored in node
    string returnIndex(); //returns index of board (a1)
    void empty(); //removes piece from board
    void insert(); //adds piece to node
};
Oops, probably scrap rofl i thought of a more space efficient implementation
*/






class ChessBoard {
private:
    int bPoints;
    int wPoints;
    string capturedBlack[];
    string caputuredWhite[];
    list<Pieces> onBoard;

    Pawn WPawn1, WPawn2, WPawn3, WPawn4, WPawn5, WPawn6, WPawn7, WPawn8,
        BPawn1, BPawn2, BPawn3, BPawn4, BPawn5, BPawn6, BPawn7, BPawn8;
    Rook WRook1, WRook2, BRook1, BRook2;
    Bishop WBish1, WBish2, BBish1, BBish2;
    Knight WKnight1, WKnight2, BKnight1, BKnight2;
    //WE CAN MOVE THESE VAR DECLARATIONS TO THE SETTER FUNCTION

public:
    ChessBoard(); //initialize board, set pieces in proper space
    bool move(string move); //move with unprocessed notation
    bool move(Piece piece, string col, string row); //move with processed location
    <SomeType> printBoard(); //prints out board by iterating through all the pieces and checking index.
                // There's no better way unless we keep track of the uncaptured pieces :D
    int getWhitePoints(); //return white points
    string* getWhiteCaptured();
    int getBlackPoints(); //return black points
    string* getBlackCaptured();
    ~ChessBoard(); //end the game
};
/**
 * Initializes all the pieces and the points for the game.
 */
ChessBoard::ChessBoard() {
    //TODO
    //hf rofl
}
/**
 * Checks whether the move is valid, and moves the piece if valid.
 * @param move: the unprocessed move string
 * @return true if valid, false if not.
 */
bool ChessBoard::move(string move) {

}
/**
 * moves the piece.
 * @param piece: the piece to move
 * @param col: the column to move ti
 * @param row: the row to move to
 */
void ChessBoard::move(Piecce piece, string col, string row) {

}
int ChessBoard::getWhitePoints() {
    return wPoints;
}
int ChessBoard::getBlackPoints() {
    return bPoints;
}

string* ChessBoard::getBlackCaptured() {
    return capturedBlack;
}
string* ChessBoard::getWhiteCaptured() {
    return capturedWhite;
}

