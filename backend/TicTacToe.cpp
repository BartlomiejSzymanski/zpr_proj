#include <iostream>
#include "Game.h"
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
//*
void test_controler(size_t size, size_t x, size_t y, size_t low_x, size_t low_y) {
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	controler.move(x, y, low_x, low_y, sign::igrek);
	try {
		if (std::get<sign>(controler.GetField(x, y, low_x, low_y)) == sign::igrek)
		{
			std::cout << "move i getField działa" << std::endl;
		}
		else
			std::cout << "move i getField nie działa" << std::endl;
	}
	catch (const std::bad_variant_access& e) {
		std::cout << "move i getField nie działa" << std::endl;
	}

}

void test_controler_upper(size_t size, size_t x, size_t y) {
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	controler.move(x, y, sign::igrek);
	try {
		if (std::get<sign>(controler.GetField(x, y)) == sign::igrek)
		{
			std::cout << "move i getField działa na górnej planszy" << std::endl;
		}
		else
			std::cout << "move i getField nie działa na górnej planszy" << std::endl;
	}
	catch (const std::bad_variant_access& e) {
		std::cout << "move i getField nie działa na górnej planszy" << std::endl;
	}

}


void test_print(size_t size) {
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::igrek);
	controler.move(0, 0, 1, 1, sign::igrek);
	controler.move(0, 0, 2, 2, sign::igrek);


	controler.board.get()->printBoard();

}

void test_win(size_t size) {
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::igrek);
	controler.move(0, 0, 1, 1, sign::igrek);
	controler.move(0, 0, 2, 2, sign::igrek);

	controler.move(2, 3, 0, 0, sign::igrek);
	controler.move(2, 3, 0, 1, sign::igrek);
	controler.move(2, 3, 0, 2, sign::igrek);
	controler.move(2, 4, sign::igrek);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			try {
				if (game.is_won(i, j).win == true)
				{
					std::cout << "win działa i grid " << i << " i " << j << " wygrany" << std::endl;


				}
			}
			catch (const std::bad_variant_access& e)
			{
				std::cout << "jakiś blad z variantami" << std::endl;
			}

		}
	}

}

int countMovesToWin(const std::shared_ptr<Board>& board, sign player) {
	// Check win condition for the current player
	// ... implementation of win condition check ...
	Game game(board);
	if (game.is_won().win && game.is_won().sign_ == player) {
		return 0;
	}

	// Check if the board is filled and there is no winner (tie)
	// ... implementation of tie condition check ...

	// Continue recursive search otherwise
	int minMoves = std::numeric_limits<int>::max();

	for (size_t i = 0; i < board->getGrid().size(); ++i) {
		for (size_t j = 0; j < board->getGrid()[i].size(); ++j) {
			if (std::get<sign>(board->getGrid()[i][j]) == sign::nic) {
				// Create a copy of the board and make a move
				std::shared_ptr<Board> newBoard = std::make_shared<Board>(*board);
				newBoard->getGrid()[i][j] = player;

				// Recursive call to the function for the next player
				int moves = countMovesToWin(newBoard, player);

				// Update the minimum number of moves
				if (moves >= 0 && moves < minMoves) {
					minMoves = moves;
				}
			}
		}
	}

	// Add the current player's move to the minimum number of moves
	if (minMoves != std::numeric_limits<int>::max()) {
		return minMoves + 1;
	}
	else {
		return -1; // No possible moves
	}
}

void test_win_upper(size_t size) {
	PBoard sisiak(new Board(size, Board(size, sign::nic)));
	Controler controler(sisiak);
	Game game(sisiak);

	controler.move(0, 0, sign::igrek);
	controler.move(0, 1, sign::igrek);
	controler.move(0, 2, sign::igrek);
	controler.move(2, 4, sign::igrek);


	try {
		if (game.is_won().win == true)
		{
			std::cout << "win działa na górnej planszy " << std::endl;


		}
	}
	catch (const std::bad_variant_access& e)
	{
		std::cout << "jakiś blad z variantami" << std::endl;
	}

}

int main()
{

	test_controler(5, 0, 2, 4, 3);
	test_controler_upper(5, 1, 4);
	test_win(5);
	test_win_upper(5);
	Board board(3);
	PBoard pboard(new Board(board));
	Controler controler(pboard);
	controler.move(0, 0, sign::iks);
	controler.move(0, 1, sign::iks);

	std::cout << "ilość ruchów jednego gracza potrzebnych do wygrania planszy: " << countMovesToWin(pboard, sign::iks) << std::endl;
	test_print(4);




	return 0;
};


