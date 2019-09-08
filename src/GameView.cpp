#include "GameView.h"
#include "PlatformDependent.h"
#include <cassert>
#include <iostream>

GameView::GameView()
{
}


GameView::~GameView()
{
}

void GameView::ClearView()
{
	PlatformDependent::Clear();
}

void GameView::ShowBoard(const std::vector<std::vector<char>> &Grid)
{
	PlatformDependent::DrawBoard(Grid);
}

void GameView::ShowStats(int WonGamesCount, int PlayedGamesCount)
{
	PlatformDependent::ShowStats(WonGamesCount, PlayedGamesCount);
}

void GameView::ShowResult(bool IsWon)
{
	if (PlatformDependent::ShowResult(IsWon)) {
		PlatformDependent::Exit();
	}
}

void GameView::ShowRules()
{
	PlatformDependent::ShowRules();
}

std::pair<int, int> GameView::MoveQuery()
{
	std::string Instructions = "Choose a square you want to fill.\n"
							   "You cannot choose a square from outside the board!\n"
							   "It is also forbidden to choose already filled square.\n"
							   "Choose a column - coordinate x (number in range 1 - 3)\n";
	PlatformDependent::DisplayMessage(Instructions);
	int Column;
	std::cin >> Column;
	PlatformDependent::DisplayMessage("Choose a row - coordinate y (number in range 1-3)\n");
	int Row;
	std::cin >> Row;
	assert(Column >= 1 && Column <= 3 && Row >= 1 && Row <= 3);
	return { 3 - Row, Column-1 };
}

