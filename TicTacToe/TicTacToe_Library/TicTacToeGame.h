#ifndef TIC_TAC_TOE_GAME
#define TIC_TAC_TOE_GAME
#pragma once

#define BOARD_ROW 3
#define BOARD_COLUMN 3

#define CIRCLE 2
#define CROSS 1

#define USED_CELL 1

class TicTacToeGame {
public:
	TicTacToeGame();
	int playTurn(int row, int column);

private:
	void initBoard();
	int setCell(int row, int column);
	void changePlayer();
	bool isUsed(int row, int column);

	int** board;
	short playerTurn;
};

#endif
