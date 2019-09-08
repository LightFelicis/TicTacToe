#include "pch.h"
#include "GameView.h"
#include <iostream>
#include <cassert>
#include "PlatformDependent.h"
GameView::GameView()
{
}


GameView::~GameView()
{
}

void GameView::ShowBoard(const std::vector<std::vector<char>> &Grid)
{
	std::cout << "_____________\n\n";
	for (auto Row : Grid) {
		std::cout << "| ";
		for (auto Mark : Row) {
			std::cout << Mark << " | ";
		}
		std::cout << "\n_____________\n\n";
	}
}

void GameView::ShowStats(int WonGamesCount, int PlayedGamesCount)
{
	std::cout << "--------------------------------------------------------------------------------------------\n";
	std::cout << "      Number of Robot's wins : " << PlayedGamesCount-WonGamesCount << " Number of your wins : " << WonGamesCount << " \n";
	std::cout << "--------------------------------------------------------------------------------------------\n";

}

void GameView::ShowResult(bool IsWon)
{
	if (IsWon) {
		std::cout << "CONGRATULATIONS, YOU WON!\n";
	}
	else {
		std::cout << "SORRY, NOT THIS TIME :(\n";
	}
	std::cout << "If you want to quit this game, type X on your keyboard. Otherwise, type any other letter to continue and start next game\n";
	char Answer;
	std::cin >> Answer;
	if (Answer == 'X') {
		PlatformDependent Dep;
		Dep.MyExit();
	}
}

void GameView::ShowRules()
{
	std::cout << "Rules of tic-tac-toe\n";
	std::cout << "Tic-tac-toe is a game for two players (in this game your opponent is a Robot, very intelligent AI)\n";
	std::cout << "Players take turns respectively, marking the spaces in 3x3 grid with their signs - 'x' for the Robot and 'o' for You.\n";
	std::cout << "If the player manages to place three respective marks (in any direction, i.e. in a horizontal, vertical, or diagonal row), he wins the game.\n";
	std::cout << "If there is a tie -- Robot wins.\n"; 
}

std::pair<int, int> GameView::MoveQuery()
{
	std::cout << "Choose a square you want to fill.\n";
	std::cout << "You cannot choose a square from outside the board!\n";
	std::cout << "It is also forbidden to choose already filled square.\n"; 
	std::cout << "Choose a column - coordinate x (number in range 1 - 3)\n";
	int Column;
	std::cin >> Column;
	std::cout << "Choose a row - coordinate y (number in range 1-3)\n";
	int Row;
	std::cin >> Row;
	assert(Column >= 1 && Column <= 3 && Row >= 1 && Row <= 3);
	return { 3 - Row, Column-1 };
}

