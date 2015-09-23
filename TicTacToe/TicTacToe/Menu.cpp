//TicTacToe
//T: Playing TicTacToe
//P: Percent of Games won
//E: Games played again itself
//V: Board -> |R

//V'(b) = w0 + w1x1 + w2x2
//w0....2 wights
//x1: number x in a row
//x2: number o in a row

//if win V = 100;
//if lost V = -100;
//if draw V = 0;

#include <iostream>;
using namespace std;

struct Weight {
	int w0 = 10, w1 = 40, w2 = 5, w3 = 40, w4 = 5;
};

struct Variable {
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
};



void checkLines(short* map, Variable* v, short player) {
	int line[8] = { 0,0,0,0,0,0,0,0 }; //f1,f2,f3,c1,c2,c3,d1,d2;

	line[0] = map[0] + map[1] + map[2];
	line[1] = map[3] + map[4] + map[5];
	line[2] = map[6] + map[7] + map[8];
	line[3] = map[0] + map[3] + map[6];
	line[4] = map[1] + map[4] + map[7];
	line[5] = map[2] + map[5] + map[8];
	line[6] = map[0] + map[4] + map[8];
	line[7] = map[2] + map[4] + map[6];

	int weight = line[0];
	for (int i = 1; i < 8; i++) {
		if (weight < line[i]) weight = line[i];
	}

	if (player == 0) {
		v->x1 = weight;
		v->x2 = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
	}
	else {
		v->x3 = weight;
		v->x4 = line[0] + line[1] + line[2] + line[3] + line[4] + line[5] + line[6] + line[7];
	}
}

short* convertMap(short* map, int k) {
	short* bufferMap = new short[9];
	for (int i = 0; i < 9; i++) {
		if (map[i] == k) bufferMap[i] = 1;
		else bufferMap[i] = 0;
	}

	return bufferMap;
}

void showMap(short* map) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (map[3 * i + j] == 0) cout << "?";
			if (map[3 * i + j] == 1) cout << "x";
			if (map[3 * i + j] == 2) cout << "o";
		}
		cout << endl;
	}
}



void initGame() {

}

void playTurn(short* board, Variable* v, Weight* w) {
	int player = 0;




	int end = -1; //-1: playing, 0: win player 0,1: win player 1, 2:draw
	int optimal = 0;
	int pos = 0;
	while (end == -1) {
		optimal = -9999999;
		pos = 0;

		//humano
		if (player == 2) {
			cout << "introduce celda: ";
			cin >> pos;

		}
		else {


			for (int i = 0; i < 9; i++) {
				if (board[i] == 0) {
					//Calculamos el peso de las posiciones
					short* mapBuffer = convertMap(board, 2);
					mapBuffer[i] = 1;
					if (player == 0) checkLines(mapBuffer, &v[i], 0); else checkLines(mapBuffer, &v[i], 1);


					mapBuffer = convertMap(board, 1);
					mapBuffer[i] = 1;
					if (player == 0) checkLines(mapBuffer, &v[i], 1); else checkLines(mapBuffer, &v[i], 0);

					//Calculamos la posicion optima si existe
					int buffer = w->w1*v[i].x1 + w->w2*v[i].x2 + w->w3*v[i].x3 + w->w4*v[i].x4;
					if (optimal < buffer) {
						optimal = buffer;
						pos = i;
					}
				}
			}

		}
		if (player == 0) board[pos] = 1; else 	board[pos] = 2;

		//mostramos el tablero
		showMap(board);

		Variable fEnd;
		//A ganado el jugador?
		if (player == 0) checkLines(convertMap(board, 1), &fEnd, 0); else checkLines(convertMap(board, 1), &fEnd, 1);
		if (player == 0) checkLines(convertMap(board, 2), &fEnd, 1); else checkLines(convertMap(board, 2), &fEnd, 0);
		if (fEnd.x1 == 3) {
			cout << "fin de la partida, ganador: " << player;
			if (player == 0) end = 0; else end = 1;
		}
		else if (board[0] != 0 && board[1] != 0 && board[2] != 0 && board[3] != 0 && board[4] != 0 && board[5] != 0 && board[6] != 0 && board[7] != 0) {
			end = 2;
			cout << "empate";
		}
		else {
			for (int i = 0; i < 9; i++) {
				v[i].x1 = 0;
				v[i].x2 = 0;
				v[i].x3 = 0;
				v[i].x4 = 0;
			}
			if (player == 0)player = 1; else player = 0;
		}

		cin.get();
	}
	int z = v[pos].x1 + v[pos].x2 + v[pos].x3 + v[pos].x4;
	float c = 0.01;
	if (end == 0) {
		w->w1 = w->w1 + c*(100 - optimal)*v[pos].x1;
		w->w2 = w->w2 + c*(100 - optimal)*v[pos].x2;
		w->w3 = w->w3 + c*(100 - optimal)*v[pos].x3;
		w->w4 = w->w4 + c*(100 - optimal)*v[pos].x4;

	}
	else if (end == 1) {
		w->w1 = w->w1 + c*(-100 - optimal)*v[pos].x1;
		w->w2 = w->w2 + c*(-100 - optimal)*v[pos].x2;
		w->w3 = w->w3 + c*(-100 - optimal)*v[pos].x3;
		w->w4 = w->w4 + c*(-100 - optimal)*v[pos].x4;
	}
	else if (end == 2) {
		w->w1 = w->w1 + c*(-optimal)*v[pos].x1;
		w->w2 = w->w2 + c*(-optimal)*v[pos].x2;
		w->w3 = w->w3 + c*(-optimal)*v[pos].x3;
		w->w4 = w->w4 + c*(-optimal)*v[pos].x4;

	}

	for (int i = 0; i < 9; i++) {
		v[i].x1 = 0;
		v[i].x2 = 0;
		v[i].x3 = 0;
		v[i].x4 = 0;
	}
	end = -1;
	//player = 0;
	board[0] = 0; board[1] = 0; board[2] = 0; board[3] = 0; board[4] = 0; board[5] = 0; board[6] = 0; board[7] = 0; board[8] = 0;
}

void finishGame() {
	//cin.get();
}

void practice(int games) {
	Variable v[9];
	Weight* w = new Weight();
	//int player = 0;
	for (int i = 0; i < games; i++) {
		short board[9] = { 0,0,0,0,0,0,0,0,0 };



		initGame();
		playTurn(board, v, w);
		finishGame();
	}
}

void main() {

	/*int play = 1;
	int optimal = 0;
	int pos = 0;*/

	while (1) {
		practice(10);
	}
}