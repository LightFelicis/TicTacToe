#include "pch.h"
#include "Board.h"
#include <cassert>
#include <iostream>
Board::Board()
{
	Grid.resize(3, std::vector<char>(3, ' '));
}


Board::~Board()
{
}
bool Board::IsFree(std::pair<int, int> Coords) const
{
	return Grid[Coords.first][Coords.second] == ' ';
}

void Board::AddMove(std::pair<int, int> Coords, char Mark)
{
	assert(IsFree(Coords));
	assert(Mark == 'x' || Mark == 'o');
	Grid[Coords.first][Coords.second] = Mark;
}

const std::vector<std::vector<char>> &Board::GetGrid()
{
	return Grid;
}

int Board::IsDone() const
{	
	for (int Column = 0; Column < 3; Column++) {
		char Mark = Grid[Column][0];
		int OccurenceCounter = 0; 
		for (int Row = 0; Row < 3; Row++) {
			if (Grid[Column][Row] == Mark) {
				OccurenceCounter++;
			}
		}
		if (OccurenceCounter == 3) {
			if (Mark == 'o') {
				return 1;
			}
			else if (Mark == 'x') {
				return 2;
			}
		}
	}
	for (int Row = 0; Row < 3; Row++) {
		char Mark = Grid[0][Row];
		int OccurenceCounter = 0;
		for (int Column = 0; Column < 3; Column++) {
			if (Grid[Column][Row] == Mark) {
				OccurenceCounter++;
			}
		}
		if (OccurenceCounter == 3) {
			if (Mark == 'o') {
				return 1;
			}
			else if (Mark == 'x'){
				return 2;
			}
		}
	}
	{	
		char Mark = Grid[0][0];
		int OccurenceCounter = 0;
		for (int Row = 0; Row < 3; Row++) {
			if (Grid[Row][Row] == Mark) {
				OccurenceCounter++;
			}
		}
		if (OccurenceCounter == 3) {
			if (Mark == 'o') {
				return 1;
			}
			else if (Mark == 'x'){
				return 2;
			}
		}
	}
	{
		char Mark = Grid[2][0];
		int OccurenceCounter = 0;
		for (int Row = 0; Row < 3; Row++) {
			if (Grid[2 - Row][Row] == Mark) {
				OccurenceCounter++;
			}
		}
		if (OccurenceCounter == 3) {
			if (Mark == 'o') {
				return 1;
			}
			else if (Mark == 'x'){
				return 2;
			}
		}
	}
	for (int Column = 0; Column < 3; Column++) {
		for (int Row = 0; Row < 3; Row++) {
			if (IsFree({ Column, Row })) {
				return -1; 
			}
		}
	}
	return 0;
}


