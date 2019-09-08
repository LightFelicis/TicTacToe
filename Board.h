#pragma once
#include <vector>
/*
Class Board keeps all the information about current state of game's board.
It provides a method to read all information about a grid representing board --
including states of squares, result of game and a method to
change a state of single square.
*/
class Board
{
public:
	Board();
	~Board();
	/*
	Method AddMove changes the state of one square on board,
	adding a mark in this square - circle or cross.
		As arguments it gets pair of coordinates and type of mark(single character)
		- 'o' - circle
		- 'x' - cross
		Coordinates are indices in Grid, labeled 0-2.
		In case of forbidden action --
			-trying to access already filled square
			-adding different mark other than 'x' / 'o'
		program crashes.
	*/
	void AddMove(std::pair <int, int> Coords, char Mark);
	/*
	Method GetGrid returns description of current state of board,
	represented by a vector of 3 vectors of size 3 filled with characters:
		- 'o' - circle
		- 'x' - cross
		- ' ' - blank square (this square is not filled yet)
	*/
	const std::vector<std::vector<char> > &GetGrid();
	/*
	Method IsDone returns
		- 1, if the player wins game.
		- 2, if the player loses game.
		- -1 if the game has not ended yet
			(there are still blank squares and there is no winner).
		- 0 if there is a tie(All squares are filled and there is no winner).
	*/
	int IsDone() const;
	/*
	Method IsFree gets as argument a pair of coordinates,
	returns true if this square in grid has character ' ' in it.
	*/
	bool IsFree(std::pair <int, int> Coords) const;
private:
	std::vector <std::vector <char> > Grid;
};

