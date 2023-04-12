#pragma once
#include <variant>
#include <vector>

class Board;
 
using Grid = std::vector<std::variant<char, Board>>;

class Board{
	public:
		Board() {Spaces = Grid(9 ,'.'); };

		Board(unsigned int nesting) { Spaces = (nesting > 0) ? Board(nesting - 1).Spaces : Board().Spaces; };



		Grid Spaces;
};

