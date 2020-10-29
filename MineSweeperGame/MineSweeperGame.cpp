
#include "MineSweeperGame.h"


MineSweeperGame::MineSweeperGame(int xSize, int ySize, int totalBombCount) {
	gameX = xSize;
	gameY = ySize;
	bombCount = totalBombCount;
	gameBoard = new Square*[xSize*ySize];
	safetyBombs = 1;

	for(int i = 0; i < xSize; i++)
		for (int j = 0; j < ySize; j++) {
			gameBoard[i*gameX + j] = new Square();;
		}

	FillGameBoard();
}

MineSweeperGame::~MineSweeperGame() {
	for (int i = 0; i < gameX*gameY; i++) {
		delete gameBoard[i];
	}
	delete[] gameBoard;
}

void MineSweeperGame::FillGameBoard() {
	GenerateBombs();

	for (int x = 0; x < gameX; x++) {
		for (int y = 0; y < gameY; y++) {
			if (gameBoard[x*gameX + y] == nullptr) {
				gameBoard[x*gameX + y] = GenerateSquare(x, y);
			}
			else if (gameBoard[x*gameX + y]->GetTrueValue() == Square::Value::Blank) {
				FillSquareDetails(x, y);
			}
		}
	}

}

void MineSweeperGame::GenerateBombs() {
	srand(time(NULL));
	int x = 0;
	int y = 0;
	for (int i = 0; i < bombCount; i++) {
		do {
			x = rand() % (gameX);
			y = rand() % (gameY);
		} while (gameBoard[x * gameX + y]->GetTrueValue() != Square::Value::Blank);

		printf("bomb at %d,%d\n", x, y);
		gameBoard[x * gameX + y]->SetValue(Square::Value::Bomb);
		gameBoard[x * gameX + y]->SetNeighbours(GenerateNeighbourArray(x, y));
	}
}

void MineSweeperGame::FillSquareDetails(int x, int y) {
	Square **neighbours = GenerateNeighbourArray(x, y);

	int bombCount = 0;

	for (int i = 0; i < Square::NeighbourCount; i++) {
		if (neighbours[i] != nullptr && neighbours[i]->GetTrueValue() == Square::Value::Bomb) {
			bombCount++;
		}
	}

	gameBoard[x * gameX + y]->SetValue((Square::Value) bombCount);
	gameBoard[x * gameX + y]->SetNeighbours(neighbours);
}

Square *MineSweeperGame::GenerateSquare(int x, int y) {
	Square **neighbours = GenerateNeighbourArray(x, y);
	int bombCount = 0;

	for (int i = 0; i < Square::NeighbourCount; i++) {
		if (neighbours[i] != nullptr && neighbours[i]->GetValue() == Square::Value::Bomb) {
			bombCount++;
		}
	}

	return new Square((Square::Value)bombCount, neighbours);
}

Square **MineSweeperGame::GenerateNeighbourArray(int x, int y) {
	Square **neighbours = new Square*[Square::NeighbourCount];

	for (int i = 0; i < Square::NeighbourCount; i++) {
		neighbours[i] = nullptr;
	}

	if (x > 0) {
		neighbours[Square::Neighbours::LeftCenter] = gameBoard[(x - 1)*gameX + y];
	}
	if (x < gameX - 1) {
		neighbours[Square::Neighbours::RightCenter] = gameBoard[(x + 1)*gameX + y];
	}

	if (y > 0) {
		neighbours[Square::Neighbours::TopCenter] = gameBoard[x*gameX + y - 1];

		if (x > 0) {
			neighbours[Square::Neighbours::TopLeft] = gameBoard[(x - 1)*gameX + y - 1];
		}
		if (x < gameX - 1) {
			neighbours[Square::Neighbours::TopRight] = gameBoard[(x + 1)*gameX + y - 1];
		}
	}

	if (y < gameY - 1) {
		neighbours[Square::Neighbours::BottomCenter] = gameBoard[x*gameX + y + 1];

		if (x > 0) {
			neighbours[Square::Neighbours::BottomLeft] = gameBoard[(x - 1)*gameX + y + 1];
		}
		if (x < gameX - 1) {
			neighbours[Square::Neighbours::BottomRight] = gameBoard[(x + 1)*gameX + y + 1];
		}
	}

	return neighbours;
}

void MineSweeperGame::PrintBoard(bool showAll) {
	printf("   ");
	for (int i = 0; i < gameX; i++) {
		printf("%d ", i);
	}
	printf("\n");
	printf("  ");
	for (int i = 0; i < gameX; i++) {
		printf("__", i);
	}
	printf("\n");
	for (int y = 0; y < gameY; y++) {
		printf("%d| ", y);
		for (int x = 0; x < gameX; x++) {
			Square *square = gameBoard[x*gameX + y];
			Square::Value val = square->GetValue();
			if (showAll && square->GetTrueValue() == Square::Value::Bomb) {
				printf("B ");
			}
			else if (showAll || square->IsViewed()) {
				printf("%d ", (int)square->GetTrueValue());
			}
			else if (val == Square::Value::Flagged) {
				printf("F ");
			}
			else {
				printf("X ");
			}
			
		}
		printf("\n");
	}
}

void MineSweeperGame::ChainViewSquares(Square square) {

}

MineSweeperGame::GameState MineSweeperGame::CheckBoardStatus() {
	int bombsHit = 0;
	bool allSquaresViewed = true;

	for (int i = 0; i < gameX*gameY; i++) {
		if (gameBoard[i]->IsViewed() 
			&& gameBoard[i]->GetTrueValue() == Square::Value::Bomb) {
			bombsHit++;
		}
		else if (!gameBoard[i]->IsViewed()) {
			allSquaresViewed = false;
		}
	}

	if (bombsHit > safetyBombs) {
		return GameState::Loss;
	}
	if (allSquaresViewed) {
		return GameState::Victory;
	}
	return GameState::Ongoing;
}

MineSweeperGame::GameState MineSweeperGame::ViewSquare(Square *square) {
	Square::Value val = square->ViewSquare();

	if (val == Square::Value::Blank) {
		Square **neighbours = square->GetNeighbourArray();

		for (int i = 0; i < Square::NeighbourCount; i++) {
			if (neighbours[i] != nullptr && !neighbours[i]->IsViewed() 
				&& neighbours[i]->GetTrueValue() != Square::Value::Bomb) {
				ViewSquare(neighbours[i]);
			}
		}
	}

	return CheckBoardStatus();
}

MineSweeperGame::GameState MineSweeperGame::ViewSquareByCoords(int x, int y) {
	ViewSquare(gameBoard[x*gameX + y]);

	return CheckBoardStatus();
}