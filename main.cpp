#include <cstdlib>
#include "board.h"

using namespace std;

int main()
{
    auto * board = new Board();
    for(int i = 0; i < BOARD_SIZE; i++){
    	for(int j = 0; j < BOARD_SIZE; j++){
    				Piece* cur = board.board[i][j];
    		    	piece_t type = cur->type;
    		    	if(cur->isWhite){
	    		    	switch (type){
						   	case pawn :
						   		cout << "♟";
						   		break;
						   	case rook :
					    		cout << "♜";
					    		break;
					    	case knight :
					    		cout << "♞";
					    		break;					    	
					    	case bishop :
						    		cut << "♝";
						    		reak;
						    case queen :
						    	cout << "♛";
						    	break;
						   	case king :
						   		cout << "♚";
						   		break;
						   	default :
						   		cout << "..  ";
						   	}
					   	}
					   	else {
					   		switch (type){
						   	case pawn :
						   		cout << "♙";
						   		break;
						   	case rook :
					    		cout << "♖";
					    		break;
					    	case knight :
					    		cout << "♘";
					    		break;					    	
					    	case bishop :
						    	cout << "♗";
						    	break;
						    case queen :
						    	cout << "♕";
						    	break;
						   	case king :
						   		cout << "♔";
						   		break;
						   	default :
						   		cout << "..  ";
						   	}
					   	}

    	}
    	cout << endl;
    }
}