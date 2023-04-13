#pragma once
#include <memory>
#include <stdexcept>

#include "Board.h"

using PBoard = std::shared_ptr<Board>;


class Controler
{	public:

	Controler() :board(new Board(3,1)){};

	Controler(PBoard _board) :board(_board) {};

	Field& Get(size_t);

	Field&  Get(size_t, size_t);

	bool move(size_t, size_t,sign);


	PBoard board;
};

