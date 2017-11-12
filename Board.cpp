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

    Pawn WPawn1, WPawn2, WPawn3, WPawn4, WPawn5, WPawn6, WPawn7, WPawn8,
        BPawn1, BPawn2, BPawn3, BPawn4, BPawn5, BPawn6, BPawn7, BPawn8;
    Rook WRook1, WRook2, BRook1, BRook2;
    Bishop WBish1, WBish2, BBish1, BBish2;


    //NEED SOMETHING TO KEEP TRACK OF CAPTURED PIECES IN STRING FORM
public:
    ChessBoard(); //initialize board, set pieces in proper space
    bool move(string); //move with unprocessed notation
    bool move(init, final); //move with processed location
    <SomeType> printBoard(); //prints out board by iterating through all the pieces and checking index.
                // There's no better way unless we keep track of the uncaptured pieces :D
    int getWhitePoints(); //return white points
    int getBlackPoints(); //return black points
    ~ChessBoard(); //end the game
};

ChessBoard::ChessBoard() {
    //TODO
    //hf rofl
}