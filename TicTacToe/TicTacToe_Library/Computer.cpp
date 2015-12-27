#include "Computer.h"

Computer::Computer(string name, int idPlayer) : Player(name, idPlayer) {
}

void Computer::turn(TicTacToeBoard* board) {
	

	Position2D* position;
	vector<Position2D*> positionList;
	bool** boolBoard;

	double valueObjetive = -99999999;
	double buffer = 0;

	for (int i = 0; i < BOARD_ROW; i++) {
		for (int j = 0; j < BOARD_COLUMN; j++) {
			position = new Position2D(i, j);
			if (board->isPositionUsed(*position) == FREE_POSITION) {
				boolBoard = transformBoardShortToBoolean(board, CROSS);
				if(idPlayer == CROSS) boolBoard[i][j] = true; 
				checkLines(boolBoard, CROSS);
				boolBoard = transformBoardShortToBoolean(board, CIRCLE);
				if (idPlayer == CIRCLE) boolBoard[i][j] = true;
				checkLines(boolBoard, CIRCLE);
				
				buffer = calculateObjetiveFunction();
				if (buffer > valueObjetive) {
					positionList.clear();
					valueObjetive = buffer;
					position = new Position2D(i, j);
					positionList.push_back(position);
				}
				else if (buffer == valueObjetive) {
					position = new Position2D(i, j);
					positionList.push_back(position);
				}
			}
		}
	}
	srand(time(NULL));
	int random = rand() % positionList.size();
	board->setValue(*positionList.at(random), idPlayer);

	delete position;
}

void Computer::checkLines(bool** boolBoard, short playerId) {
	int line[8] = { 0,0,0,0,0,0,0,0 }; //f1,f2,f3,c1,c2,c3,d1,d2;
	//Position2D* position;

	line[0] = boolBoard[0][0] + boolBoard[0][1] + boolBoard[0][2];
	line[1] = boolBoard[1][0] + boolBoard[1][1] + boolBoard[1][2];
	line[2] = boolBoard[2][0] + boolBoard[2][1] + boolBoard[2][2];

	line[3] = boolBoard[0][0] + boolBoard[0][0] + boolBoard[0][0];
	line[4] = boolBoard[1][1] + boolBoard[1][1] + boolBoard[1][1];
	line[5] = boolBoard[2][2] + boolBoard[2][2] + boolBoard[2][2];
	
	line[6] = boolBoard[0][0] + boolBoard[1][1] + boolBoard[2][2];
	line[7] = boolBoard[2][0] + boolBoard[1][1] + boolBoard[0][2];

	int weight = line[0];
	for (int i = 1; i < 8; i++) {
		if (weight < line[i]) weight = line[i];
	}

	if (this->idPlayer == playerId) {
		varNumberMyValuesInRow = weight;
		varMyValueSummationOfAllLines = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
	} else {
		varNumberOtherValuesInRow = weight;
		varOtherValueSummationOfAllLines = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
	}
}

bool ** Computer::transformBoardShortToBoolean(TicTacToeBoard * board, short idPlayer){
	Position2D* position;
	bool** boolBoard = new bool*[BOARD_ROW];
	for (int i = 0; i < BOARD_ROW; i++) {
		boolBoard[i] = new bool[BOARD_COLUMN];
	}

	for (int i = 0; i < BOARD_ROW; i++) {
		for (int j = 0; j < BOARD_COLUMN; j++) {
			position = new Position2D(i, j);
			if (board->getValue(*position) == idPlayer) boolBoard[i][j] = true;
			else boolBoard[i][j] = false;
		}
	}
	return boolBoard;
}

void Computer::endGame(TicTacToeBoard* board, short idPlayer) {
	int buffer = 0;
	int valueObjetive = -999999;
	bool** boolBoard;

	boolBoard = transformBoardShortToBoolean(board, CROSS);
	checkLines(boolBoard, CROSS);
	boolBoard = transformBoardShortToBoolean(board, CIRCLE);
	checkLines(boolBoard, CIRCLE);

	buffer = calculateObjetiveFunction();
	if (buffer > valueObjetive) {
		valueObjetive = buffer;
	}

	debugInformationAI();
	double c = 0.01;
	double newValueObjetive = 0;
	
	if (this->idPlayer== idPlayer) {
		newValueObjetive = 100 - valueObjetive;	
	}
	else if (idPlayer == 0) {
		newValueObjetive = -valueObjetive;
	} else {
		newValueObjetive = -valueObjetive-100;
	}
	
	weightMyValueSummationOfAllLines = weightMyValueSummationOfAllLines + c*(newValueObjetive)*varMyValueSummationOfAllLines / 16;
	weightNumberMyValuesInRow = weightNumberMyValuesInRow + c*(newValueObjetive)*varNumberMyValuesInRow / 3;
	weightNumberOtherValuesInRow = weightNumberOtherValuesInRow + c*(newValueObjetive)*varNumberOtherValuesInRow / 3;
	weightOtherValueSummationOfAllLines = weightOtherValueSummationOfAllLines + c*(newValueObjetive)*varOtherValueSummationOfAllLines / 16;
	debugInformationAI();
}

int Computer::calculateObjetiveFunction(){
	return varMyValueSummationOfAllLines * weightMyValueSummationOfAllLines
		+ varNumberMyValuesInRow * weightNumberMyValuesInRow
		+ varNumberOtherValuesInRow * weightNumberOtherValuesInRow
		+ varOtherValueSummationOfAllLines * weightOtherValueSummationOfAllLines;
}

void Computer::debugInformationAI() {
	ofstream myFile;
	myFile.open("example.txt", myFile.app);

	myFile << "Player: " << this->idPlayer << endl;
	myFile << "valueObjetive: " << calculateObjetiveFunction() << endl;

	myFile << "varMyValueSummationOfAllLines: " << varMyValueSummationOfAllLines << endl;
	myFile << "varNumberMyValuesInRow: " << varNumberMyValuesInRow << endl;
	myFile << "varNumberOtherValuesInRow: " << varNumberOtherValuesInRow << endl;
	myFile << "varOtherValueSummationOfAllLines: " << varOtherValueSummationOfAllLines << endl;

	myFile << "weightMyValueSummationOfAllLines: " << weightMyValueSummationOfAllLines << endl;
	myFile << "weightNumberMyValuesInRow: " << weightNumberMyValuesInRow << endl;
	myFile << "weightNumberOtherValuesInRow: " << weightNumberOtherValuesInRow << endl;
	myFile << "weightOtherValueSummationOfAllLines: " << weightOtherValueSummationOfAllLines << endl;
	myFile << endl;
	myFile.close();
}
