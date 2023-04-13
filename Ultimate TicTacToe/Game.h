#pragma once
#include "Controler.h"


using PBoard = std::shared_ptr<Board>;

class Game
{
public:

	Game() : x(new Board), y(x) {};
	~Game() {};

	bool Turn();
	size_t is_won();

private:

	PBoard x;
	Controler y;

};

