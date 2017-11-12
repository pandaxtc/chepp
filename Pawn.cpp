//INCOMPLETE
class Pawn {
    private:
        int row; //1-8, -1 if captured
        char col; //a-h, by convention always store as lowercase, z if captured
        boolean isWhite; //true if white else black
    public:
        void validMoves(); //not sure what type we want this to be yet.
        void move(char, int); //we are going by char for cols and numb for rows
        void getCaptured(); //set row and col to 1 and z,
};
void Pawn::validMoves() {

}

