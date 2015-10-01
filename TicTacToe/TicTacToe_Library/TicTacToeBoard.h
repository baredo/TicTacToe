#ifndef TIC_TAC_TOE_BOARD
#define TIC_TAC_TOE_BOARD
#pragma once
#include "Position2D.h"

#define CIRCLE 2
#define CROSS 1

#define BOARD_ROW 3
#define BOARD_COLUMN 3

#define USED_POSITION 1
#define FREE_POSITION 0

class TicTacToeBoard{
public:
	TicTacToeBoard();
	short setValue(Position2D position, short value);
	short getValue(Position2D position);

private:
	bool isPositionUsed(Position2D position);

	short** board;
};

#endif