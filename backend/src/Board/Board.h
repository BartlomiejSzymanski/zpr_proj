#pragma once
#include <variant>
#include <vector>
#include <math.h>
#include <iostream>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Board;

enum class sign {

	iks,
	igrek,
	nic

};


using Field = std::variant<sign, Board>;
using Row = std::vector<Field>;
using Grid = std::vector<std::vector<Field>>;



class Board {
public:

	Board();
	~Board() {};


	Board(Grid spaces, const int size) : Size(size), Spaces(spaces) {};
	Board(size_t _size, Field field = sign::nic);
	size_t getSize();
	Grid& getGrid();

	void printBoard() const;

private:
	size_t Size;
	Grid Spaces;
};

