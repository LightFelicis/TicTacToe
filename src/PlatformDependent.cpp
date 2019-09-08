#include "PlatformDependent.h"

#include <iostream>
#include <fstream>

namespace PlatformDependent
{

void Clear()
{
	system("clear");
}

void DisplayMessage(const std::string &Message)
{
	std::cout << Message;
}

void DrawBoard(const std::vector<std::vector<char>> &Grid)
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

void Sound1()
{
	// Beep(10000, 300);
}


void Sound2()
{
	// Beep(500, 500);
}

bool ShowResult(bool IsWon)
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
	return Answer == 'X';
}

void ShowRules()
{
	std::cout << "Rules of tic-tac-toe\n";
	std::cout << "Tic-tac-toe is a game for two players (in this game your opponent is a Robot, very intelligent AI)\n";
	std::cout << "Players take turns respectively, marking the spaces in 3x3 grid with their signs - 'x' for the Robot and 'o' for You.\n";
	std::cout << "If the player manages to place three respective marks (in any direction, i.e. in a horizontal, vertical, or diagonal row), he wins the game.\n";
	std::cout << "If there is a tie -- Robot wins.\n";
}

void ShowStats(const int WonGamesCount, const int PlayedGamesCount)
{
	std::cout << "--------------------------------------------------------------------------------------------\n";
	std::cout << "      Number of Robot's wins : " << PlayedGamesCount-WonGamesCount << " Number of your wins : " << WonGamesCount << " \n";
	std::cout << "--------------------------------------------------------------------------------------------\n";
}


void Exit()
{
	Clear();
	exit(0);
}

std::vector<int> ReadFile()
{
	std::ifstream File("Stats.txt");
	std::vector <int> Stats;
	int SingleInfo;
	while (File >> SingleInfo) {
		Stats.push_back(SingleInfo);
	}
	return Stats;
}

void WriteFile(const std::vector<int>& Stats)
{
	std::ofstream File("Stats.txt");
	for (auto SingleInfo : Stats) {
		File << SingleInfo << " ";
	}
}

} // namespace PlatformDependent






