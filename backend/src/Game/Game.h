#include "Controler.h"
#include <utility> 
#include <unordered_map>

#ifndef GAME_H
#define GAME_H

using PBoard = std::shared_ptr<Board>;

struct win
{
	sign	sign_;
	bool    win;
};


/*!
 * @class Composite class which perpouse is to hold gamestate, change it and assert winers of the game
 */
class Game
{
public:

	/*!
	* Default constructor which creates the Game witch holds 3X3 game of Ultimate TicTacToe
	*/

	Game() : board(new Board), controler(board), Turn(0) {};

	/*!
	* Default Desstructor
	*/

	~Game() {};

	/*!
	* Constructor which creates the Game witch holds board given as a parameter
	* @param shared ptr to some board
	*/

	Game(PBoard _board) : board(_board), controler(board), Turn(0) {};

	/*!
	* Constructor which creates the Game witch holds board of a given size
	* @param size of the game that we want to create
	*/

	Game(size_t size) : board(new Board(size)), controler(board), Turn(0) {};



	/*!
	 *@fn Function that checks if the board is won
	 * @return Struct which holds boolean value (if board is won true else false) and sign of the player that won that board (if non of the players won sign = nothing)
	 */

	win is_won();



	/*!
	 *@fn Function that checks if the board of given index is won
	 * @param X index of the board
	 * @param Y index of the board
	 * @return Struct which holds boolean value (if board is won true else false) and sign of the player that won that board (if non of the players won sign = n
	 */

	win is_won(const int, const int);


	/*!
	 *@fn Function that searches for move that wins board of specific index
	 * @param X index of the board
	 * @param Y index of the board
	 * @param sign of the player that serches for wining move
	 * @return Pair of intigers which represent index of wining move
	 */

	std::pair<int, int> checkWin(const int, const int, sign);


	/*!
	 *@fn Function that searches for move that wins board of specific index
	 * @param sign of the player that serches for wining move
	 * @return Pair of intigers which represent index of wining move
	 */

	std::pair<int, int> checkWin(sign);

	/*!
	 *@fn Function that counts how many more moves player needs to win given board
	 * @param X index of the board
	 * @param Y index of the board
	 * @param sign of the player that serches for wining move
	 * @return number of moves needed to win bord
	 */

	int countMovesToWin(const int x_, const int y_, sign player);

	/*!
	 *@fn Function that counts how many more moves player needs to win board
	 * @param sign of the player that serches for wining move
	 * @return number of moves needed to win bord
	 */

	int countMovesToWin(sign player);


	/*!
	 *@fn Function that counts how many more moves player needs to win board with cashe which prevents counting the same state twice
	 * @param sign of the player that serches for wining move
	 * @param states of which we know how many moves are needed to win
	 * @return number of moves needed to win bord
	 */

	int countMovesToWin(sign player, std::unordered_map<std::string, int>& cache);

	/*!
	 *@fn Returns the size of the game
	 * @return size of the game
	 */

	size_t getSize();

	/*!
	 *@fn Returns reference to two-dimensional dynamic array of Fields which are other boards or signs which represents TicTacToe board
	 * @return size of the game
	 */

	Grid& getGrid();

	/*!
	 *@fn Returns the Board on which game is taking place on
	 * @return size of the game
	 */

	Board* getBoard();

	/*!
	 *@fn Returns the controler to the game
	 * @return controler to the game
	 */

	Controler getControler();




private:

	/*!
	 * @var boolean value which represents even and od turns of the game
	 * @var Board of TicTacToe
	 * @var implements control methods to the game
	 */
	bool Turn;
	PBoard board;
	Controler controler;

};

#endif