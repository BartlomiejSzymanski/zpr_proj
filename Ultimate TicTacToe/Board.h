#pragma once
#include <variant>
#include <vector>
#include <math.h>

class Board;

enum class sign {

	iks,
	igrek,
	nic

};


using Field = std::variant<sign, Board>;
using Grid = std::vector<Field>;



class Board{
	public:

		Board() {};
		~Board() {};

		Board(unsigned int size,bool is_nested = 0);

		


		Grid Spaces;
};

