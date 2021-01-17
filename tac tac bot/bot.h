#ifndef BOT_H
#define BOT_H

#include "player.h"

class bot : public player
{
public:
	bot();
	bot(int num);
	int minimax(grid darray, bool maximizing); // Minimax algorithm
	int findMoveX(grid darray); // Calls minimax algorithm on all empty positions on grid. Returns best move for X.
	int findMoveO(grid darray); // Same as findMoveX. Returns best move for O.
};
#endif