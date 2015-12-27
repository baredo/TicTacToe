#ifndef HUMAN_H
#define HUMAN_H

#pragma once

#include "Player.h"
#include "HumanInterface.h"

class Human :  public Player, public HumanInterface{
public:
	Human(string name, int idPlayer);
	void turn(TicTacToeBoard* board);
	void endGame(TicTacToeBoard* board, short idPlayer);
private:
};

#endif