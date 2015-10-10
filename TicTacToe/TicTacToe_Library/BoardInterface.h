#ifndef BOARD_INTERFACE_H
#define BOARD_INTERFACE_H

#define BOARD_ROW 3
#define BOARD_COLUMN 3

#define CIRCLE 2
#define CROSS 1
#define VOID 0

#pragma once
#include <iostream>
#include <string>
#include "Position2D.h"

using namespace std;

class BoardInterface {
public:
	void showBoard();
	virtual short getValue(Position2D position) = 0;
private:

protected:
	BoardInterface();
};

#endif