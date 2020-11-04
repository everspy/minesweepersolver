// MineSweeperInterpreter.cpp : Defines the entry point for the application.
//

#include "MineSweeperInterpreter.h"
#include "../MineSweeperGame/MineSweeperGame.h"


int main()
{
	
	int gameX, gameY, bombCount;
	// Better input would be nice
	std::cout << "Enter X dimension of game:";
	std::cin >> gameX;
	
	std::cout << "Enter Y dimension of game:";
	std::cin >> gameY;

	std::cout << "Enter number of bombs:";
	std::cin >> bombCount;
	
	MineSweeperGame game (gameX, gameY, bombCount);
	game.PrintBoard();
	
	int x;
	int y;
	while(game.GetCurrentGameState() == MineSweeperGame::GameState::Ongoing){
		x = -1;
		y = -1;		
		while(x < 0 || x >= gameX){
			std::cin >> x;
		}
		while(y < 0 || y >= gameY) {
			std::cin >> y;
		}

		game.ViewSquare(x,y);
		game.PrintBoard();
	}

	if(game.GetCurrentGameState() == MineSweeperGame::GameState::Victory) {
		printf("Victory!");
	}
	else {
		printf("You lose...");
	}
	
	std::cin >> x;
	return 0;
}

int GetCoords(int &x, int& y, int maxX, int maxY) {
	x = -1, y = -1;

	while(x == -1 && y == -1) {
	}
	return 0;
}
