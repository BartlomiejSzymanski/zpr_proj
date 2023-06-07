#include <variant>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#ifndef BOARD_H
#define BOARD_H

class Board;


/*!
 * @enum signs that can be used to fill the board
 */
enum class sign {

	ex,
	circle,
	nothing

};


using Field = std::variant<sign, Board>;
using Row = std::vector<Field>;
using Grid = std::vector<std::vector<Field>>;


/*!
 * @class frame to hold TicTacToe boards with the ability to nest them
 */
class Board {
public:


	/*!
	* Default constructor which creates 3X3 board of TicTacToe
	*/
	Board();

	/*!
	* Default destructor of board
	*/
	~Board() {};

	/*!
	* constructor which creates board of TicTacToe of a given size
	* @param size of the board that will be crated
	* @param "filling" of the board which can be signs or other boards
	*/
	Board(size_t _size, Field field = sign::nothing);

	/*!
	* constructor which creates board of TicTacToe of a given size based
	* on two-dimensional dynamic array of Fields which are other boards or signs
	* @param two-dimensional dynamic array of Fields which are other boards or signs which represents TicTacToe board
	* @param size
	*/
	Board(Grid spaces, const int size) : Size(size), Spaces(spaces) {};


	/*!
	 * @fn Returns the size of the Board
	 * @return size of the Board
	*/
	size_t getSize();

	/*!
	 * @fn Returns two-dimensional dynamic array of Fields which are other boards or signs
	 * @return two-dimensional dynamic array of Fields which are other boards or signs which represents
	 board
	*/
	Grid& getGrid();

	/*!
	 * @fn prints to console state of the board
	*/
	void printBoard() const;

	/*!
	 * @fn creates string representation od the board for eventual comparison of board states
	 * @return string representation od the board
	*/
	std::string getState() const;

private:

	/*!
	* @var size of the board
	* @var two-dimensional dynamic array of Fields which are other boards or signs which represents TicTacToe board
	*/
	size_t Size;
	Grid Spaces;
};

#endif

