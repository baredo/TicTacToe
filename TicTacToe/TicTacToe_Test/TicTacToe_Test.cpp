#include "stdafx.h"
#include "CppUnitTest.h"
#include <TicTacToeGame.h>
#include <TicTacToeBoard.h>
#include <Position2D.h>
#include <Human.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToe_Test{
	/* DE MOMENTO NO SE PUEDE IMPLEMENTAR(SOLO CON IA, SIN INTERFAZ)
	TEST_CLASS(TicTacToeGame_Test){
	public:
		Player* player1 = new Human("name1", 0);
		Player* player2 = new Human("name2", 0);
		TicTacToeGame* game = new TicTacToeGame(player1, player2);
		TEST_METHOD(IntroduceElementWhitSpace){
			//Arrange
			int expected = 0;

			//Act
			int actual = game->playTurn();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntroduceElementWhitOutSpace){
			//Arrange
			int expected = 1;

			//Act
			game->playTurn();
			int actual = game->playTurn();

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
	*/
	TEST_CLASS(TicTacToeBoard_Test) {
		public:
		TicTacToeBoard* board = new TicTacToeBoard();
		Position2D* position1 = new Position2D(0, 0);
		Position2D* position2 = new Position2D(1, 0);
		Position2D* position3 = new Position2D(2, 0);
		Position2D* position4 = new Position2D(1, 1);
		Position2D* position5 = new Position2D(2, 2);

		TEST_METHOD(PutCircleInBoard) {
			// Arrange
			int excpectedValue = CIRCLE;

			//Act
			board->setValue(*position1, CIRCLE);
			int actualValue = board->getValue(*position1);

			//Assert
			Assert::AreEqual(excpectedValue, actualValue);
		}

		TEST_METHOD(PutCrossInBoard) {
			// Arrange
			int excpectedValue = CROSS;

			//Act
			board->setValue(*position1, CROSS);
			int actualValue = board->getValue(*position1);

			//Assert
			Assert::AreEqual(excpectedValue, actualValue);
		}

		TEST_METHOD(NoErrorWhenSetOneValue) {
			// Arrange
			int excpectedError = FREE_POSITION;

			//Act
			int actualError = 0;
			actualError = board->setValue(*position1, CROSS);

			//Assert
			Assert::AreEqual(excpectedError, actualError);
		}

		TEST_METHOD(ErrorWhenSetTwoValuesInSamePosition) {
			// Arrange
			int excpectedError = USED_POSITION;

			//Act
			int actualError = 0;
			board->setValue(*position1, CROSS);
			actualError = board->setValue(*position1, CROSS);

			//Assert
			Assert::AreEqual(excpectedError, actualError);
		}

		TEST_METHOD(ClearBoard) {
			//Arrange
			int expected = 0;
			board->setValue(*position1, CROSS);

			//Act
			board->cleanBoard();
			int actual = board->getValue(*position1);

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ThreeInRow_Test1) {
			//Arrange
			int expected = CROSS;
			board->setValue(*position1, CROSS);
			board->setValue(*position2, CROSS);
			board->setValue(*position3, CROSS);

			//Act
			int actual = board->whoHaveThreeInRow();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ThreeInRow_Test2) {
			//Arrange
			int expected = CIRCLE;
			board->setValue(*position1, CIRCLE);
			board->setValue(*position4, CIRCLE);
			board->setValue(*position5, CIRCLE);

			//Act
			int actual = board->whoHaveThreeInRow();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ThreeInRow_Test3) {
			//Arrange
			int expected = 0;
			board->setValue(*position1, CIRCLE);
			board->setValue(*position2, CIRCLE);
			board->setValue(*position5, CIRCLE);

			//Act
			int actual = board->whoHaveThreeInRow();

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(ThreeInRow_Test4) {
			//Arrange
			int expected = 0;
			board->setValue(*position1, CROSS);
			board->setValue(*position2, CIRCLE);
			board->setValue(*position3, CIRCLE);

			//Act
			int actual = board->whoHaveThreeInRow();

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(Position2D_Test) {
	public:
		TEST_METHOD(CorrectConstructorParameters) {
			// Arrange
			int expectedRow = 2;
			int expectedColumn = 3;

			//Act
			Position2D* position = new Position2D(2, 3);
			int rowActual = position->row;
			int columnActual = position->column;

			//Assert
			Assert::AreEqual(expectedRow, rowActual);
			Assert::AreEqual(expectedColumn, columnActual);
		}
	};

}