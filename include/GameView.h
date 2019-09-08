#pragma once
#include <vector>

/*
Class GameView
Manages communication with a player.
Manages visualisation of current game state:
	-statistics about previous games,
	-current board state,
	-rules of tic-tac-toe.
Gets information about chosen square to mark from player.
*/


class GameView
{
public:
	GameView();
	~GameView();
	/*
	Method ClearView removes all visualisations of current state.
	*/
	void ClearView();
	/*
	Method ShowBoard generates a picture of 9 squares filled with marks:
	'o', 'x', ' ',
	every mark is a state in tic-tac-toe. Marks are separated with '|' and '_'.
	As an argument it gets vector of characters, meaning the mark in every square.
	  ___   ___   ___

	| ' ' | ' ' | ' ' |
      ___   ___   ___

	| ' ' | ' ' | ' ' |
	  ___   ___   ___

	| ' ' | ' ' | ' ' |
	  ___   ___   ___
	*/
	void ShowBoard(const std::vector<std::vector<char>> &Grid);
	/*
	Method ShowStats displays information about number of won and lost games.
	*/
	void ShowStats(int WonGamesCount, int PlayedGamesCount);
	/*
	Method ShowResult displays information whether player has won, or lost.
	After that method generates query,
	asking the player if he wants to play next game.
	In case of rejection the offer, the program stops.
	In case of acceptance, the function ends.
	*/
	void ShowResult(bool IsWon);
	/*
	Method ShowRules displays player rules of the tic-tac-toe.
	*/
	void ShowRules();
	/*
	Method MoveQuery generates a query to player,
	asking for coordinates of square pola, on which he wants to place his mark.
	Returns a pair of coordinates.
	In case of non-valid coordinates
	(for example from outside the board) the program stops.
	*/
	std::pair <int, int> MoveQuery();
};

