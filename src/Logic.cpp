#include "Logic.h"
#include <iostream>
#include "Board.h"
#include "GameView.h"
#include "PlatformDependent.h"

void Logic::Start()
{
	std::vector<int>Stats;
	Stats = PlatformDependent::ReadFile();
	if (Stats.size() == 0) {
		Stats = { 0, 0 };
	}
	WonGamesCount = Stats[0];
	PlayedGamesCount = Stats[1];

	GameBoard = Board();
	CurrentGameView = GameView();
	int WhoseMove = PlayedGamesCount % 2;
	while (GameBoard.IsDone() == -1) {

		CurrentGameView.ClearView();
		CurrentGameView.ShowRules();
		CurrentGameView.ShowStats(WonGamesCount, PlayedGamesCount);
		CurrentGameView.ShowBoard(GameBoard.GetGrid());

		if (WhoseMove == 0) {
			PlayersMove('o');
		}
		else {
			RobotsMove('x');
		}
		WhoseMove++;
		WhoseMove %= 2;
	}


	CurrentGameView.ClearView();
	CurrentGameView.ShowRules();
	CurrentGameView.ShowStats(WonGamesCount, PlayedGamesCount);
	CurrentGameView.ShowBoard(GameBoard.GetGrid());

	PlayedGamesCount++;
	Stats[1] = PlayedGamesCount;
	if (GameBoard.IsDone() == 1) {
		PlatformDependent::Sound1();
		WonGamesCount++;
		Stats[0] = WonGamesCount;
		PlatformDependent::WriteFile(Stats);
		CurrentGameView.ShowResult(true);

	}
	else {
		PlatformDependent::Sound2();
		PlatformDependent::WriteFile(Stats);
		CurrentGameView.ShowResult(false);
	}

}

Logic::Logic()
{
}


Logic::~Logic()
{
}

void Logic::RobotsMove(char Mark)
{
	for (int Column = 0; Column < 3; Column++) {
		for (int Row = 0; Row < 3; Row++) {
			if (GameBoard.IsFree({ Column, Row }) == true) {
				GameBoard.AddMove({ Column, Row }, Mark);
				return;
			}
		}
	}

}

void Logic::PlayersMove(char Mark)
{
	std::pair <int, int> Answer = CurrentGameView.MoveQuery();
	GameBoard.AddMove(Answer, Mark);
}
