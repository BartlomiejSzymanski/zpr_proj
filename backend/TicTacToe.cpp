#include <iostream>
#include "Game.h"
#include <vector>
#include "AiPlayer.h"
#include <utility>

void test_controler(size_t size, size_t x, size_t y, size_t low_x, size_t low_y) {
	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	Controler controler(sisiak);
	controler.move(x, y, low_x, low_y, sign::circle);
	try {
		if (std::get<sign>(controler.GetField(x, y, low_x, low_y)) == sign::circle)
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
	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	Controler controler(sisiak);
	controler.move(x, y, sign::circle);
	try {
		if (std::get<sign>(controler.GetField(x, y)) == sign::circle)
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
	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::circle);
	controler.move(0, 0, 1, 1, sign::circle);
	controler.move(0, 0, 2, 2, sign::circle);

	controler.move(0, 2, sign::ex);


	controler.getBoard().get()->printBoard();

}

void test_win(size_t size) {
	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::circle);
	controler.move(0, 0, 1, 1, sign::circle);
	controler.move(0, 0, 2, 2, sign::circle);
	controler.move(0, 0, 3, 3, sign::circle);
	controler.move(0, 0, 4, 4, sign::circle);

	controler.move(2, 1, 0, 0, sign::circle);
	controler.move(2, 1, 0, 1, sign::circle);
	controler.move(2, 1, 0, 2, sign::circle);
	controler.move(2, 1, 0, 3, sign::circle);
	controler.move(2, 1, 0, 4, sign::circle);
	controler.move(2, 2, sign::circle);

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

void test_win_upper(size_t size) {
	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);

	controler.move(0, 0, sign::circle);
	controler.move(0, 1, sign::circle);
	controler.move(0, 2, sign::circle);
	controler.move(0, 3, sign::circle);
	controler.move(0, 4, sign::circle);


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

void test_countMovesToWin() {
	Board board(3);
	PBoard pboard(new Board(board));
	Controler controler(pboard);
	controler.move(0, 0, sign::ex);
	controler.move(0, 1, sign::ex);
	Game game(pboard);
	std::cout << "ilość ruchów jednego gracza potrzebnych do wygrania planszy: " << game.countMovesToWin(sign::ex) << std::endl;

}

void test_checkWin() {
	Board board(3);
	PBoard pboard(new Board(board));
	Controler controler(pboard);
	controler.move(0, 0, sign::ex);
	controler.move(0, 1, sign::ex);
	Game game(pboard);

	std::cout << "wygrywający ruch: " << game.checkWin(sign::ex).first << "  " << game.checkWin(sign::ex).second << std::endl;
}

void test_AI()
{
	PBoard sisiak(new Board(3, Board(3, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::ex);
	controler.move(0, 0, 1, 1, sign::ex);


	controler.getBoard().get()->printBoard();
	AiPlayer Ai;
	std::pair<int, int> move = Ai.AiMove(0, 0, game, sign::ex);
	std::cout << "Ai robi ruch 0 0 " << move.first << " " << move.second << std::endl;

	move = Ai.AiMove(0, 1, game, sign::circle);
	std::cout << "Ai robi ruch 0 1 " << move.first << " " << move.second << std::endl;

	std::pair<std::pair<int, int>, std::pair<int, int>> move2 = Ai.AiMove(game, sign::circle);
	std::cout << "Ai robi ruch " << move2.first.first << " " << move2.first.second << " " << move2.second.first << " " << move2.second.second << std::endl;



	controler.move(1, 1, sign::circle);
	controler.move(0, 1, sign::circle);
	controler.getBoard().get()->printBoard();
	move2 = Ai.AiMove(game, sign::circle);
	std::cout << "Ai robi ruch " << move2.first.first << " " << move2.first.second << " " << move2.second.first << " " << move2.second.second << std::endl;

}

void setup(Game& game, int& tryb, size_t size, int zadanyTryb) {

	PBoard sisiak(new Board(size, Board(size, sign::nothing)));
	game = Game(sisiak);

	tryb = zadanyTryb;
}


int main()
{

	test_controler(5, 0, 2, 4, 3);
	test_controler_upper(5, 1, 4);
	test_win(5);
	test_win_upper(5);
	test_countMovesToWin();
	test_checkWin();
	test_print(5);
	test_AI();

	// stopień pokrycia cpp 

	int tryb;
	Game game;
	setup(game, tryb, 4, 1);

	return 0;
};


