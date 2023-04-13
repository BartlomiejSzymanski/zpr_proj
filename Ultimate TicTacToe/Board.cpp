#include "Board.h"


Board::Board(unsigned int size, bool is_nested)
{
	if (is_nested) {
		Spaces = Grid(pow(size, 2), Board(size,0));
	}
	else {
		Spaces = Grid(pow(size, 2), sign::nic);
	}
}
