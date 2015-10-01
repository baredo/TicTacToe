#ifndef TIC_TAC_TOE_GAME
#define TIC_TAC_TOE_GAME
#pragma once

#include "TicTacToeBoard.h"
#include "Position2D.h"

class TicTacToeGame {

public:
	TicTacToeGame();
	int playTurn(Position2D position);

private:
	short setValueInBoard(Position2D position);
	void changePlayer();

	TicTacToeBoard board;
	short playerTurn;
};

#endif
