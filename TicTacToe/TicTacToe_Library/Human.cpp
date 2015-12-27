#include "Human.h"

Human::Human(string name, int idPlayer) : Player(name, idPlayer), HumanInterface(){
}

void Human::turn(TicTacToeBoard* board){
	Position2D* position = introduceBoardPosition();
	short errorValue;

	do{
		errorValue = board->setValue(*position, idPlayer);

		if (errorValue == WRONG_POSITION) {
			position = wrongPositionReintroduce();
			errorValue = board->setValue(*position, idPlayer);
		}
		else if (errorValue == USED_POSITION) {
			position = usedPositionReintroduce();
			errorValue = board->setValue(*position, idPlayer);
		}
	} while (errorValue != SUCCEFULL_SET_VALUE);
	
	delete position;
}

void Human::endGame(TicTacToeBoard * board, short idPlayer){
}
