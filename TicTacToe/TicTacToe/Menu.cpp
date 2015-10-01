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

#include <iostream>
#include <TicTacToeGame.h>
#include <Position2D.h>
using namespace std;

void main() {

	TicTacToeGame* newGame = new TicTacToeGame();
	//Position2D position(0, 0);
	newGame->playTurn(*new Position2D(0,0));
	newGame->playTurn(*new Position2D(0,0));
}