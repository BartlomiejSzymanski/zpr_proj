#include "Controler.h"
#include <iostream>

Field& Controler::GetField(size_t upper_x, size_t upper_y)
{
	return this->board.get()->getGrid()[upper_x][upper_y];
}




Field& Controler::GetField(size_t upper_x, size_t upper_y, size_t lower_x, size_t lower_y)
{
	Field& UpperGrid = this->board.get()->getGrid()[upper_x][upper_y];

	if (std::holds_alternative<Board>(UpperGrid))
	{
		return std::get<Board>(UpperGrid).getGrid()[lower_x][lower_y];
	}
	else
		return this->GetField(upper_x, upper_y);
}

bool Controler::move(size_t upper_x, size_t upper_y, sign symbol)
{

	if ((std::holds_alternative<sign>(this->GetField(upper_x, upper_y)) ? std::get<sign>(this->GetField(upper_x, upper_y)) == sign::nothing : false) || std::holds_alternative<Board>(this->GetField(upper_x, upper_y))) {
		this->GetField(upper_x, upper_y) = symbol;
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool Controler::move(size_t upper_x, size_t upper_y, size_t lower_x, size_t lower_y, sign symbol)
{
	try {
		if (std::get<sign>(this->GetField(upper_x, upper_y, lower_x, lower_y)) == sign::nothing || typeid(this->GetField(upper_x, upper_y)) == typeid(Board)) {
			this->GetField(upper_x, upper_y, lower_x, lower_y) = symbol;
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (const std::bad_variant_access& e) {
		std::cout << "controler exepction" << std::endl;
	}

}

PBoard Controler::getBoard()
{
	return board;
}




