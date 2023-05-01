#include "Controler.h"

Field& Controler::GetField(size_t upper)
{
	return this->board.get()->Spaces[upper];
}
	

Field& Controler::GetField(size_t upper,size_t lower)
{
	Field& UpperGrid = this->board.get()->Spaces[upper];

	if (std::holds_alternative<Board>(UpperGrid))
	{
		return std::get<Board>(UpperGrid).Spaces[lower];
	}
	else
		return GetField(upper);
}

bool Controler::move(size_t upper, size_t lower, sign symbol)
{
	if (std::get<sign>(GetField(upper, lower)) == sign::nic) {
		GetField(upper, lower) = symbol;
		return true;
	}
	else
	{
		return false;
	}
}


