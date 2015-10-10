#ifndef HUMAN_INTERFACE_H
#define HUMAN_INTERFACE_H

#pragma once
#include <iostream>
#include <string>
#include "Position2D.h"
using namespace std;

class HumanInterface{
public:
	Position2D* introduceBoardPosition();
	Position2D* wrongPositionReintroduce();
	Position2D* usedPositionReintroduce();
private:

protected:
	HumanInterface();
};

#endif