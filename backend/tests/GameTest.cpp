#include<catch2/catch_test_macros.hpp>


#include "Game.h"
#include "AiPlayer.h"

#include <iostream>
#include <vector>
#include <utility>
#include<istream>
#include<sstream>
#include<iostream>

#if 1


TEST_CASE("Controler can modify nested boards", "[Controler]"){
	PBoard sisiak(new Board(3, Board(3, sign::nothing)));
	Controler controler(sisiak);
	controler.move(2, 1, 0, 1, sign::circle);
    controler.move(0, 1, 2, 2, sign::ex);

    PBoard sisiak2(new Board(5, Board(5, sign::nothing)));
	Controler controler2(sisiak);
	controler2.move(3, 2, 4, 1, sign::circle);
    controler2.move(4, 1, 1, 2, sign::ex);
	
    REQUIRE(std::get<sign>(controler.GetField(2, 1, 0, 1)) == sign::circle);
    REQUIRE(std::get<sign>(controler.GetField(0, 1, 2, 2)) == sign::ex);

    REQUIRE(std::get<sign>(controler2.GetField(3, 2, 4, 1)) == sign::circle);
    REQUIRE(std::get<sign>(controler2.GetField(4, 1, 1, 2)) == sign::ex);

}

TEST_CASE("Controler can modify upper boards", "[Controler]" ) {
    
	PBoard sisiak(new Board(3, Board(3, sign::nothing)));
	Controler controler(sisiak);
	controler.move(2, 1, sign::circle);
    controler.move(0, 1, sign::ex);

    PBoard sisiak2(new Board(5, Board(5, sign::nothing)));
	Controler controler2(sisiak);
	controler2.move(3, 2,sign::circle);
    controle2.move(4, 1, sign::ex);
		


    REQUIRE(std::get<sign>(controler.GetField(2, 1)) == sign::circle);
    REQUIRE(std::get<sign>(controler.GetField(0, 1)) == sign::ex);

    REQUIRE(std::get<sign>(controler2.GetField(3, 2)) == sign::circle);
    REQUIRE(std::get<sign>(controler2.GetField(4, 1)) == sign::ex);
}

TEST_CASE("Print Board Test", "[output]") {
    Board board;


    std::stringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());


    board.printBoard();


    std::cout.rdbuf(oldCoutBuffer);

 
    std::string expectedOutput = R"(
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
--------------------------------
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
--------------------------------
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
.  .  .  |  .  .  .  |  .  .  .  
)";


    expectedOutput = expectedOutput.substr(1);



    Board board2(5);
    PBoard sisiak(new Board(board2));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::circle);
	controler.move(0, 0, 1, 1, sign::circle);
	controler.move(0, 0, 2, 2, sign::circle);

	controler.move(0, 2, sign::ex);
    
    std::stringstream output2;
    std::streambuf* oldCoutBuffer2 = std::cout.rdbuf(output2.rdbuf());


    board2.printBoard();


    std::cout.rdbuf(oldCoutBuffer2);

 
    std::string expectedOutput2 = R"(
 O  .  .  .  .  |  .  .  .  .  .  |  X  X  X  X  X  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  O  .  .  .  |  .  .  .  .  .  |  X  X  X  X  X  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  O  .  .  |  .  .  .  .  .  |  X  X  X  X  X  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  X  X  X  X  X  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  X  X  X  X  X  |  .  .  .  .  .  |  .  .  .  .  .  |
----------------------------------------------------------------------------------------------------
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
----------------------------------------------------------------------------------------------------
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
----------------------------------------------------------------------------------------------------
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
----------------------------------------------------------------------------------------------------
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
 .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |  .  .  .  .  .  |
----------------------------------------------------------------------------------------------------
)";


    expectedOutput2 = expectedOutput2.substr(1);



    REQUIRE(output.str() == expectedOutput);
    REQUIRE(output2.str() == expectedOutput2);
}

TEST_CASE("Game can assert wining:", "[Win]" ) {
    
    PBoard sisiak(new Board(5, Board(5, sign::nothing)));
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


    REQUIRE(game.is_won(0, 0).win == true);
    REQUIRE(game.is_won(2, 1).win == true);
}


TEST_CASE("CountMovesToWin test:", "[Ai]" ) {
    
    Board board(3);
	PBoard pboard(new Board(board));
	Controler controler(pboard);
	controler.move(0, 0, sign::ex);
	controler.move(0, 1, sign::ex);
	Game game(pboard);

    REQUIRE(game.countMovesToWin(sign::ex) == 1);

}

TEST_CASE("Game can assert wining on upper Boards:", "[Win]" ) {
    
    PBoard sisiak(new Board(5, Board(5, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);

	controler.move(0, 0, sign::circle);
	controler.move(0, 1, sign::circle);
	controler.move(0, 2, sign::circle);
	controler.move(0, 3, sign::circle);
	controler.move(0, 4, sign::circle);
	controler.move(1, 0, 3, 3, sign::ex);
	controler.move(1, 0, 4, 4, sign::ex);

	REQUIRE(game.is_won().win == true);
}

TEST_CASE("Test finding wining move:", "[Ai]" ) {
    
    Board board(3);
	PBoard pboard(new Board(board));
	Controler controler(pboard);
	controler.move(0, 0, sign::ex);
	controler.move(0, 1, sign::ex);
	Game game(pboard);


	REQUIRE(game.checkWin(sign::ex).first == 0);
    REQUIRE(game.checkWin(sign::ex).second == 2);
}

TEST_CASE("Test Ai for ilegal moves:", "[Ai]" ) {
    
    PBoard sisiak(new Board(3, Board(3, sign::nothing)));
	Controler controler(sisiak);
	Game game(sisiak);
	controler.move(0, 0, 0, 0, sign::ex);
	controler.move(0, 0, 1, 1, sign::ex);
	AiPlayer Ai;

	std::pair<int, int> move = Ai.AiMove(0, 0, game, sign::ex);
	std::pair<int, int> move1 = Ai.AiMove(0, 1, game, sign::circle);


    controler.move(1, 1, sign::circle);
	controler.move(0, 1, sign::circle);

	std::pair<std::pair<int, int>, std::pair<int, int>> move2 = Ai.AiMove(game, sign::circle);

	std::cout << "Ai robi ruch " << move2.first.first << " " << move2.first.second << " " << move2.second.first << " " << move2.second.second << std::endl;

	REQUIRE(move.first == 2);
    REQUIRE(move.second == 2);
    REQUIRE(move1.first > -1);
    REQUIRE(move1.second > -1);

    REQUIRE(move2.first.first != 1 && move2.first.second != 1);
    REQUIRE(move2.first.first != 0 && move2.first.second != 1);
    REQUIRE( move2.first.first > 0 &&  move2.first.second > 0 && move2.second.first > 0 && move2.second.second > 0);

    

}


#endif