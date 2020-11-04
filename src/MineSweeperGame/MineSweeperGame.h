// MineSweeperGame.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Square.h"

#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H

class MineSweeperGame
{
private: 
	int gameX;
	int gameY;
	int bombCount;
	int safetyBombs;
	Square **gameBoard;

public:
	enum class GameState {
		Loss, Victory, Ongoing
	};

public: 
	MineSweeperGame(int xSize, int ySize, int bombCount);
	~MineSweeperGame();
private: 
	void FillGameBoard();
	void GenerateBombs();
	void FillSquareDetails(int x, int y);
	Square *GenerateSquare(int x, int y);
	Square **GenerateNeighbourArray(int x, int y);
	void ChainViewSquares(Square square);
	GameState CheckBoardStatus();
public: 
	void PrintBoard(bool showall = false);
	int GetGameX();
	int GetGameY();
	GameState ViewSquare(Square *square);
	GameState ViewSquare(int x, int y);
	GameState GetCurrentGameState();
	Square **GetGameBoard();
};
#endif // !MINESWEEPERGAME_H

