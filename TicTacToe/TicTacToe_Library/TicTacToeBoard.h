#ifndef TIC_TAC_TOE_BOARD
#define TIC_TAC_TOE_BOARD
#pragma once
#include "Position2D.h"
#include "BoardInterface.h"

#define CIRCLE 2
#define CROSS 1

#define BOARD_ROW 3
#define BOARD_COLUMN 3

#define WRONG_POSITION 2
#define CORRECT_POSITION 0
#define USED_POSITION 1
#define FREE_POSITION 0
#define SUCCEFULL_SET_VALUE 0

class TicTacToeBoard : public BoardInterface{
public:
	TicTacToeBoard();
	~TicTacToeBoard();
	short setValue(Position2D position, short value);
	short getValue(Position2D position);
	short whoHaveThreeInRow();
	void cleanBoard();
	

private:
	short isPositionUsed(Position2D position);
	short isWrongPosition(Position2D position);
	void resetValue(Position2D position);

	short** board;
};

#endif