#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame() {
	playerTurn = CROSS;
}

int TicTacToeGame::playTurn(Position2D position) {
	bool isPositionUsed;
	
	isPositionUsed = setValueInBoard(position);
	changePlayer();
	
	return isPositionUsed;
}

short TicTacToeGame::setValueInBoard(Position2D position) {
	return this->board.setValue(position, playerTurn);
}

void TicTacToeGame::changePlayer() {
	if (this->playerTurn == CIRCLE) {
		this->playerTurn = CROSS;
	} else {
		this->playerTurn = CIRCLE;
	}
}
