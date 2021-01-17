#include "bot.h"
#include <iostream>
#include <algorithm>
using namespace std;

bot::bot()
{
	playerNum = 0;
}

bot::bot(int num)
{
	playerNum = num;
}


int bot::minimax(grid darray, bool maximizing)
{
	int temp = darray.check();
	if (temp == 1)
	{
		return 1;
	}
	else if (temp == 2)
	{
		return -1;
	}
	else if (temp == 0)
	{
		return 0;
	}

	if (maximizing)
	{
		int value = -99;

		for (int i = 0; i < 9; i++)
		{
			if (darray.getArray()[i] == 0)
			{
				darray.fill_value(1, i);
				value = max(value, minimax(darray, false));
				darray.getArray()[i] = 0;
			}
		}

		return value;
	}
	else
	{
		int value = 99;

		for (int i = 0; i < 9; i++)
		{
			if (darray.getArray()[i] == 0)
			{
				darray.fill_value(2, i);
				value = min(value, minimax(darray, true));
				darray.getArray()[i] = 0;
			}
		}

		return value;
	}
}

int bot::findMoveX(grid darray)
{
	int value = -99;
	int maxValue = -99;
	int bestMove = 0;
	for (int i = 0; i < 9; i++)
	{
		if (darray.getArray()[i] == 0)
		{
			darray.fill_value(1, i);
			int value = minimax(darray, false);
			darray.getArray()[i] = 0;

			if (value > maxValue)
			{
				bestMove = i;
				maxValue = value;
			}
		}
	}

	return bestMove;
}

int bot::findMoveO(grid darray)
{
	int value = 99;
	int minValue = 99;
	int bestMove = 0;
	for (int i = 0; i < 9; i++)
	{
		if (darray.getArray()[i] == 0)
		{
			darray.fill_value(2, i);
			int value = minimax(darray, true);
			darray.getArray()[i] = 0;

			if (value < minValue)
			{
				bestMove = i;
				minValue = value;
			}
		}
	}

	return bestMove;
}