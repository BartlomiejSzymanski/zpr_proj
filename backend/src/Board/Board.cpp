#include "Board.h"


Board::Board() : Size(3)
{
	// to do 
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

						if (std::get<sign>((field).getGrid()[j][l]) == sign::igrek) {
							std::cout << " O ";
						}
						else if (std::get<sign>((field).getGrid()[j][l]) == sign::iks)
						{
							std::cout << " X ";
						}
						else {
							std::cout << "   ";
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