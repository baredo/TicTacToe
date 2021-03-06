#include <iostream>
#include <TicTacToeGame.h>
#include <Position2D.h>
#include <Player.h>
#include <Human.h>
#include <Computer.h>
using namespace std;

void main() {
	//Player* player1 = new Human("Fran", 0);
	//Player* player2 = new Human("Juan", 0);
	Player* player1 = new Computer("AI 1", 0);
	Player* player2 = new Computer("AI 2", 0);

	TicTacToeGame* newGame = new TicTacToeGame((Player*)player1, (Player*)player2);
	
	delete newGame;
	delete player1;
	delete player2;
	_CrtDumpMemoryLeaks();
}