// MineSweeperSolver.cpp : Defines the entry point for the application.
//

#include "MineSweeperSolver.h"
#include "../MineSweeperGame/MineSweeperGame.h"


int main()
{
	MineSweeperGame game (10, 10, 1);
	game.PrintBoard();
	int in;
	game.PrintBoard(true);
	game.ViewSquareByCoords(5, 5);
	game.PrintBoard();
	std::cin >> in;
	return 0;
}
