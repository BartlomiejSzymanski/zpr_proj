#include "Board.h"


Board::Board() : Size(3)
{
	// to do 
}

Board::Board(size_t _size, Field field): Size(_size)
{
		Spaces = Grid(pow(Size, 2), field);
}
