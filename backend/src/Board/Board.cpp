#include "Board.h"


Board::Board() : Size(3)
{
	new Board(Size);
}

Board::Board(size_t _size, Field field) : Size(_size)
{

	Row Row_;

	for (int i = 0; i < _size; ++i) {
		Row_.push_back(field);
	}

	for (int i = 0; i < _size; ++i) {
		this->Spaces.push_back(Row_);
	}
}

size_t Board::getSize()
{
	return this->Size;

}

Grid& Board::getGrid()
{
	return this->Spaces;
}


void Board::printBoard() const {

	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j) {
			for (int k = 0; k < Size; ++k) {
				for (int l = 0; l < Size; ++l) {

					if (std::holds_alternative<Board>(Spaces[i][k])) {

						Board field = std::get<Board>(Spaces[i][k]);

						if (std::get<sign>((field).getGrid()[j][l]) == sign::circle) {
							std::cout << " O ";
						}
						else if (std::get<sign>((field).getGrid()[j][l]) == sign::ex)
						{
							std::cout << " X ";
						}
						else {
							std::cout << " . ";
						}

					}
					else {
						sign sign_ = std::get<sign>(Spaces[i][k]);

						if (sign_ == sign::circle) {
							std::cout << " O ";
						}
						else if (sign_ == sign::ex)
						{
							std::cout << " X ";
						}
						else {
							std::cout << " . ";
						}
					}

				}
				std::cout << " | ";
			}
			std::cout << std::endl;
		}
		for (int k = 0; k < Size * Size; ++k)
		{
			std::cout << "----";
		}
		std::cout << std::endl;
	}

}

std::string Board::getState() const {
	std::string state;

	for (const auto& row : Spaces) {
		for (const auto& cell : row) {
			if (std::holds_alternative<sign>(cell)) {
				const sign& cellSign = std::get<sign>(cell);
				switch (cellSign) {
				case sign::nothing:
					state += '0';
					break;
				case sign::ex:
					state += 'X';
					break;
				case sign::circle:
					state += 'O';
					break;
				}
			}
			else {
				state += 'B'; // Jeœli komórka przechowuje obiekt klasy Board, oznaczamy to jako 'B'
			}
		}
	}

	return state;
}