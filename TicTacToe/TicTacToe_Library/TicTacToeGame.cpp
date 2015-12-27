#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(Player* player1, Player* player2) {
	playerTurn = CROSS;

	this->crossPlayer = player1;
	player1->setId(CROSS);

	this->circlePlayer = player2;
	player2->setId(CIRCLE);
	

	while (1) {
		playTurn();
		board.showBoard();
		AnybodyWon();
	}
}

void TicTacToeGame::AnybodyWon() {
	short winnerPlayer;
	winnerPlayer = board.whoHaveThreeInRow();
	if (winnerPlayer != 0) {
		if (winnerPlayer == CROSS) cout << "Gana jugador X" << endl;
		else cout << "Gana jugador O" << endl;
		crossPlayer->endGame(&board, winnerPlayer);
		circlePlayer->endGame(&board, winnerPlayer);
		board.cleanBoard();
		cin.get();
	}
	else if (board.isDraw()) {
		cout << "Empate" << endl;
		crossPlayer->endGame(&board, 0);
		circlePlayer->endGame(&board, 0);
		board.cleanBoard();
		cin.get();
	}
}

int TicTacToeGame::playTurn() {
	
	if (playerTurn == CROSS) 
		crossPlayer->turn(&board);
	else 
		circlePlayer->turn(&board);

	changePlayer();
	
	return 0;
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
