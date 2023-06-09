#include "Game.h"
#include <algorithm>
#include <unordered_map>
#ifndef AIPLAYER_H
#define AIPLAYER_H

/*!
 *  This class is rensponsible for "thought" process of Ai
 */
class AiPlayer
{
public:

	/*!
	 * Function that serches for the best move based game state
	 * @param X index of the board on which the Ai has to find the move
	 * @param Y index of the board on which the Ai has to find the move
	 * @param game that we are playing right now
	 * @param sign of the Ai player
	 * @return Index of the best move
	 */
	std::pair<int, int> AiMove(int X, int Y, Game game, sign sign);

	/*!
	 * Function that serches for the best move based game state when the Ai has compleate freedom of choice
	 * of the board that the move will be placed
	 * @param game that we are playing right now
	 * @param sign of the Ai player
	 * @return Index of the best move
	 */
	std::pair< std::pair<int, int>, std::pair<int, int>> AiMove(Game game, sign sign);

private:


	std::unordered_map<std::string, int> cache;
};

#endif