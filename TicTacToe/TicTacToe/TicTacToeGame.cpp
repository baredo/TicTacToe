#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(){
	playerTurn = CROSS;
	this->initBoard();
}

int TicTacToeGame::playTurn(int row, int column){
	if (setCell(row, column) == USED_CELL) {
		return USED_CELL;
	}
	changePlayer();
}

void TicTacToeGame::initBoard(){
	this->board = new int*[BOARD_ROW];
	for (int i = 0; i < 3; i++) {
		this->board[i] = new int[BOARD_COLUMN];
	}
}

int TicTacToeGame::setCell(int row, int column){
	if (isUsed(row,column)){
		return USED_CELL;
	} else {
		this->board[row][column] = playerTurn;
		return 0;
	}
}

void TicTacToeGame::changePlayer(){
	if (this->playerTurn == CIRCLE) {
		this->playerTurn = CROSS;
	}
	else {
		this->playerTurn = CIRCLE;
	}
}

bool TicTacToeGame::isUsed(int row, int column){
	if (this->board[row][column] == CIRCLE || this->board[row][column] == CROSS) {
		return true;
	} else {
		return false;
	}
}
