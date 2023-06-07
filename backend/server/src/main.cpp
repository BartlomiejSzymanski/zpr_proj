#include <iostream>
#include "Game.h"
#include <vector>
#include "AiPlayer.h"
#include <utility>


void setup(Game& game, int& tryb, size_t size, int zadanyTryb) {

	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	game = Game(sisiak);

	tryb = zadanyTryb;
}

int main()
{

	int tryb;
	Game game;
	setup(game, tryb, 4, 1);

	return 0;
};


