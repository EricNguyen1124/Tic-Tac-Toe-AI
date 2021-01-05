#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"

class player
{
protected:
	int playerNum;
public:
	player(int num);
	bool fill_grid(int pos, grid& darray);
	int getPlayerNum();
};


#endif