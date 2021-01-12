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
	int blanksNum = 0;
	int numPossibles = 0;
	grid* possibles;
	int* scores;

	if (temp == 1)
		return 1;
	else if (temp == 2)
		return -1;
	else if (temp == 0)
		return 0;

	for (int i = 0; i < 9; i++)
	{
		if (darray.getArray()[i] == 0)
		{
			blanksNum++;
		}
	}

	possibles = new grid[blanksNum];
	scores = new int[blanksNum];
	
	if (maximizing)
	{
		for (int i = 0; i < 9; i++)
		{
			if (darray.getArray()[i] == 0)
			{
				darray.fill_value(1, i);
				possibles[numPossibles].copy_array(darray.getArray());
				darray.getArray()[i] = 0;
				numPossibles++;
			}
		}
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			if (darray.getArray()[i] == 0)
			{
				darray.fill_value(2, i);
				possibles[numPossibles].copy_array(darray.getArray());
				darray.getArray()[i] = 0;
				numPossibles++;
			}
		}
	}

	if (maximizing)
	{
		for (int i = 0; i < blanksNum; i++)
		{
			scores[i] = minimax(possibles[i], false);
		}
		return scores[findMax(scores, blanksNum)];
	}
	else
	{
		for (int i = 0; i < blanksNum; i++)
		{
			scores[i] = minimax(possibles[i], true);
		}
		return scores[findMin(scores, blanksNum)];
	}
}

int bot::findMax(int arr[], int num)
{
	int max = -99;
	int maxInd;
	for (int i = 0; i < num; i++)
		if (max < arr[i])
		{
			max = arr[i];
			maxInd = i;
		}

	return maxInd;
}

int bot::findMin(int arr[], int num)
{
	int min = 99;
	int minInd;
	for (int i = 0; i < num; i++)
		if (min > arr[i])
		{
			min = arr[i];
			minInd = i;
		}

	return minInd;
}