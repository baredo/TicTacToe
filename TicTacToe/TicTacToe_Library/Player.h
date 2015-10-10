#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <iostream>
#include <string>
#include "TicTacToeBoard.h"
using namespace std;

class Player {
public:
	Player(string name, int idPlayer);
	virtual void turn(TicTacToeBoard* board) = 0;
	void setId(int id) { this->idPlayer = id; }
protected:
	string name;
	int idPlayer;

};

#endif
