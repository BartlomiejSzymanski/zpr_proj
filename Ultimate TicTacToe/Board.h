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

		Board();
		~Board() {};

		Board(size_t _size,Field field = sign::nic);

		

		const int Size;
		Grid Spaces;
};

