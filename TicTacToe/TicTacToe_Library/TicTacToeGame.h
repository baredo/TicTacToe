#ifndef TIC_TAC_TOE_GAME
#define TIC_TAC_TOE_GAME
#pragma once

#include "TicTacToeBoard.h"
#include "Human.h"

class TicTacToeGame {

public:
	TicTacToeGame(Player* player1, Player* player2);
	int playTurn();

private:
	short setValueInBoard(Position2D position);
	void changePlayer();

	TicTacToeBoard board;
	Player* crossPlayer;
	Player* circlePlayer;
	short playerTurn;
};

#endif
