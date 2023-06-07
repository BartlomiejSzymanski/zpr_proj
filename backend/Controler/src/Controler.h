#pragma once
#include <memory>
#include <stdexcept>

#include "Board.h"

using PBoard = std::shared_ptr<Board>;

/*!
 * @class Composite class that allows for control over boardstates
 */
class Controler
{
public:

	/*!
	*  defoult constructor which creates control over brand new Board
	*/
	Controler() :board(new Board) {};

	/*!
	*  constructor which creates control over given Board
	*/
	Controler(PBoard _board) :board(_board) {};

	/*!
	* @fn allows acces to specified field of the board
	* @param X index of the field
	* @param Y index of the field
	*/
	Field& GetField(size_t, size_t);

	/*!
	* @fn allows acces to specified field of the nested board
	* @param X index of the field
	* @param Y index of the field
	* @param nested X index of the field
	* @param nested Y index of the field
	*/
	Field& GetField(size_t, size_t, size_t, size_t);

	/*!
	* @fn allows to change the specific fields of board
	* @param X index of the field
	* @param Y index of the field
	* @param sign that will be emplaced
	* @return A boolean value that denotes the success of the action
	*/
	bool move(size_t, size_t, sign);

	/*!
	* @fn allows to change the specific fields of nested board
	* @param X index of the field
	* @param Y index of the field
	* @param nested X index of the field
	* @param nested Y index of the field
	* @param sign that will be emplaced
	* @return A boolean value that denotes the success of the action
	*/
	bool move(size_t, size_t, size_t, size_t, sign);


	/*!
	* @fn gives acces to board which object holds
	* @return shraed ptr to the board
	*/
	PBoard getBoard();

private:

	/*!
	* @var shraed ptr to the board
	*/
	PBoard board;
};

