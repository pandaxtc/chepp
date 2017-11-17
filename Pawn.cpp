//INCOMPLETE

/*
 * Someone can create complete the Pieces class for inheritance for more neat :DDDDDD its row, col, isWhite
 */
class Pawn {
    private:
        int row; //1-8, -1 if captured
        char col; //a-h, by convention always store as lowercase, z if captured
        boolean isWhite; //true if white else black
        <TYPE> pawnMoveSequence; //CUSTOM idk about this yet.
    public:
        Pawn(char col, int row, bool isWhite); //initialize the piece (ONLY use for init on board), bool is isWhite
        void validMoves(); //not sure what type we want this to be yet.
        void move(char col, int row); //we are going by char for cols and numb for rows
        ~Pawn(); //destructor, not sure what to to with this yet.
};
Pawn::Pawn(char col, int row, bool isWhite) {
    this->col = col;
    this->row = row;
    this->isWhite = isWhite;
}

void Pawn::validMoves() {
    //TODO, we can do this in board maybe
}

void Pawn::move(char col, int row) {
    this->col = col;
    this->row = row;
}

