#pragma once
#include <memory>
#include <stdexcept>

#include "Board.h"

using PBoard = std::shared_ptr<Board>;


class Controler
{	public:

	Controler() :board(new Board){};

	Controler(PBoard _board) :board(_board) {};

	Field& GetField(size_t);

	Field&  GetField(size_t, size_t);

	bool move(size_t, size_t,sign);


	PBoard board;
};

