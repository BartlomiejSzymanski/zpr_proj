
#include <memory>
#include <stdexcept>
#include "Board.h" 

#ifndef CONTROLLER_H
#define CONTROLLER_H

using PBoard = std::shared_ptr<Board>;

/*!
 *  Composite class that allows for control over boardstates
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
	*  allows acces to specified field of the board
	* @param X index of the field
	* @param Y index of the field
	*/
	Field& GetField(size_t X, size_t Y);

	/*!
	*  allows acces to specified field of the nested board
	* @param X index of the field
	* @param Y index of the field
	* @param nested_X index of the field
	* @param nested_Y index of the field
	*/
	Field& GetField(size_t X, size_t Y, size_t nested_X, size_t nested_Y);

	/*!
	* allows to change the specific fields of board
	* @param X index of the field
	* @param Y index of the field
	* @param sign that will be emplaced
	* @return A boolean value that denotes the success of the action
	*/
	bool move(size_t X, size_t Y, sign sign);

	/*!
	* allows to change the specific fields of nested board
	* @param X index of the field
	* @param Y index of the field
	* @param nested_X index of the field
	* @param nested_Y index of the field
	* @param sign that will be emplaced
	* @return A boolean value that denotes the success of the action
	*/
	bool move(size_t X, size_t Y, size_t nested_X , size_t nested_Y, sign sign);


	/*!
	*  gives acces to board which object holds
	* @return shraed ptr to the board
	*/
	PBoard getBoard();

private:

	
	PBoard board;
};

#endif