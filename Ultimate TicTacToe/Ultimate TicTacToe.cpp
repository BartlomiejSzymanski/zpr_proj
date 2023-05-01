#include <iostream>
#include "Game.h"

void test_controler(int size,int x, int y){
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	controler.move(x, y, sign::igrek);
	try {
		if (std::get<sign>(controler.GetField(x, y)) == sign::igrek)
		{
			std::cout << "move i getField działa";
		}
		else
			std::cout << "move i getField nie działa";
	}
	catch (std::bad_variant_access e) {
		std::cout << "move i getField nie działa";
	}
}

int main()
{
	test_controler(5,2,1);
	
	return 0;
};

