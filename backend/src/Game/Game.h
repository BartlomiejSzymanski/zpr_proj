#pragma once
#include "Controler.h"


using PBoard = std::shared_ptr<Board>;

struct win
{
	sign	sign_;
	bool    win;
};

class Game
{
public:

	Game() : X(new Board), Y(X), Turn(0) {};
	~Game() {};
	Game(PBoard _board) : X(_board), Y(X), Turn(0) {};

	void turn();
	win is_won();
	win is_won(const int, const int);

private:

	bool Turn;
	PBoard X;
	Controler Y;

};

