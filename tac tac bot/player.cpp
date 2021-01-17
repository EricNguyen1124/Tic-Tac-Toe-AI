#include "player.h"
#include <iostream>
using namespace std;

player::player()
{
	playerNum = 0;
}

player::player(int num)
{
	playerNum = num;
}

bool player::fill_grid(int pos, grid& darray)
{
	if (darray.fill_value(playerNum, pos))
	{
		cout << "Player: " << playerNum << " filled in an "; 
		if (playerNum == 1) 
			cout << "X";
		else
			cout << "O";
		
		cout << " into position " << pos << endl;

		return true;
	}
	else
	{
		cout << "Invalid position!" << endl;
		return false;
	}
}

int player::getPlayerNum()
{
	return playerNum;
}

void player::setPlayerNum(int num)
{
	playerNum = num;
}