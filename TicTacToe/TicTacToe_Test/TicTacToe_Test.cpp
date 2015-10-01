#include "stdafx.h"
#include "CppUnitTest.h"
#include <TicTacToeGame.h>
#include <TicTacToeBoard.h>
#include <Position2D.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToe_Test{
	
	TEST_CLASS(TicTacToeGame_Test){
	public:
		TicTacToeGame* game = new TicTacToeGame();
		TEST_METHOD(IntroduceElementWhitSpace){
			//Arrange
			int expected = 0;

			//Act
			int actual = game->playTurn(*new Position2D(0,0));

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntroduceElementWhitOutSpace){
			//Arrange
			int expected = 1;

			//Act
			game->playTurn(*new Position2D(0, 0));
			int actual = game->playTurn(*new Position2D(0, 0));

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
	
	TEST_CLASS(TicTacToeBoard_Test) {
		public:
		TicTacToeBoard* board = new TicTacToeBoard();
		Position2D* position1 = new Position2D(0, 0);
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