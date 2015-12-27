#include "BoardInterface.h"

void BoardInterface::showBoard(){
	Position2D* position;
	int value = -1;
	for (int i = 0; i < BOARD_ROW; i++) {
		for (int j = 0; j < BOARD_COLUMN; j++) {
			position = new Position2D(i, j);
			value = getValue(*position);
			delete position;

			if (value == VOID) cout << " " << "|";
			if (value == CROSS) cout << "X" << "|";
			if (value == CIRCLE) cout << "O" << "|";			
		}
		cout << endl << "------" << endl;
	}
	cout << endl;
}

BoardInterface::BoardInterface(){
}
