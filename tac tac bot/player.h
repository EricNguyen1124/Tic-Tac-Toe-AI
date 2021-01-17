#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"

class player
{
protected:
	int playerNum; // playerNum is 1 when X, 2 when O.
public:
	player();
	player(int num);
	bool fill_grid(int pos, grid& darray); // Attempts to fill in values array in grid darray. Returns true if successful and false otherwise. Prints out message.
	int getPlayerNum(); // Returns playerNum
	void setPlayerNum(int num); // Sets playerNum
};


#endif