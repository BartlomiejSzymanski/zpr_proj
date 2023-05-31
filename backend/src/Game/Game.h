#pragma once
#include "Controler.h"


using PBoard = std::shared_ptr<Board>;

class Game
{
public:

	Game() : X(new Board), Y(X), Turn(0){};
	~Game() {};

	void turn();
	size_t is_won();

private:

	bool Turn;
	PBoard X;
	Controler Y;

};

