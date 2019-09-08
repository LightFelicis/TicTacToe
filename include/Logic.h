#pragma once
#include "GameView.h"
#include "Board.h"
/*
Class Logic begins, manages and end one instance of a play.
*/
class Logic
{
public:
	/*
	Method Start initiates the play. Creates new Board and GameView objects.
	From a file the method imports informations about previous games' statistics:
		- Number of games won by player.
		- Number of all games played.
	In a loop alternately executes methods RobotsMove and PlayersMove,
	unless the game is done.
	The point of ending the game is determined by result returned
	by Board::IsDone method.
	In the end informs the player about the game's result,
	the sound is played, different for lose and win.
	The statistics are updated and saved in the file.
	*/
	void Start();
	Logic();
	~Logic();
private:
	int WonGamesCount;
	int PlayedGamesCount;
	/*
	Method RobotsMove simulates player's opponent move.
	It finds any not filled yet square and marks it with 'x'--the opponent's mark
	*/
	void RobotsMove(char Mark);
	/*
	Method PlayersMove gets from player the information about his chosen square
	and marks it with 'o' - the player's mark.
	*/
	void PlayersMove(char Mark);
	Board GameBoard;
	GameView CurrentGameView;
};

