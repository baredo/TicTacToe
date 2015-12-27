#ifndef COMPUTER_H
#define COMPUTER_H

#pragma once

#include "Player.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h> 

class Computer : public Player{
public:
	Computer(string name, int idPlayer);
	void turn(TicTacToeBoard* board);
	void checkLines(bool** board, short idPlayer);
	bool** transformBoardShortToBoolean(TicTacToeBoard* board, short idPlayer);
	void endGame(TicTacToeBoard* board, short idPlayer);
private:
	int calculateObjetiveFunction();
	void debugInformationAI();

	double varNumberMyValuesInRow = 0;
	double varNumberOtherValuesInRow = 0;
	double varMyValueSummationOfAllLines = 0;
	double varOtherValueSummationOfAllLines = 0;

	double weightNumberMyValuesInRow = 1;
	double weightNumberOtherValuesInRow = 1;
	double weightMyValueSummationOfAllLines = 1;
	double weightOtherValueSummationOfAllLines = 1;
};

#endif