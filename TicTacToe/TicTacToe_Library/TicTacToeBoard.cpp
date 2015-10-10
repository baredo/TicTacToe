#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard(){
	this->board = new short*[BOARD_ROW];
	for (int i = 0; i < 3; i++) {
		this->board[i] = new short[BOARD_COLUMN];
	}
	cleanBoard();
}

TicTacToeBoard::~TicTacToeBoard(){
	for (int i = 0; i < BOARD_COLUMN; i++) {
		delete board[i];
	}
	delete board;
}

short TicTacToeBoard::setValue(Position2D position, short value){
	if (isWrongPosition(position) == WRONG_POSITION) {
		return WRONG_POSITION;
	}else if(isPositionUsed(position) == USED_POSITION) {
		return USED_POSITION;
	} else {
		board[position.row][position.column] = value;
		return SUCCEFULL_SET_VALUE;
	}
}

short TicTacToeBoard::getValue(Position2D position) {
	return board[position.row][position.column];
}

short TicTacToeBoard::whoHaveThreeInRow(){
	int player[2] = { CROSS,CIRCLE };
	for (int i = 0; i < 2; i++) {
		//Rows
		if (board[0][0] == player[i] && board[0][1] == player[i] && board[0][2] == player[i]) return player[i];
		if (board[1][0] == player[i] && board[1][1] == player[i] && board[1][2] == player[i]) return player[i];
		if (board[2][0] == player[i] && board[2][1] == player[i] && board[2][2] == player[i]) return player[i];
		//Columns
		if (board[0][0] == player[i] && board[1][0] == player[i] && board[2][0] == player[i]) return player[i];
		if (board[0][1] == player[i] && board[1][1] == player[i] && board[2][1] == player[i]) return player[i];
		if (board[0][2] == player[i] && board[1][2] == player[i] && board[2][2] == player[i]) return player[i];
		//Diagonals
		if (board[0][0] == player[i] && board[1][1] == player[i] && board[2][2] == player[i]) return player[i];
		if (board[0][2] == player[i] && board[1][1] == player[i] && board[2][0] == player[i]) return player[i];
	}
	return false;
}

void TicTacToeBoard::cleanBoard(){
	Position2D* position;
	
	for (int i = 0; i < BOARD_ROW; i++) {
		for (int j = 0; j < BOARD_COLUMN; j++) {
			position = new Position2D(i, j);
			resetValue(*position);
		}
	}
	
	delete position;
}

short TicTacToeBoard::isPositionUsed(Position2D position) {
	if (this->getValue(position) == CIRCLE || this->getValue(position) == CROSS) {
		return USED_POSITION;
	}
	else {
		return FREE_POSITION;
	}
}

short TicTacToeBoard::isWrongPosition(Position2D position) {
	if (position.row < 0 || position.column < 0 || position.row >= BOARD_ROW || position.column >= BOARD_COLUMN) {
		return WRONG_POSITION;
	}
	else {
		return CORRECT_POSITION;
	}
}

void TicTacToeBoard::resetValue(Position2D position){
	board[position.row][position.column] = 0;
}
