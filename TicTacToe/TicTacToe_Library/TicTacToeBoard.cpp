#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard(){
	this->board = new short*[BOARD_ROW];
	for (int i = 0; i < 3; i++) {
		this->board[i] = new short[BOARD_COLUMN];
	}
}

short TicTacToeBoard::setValue(Position2D position, short value){
	if (isPositionUsed(position) == USED_POSITION) {
		return USED_POSITION;
	}else {
		board[position.row][position.column] = value;
		return FREE_POSITION;
	}
}

short TicTacToeBoard::getValue(Position2D position) {
	return board[position.row][position.column];
}

bool TicTacToeBoard::isPositionUsed(Position2D position) {
	if (this->getValue(position) == CIRCLE || this->getValue(position) == CROSS) {
		return USED_POSITION;
	}
	else {
		return FREE_POSITION;
	}
}