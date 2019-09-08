// Alicja Kluczek
#pragma execution_character_set( "utf-8" )

#include "pch.h"
#include <iostream>
#include "GameView.h"
#include "Board.h"
#include "Logic.h"
#include <Windows.h>


int main()
{
	while (true) {
		Logic GAME = Logic();
		GAME.Start();
	}
}
