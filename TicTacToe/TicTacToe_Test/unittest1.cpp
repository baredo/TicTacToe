#include "stdafx.h"
#include "CppUnitTest.h"
#include <TicTacToeGame.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToe_Test
{
	TEST_CLASS(TicTacToe_Test)
	{
	public:
		TicTacToeGame* game = new TicTacToeGame();
		TEST_METHOD(IntroduceElementWhitSpace)
		{
			//Arrange
			int expected = 0;

			//Act
			int actual = game->playTurn(1, 1);

			//Assert
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(IntroduceElementWhitOutSpace)
		{
			//Arrange
			int expected = 1;

			//Act
			game->playTurn(1, 1);
			int actual = game->playTurn(1, 1);

			//Assert
			Assert::AreEqual(expected, actual);
		}
	};
}