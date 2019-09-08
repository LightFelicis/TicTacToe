#pragma once
#include <vector>
#include <string>
/*
Class PlatormDependent manages operations, which are platform dependent:
playing sound, clearing console, reading/writing files
and stopping the program.
*/

namespace PlatformDependent
{
	/*
		Clear clears all generated visualisations.
	*/
	void Clear();
	/*
		DisplayMessage generates visualisation of given message.
	*/
	void DisplayMessage(const std::string &Message);
	/*
		DrawBoard method creates visualisation of a game board.
	*/
	void DrawBoard(const std::vector<std::vector<char>> &Grid);
	/*
		Sound1 plays a win sound.
	*/
	void Sound1();
	/*
		Sound2 plays a lose sound.
	*/
	void Sound2();
	/*
		ShowResult method generates visualisation of a result statement.
	*/
	bool ShowResult(bool IsWon);
	/*
		ShowRules method generates visualisation of rules list.
	*/
	void ShowRules();
	/*
		ShowStats method generates visualisation of player's statistics.
	*/
	void ShowStats(const int WonGamesCount, const int PlayedGamesCount);
	void Exit();
	/*
		ReadFile opens file containing statistics,
		and returns a vector with numbers from file.
		1th number is number of player's wins,
		2nd number is number of played games.
	*/
	std::vector <int> ReadFile();
	/*
		WriteFile gets a vector with numbers as argument,
		saves them into the same file as ReadFile.
	*/
	void WriteFile(const std::vector<int> &Stats);
} // PlatformDependent
