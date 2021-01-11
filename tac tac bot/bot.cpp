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
	int blanks[9] = { 0,0,0,0,0,0,0,0,0 };
	int blanksNum = 0;
	grid* scores;
	
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
			blanks[i] = 1;
			blanksNum++;
		}
	}

	scores = new grid[blanksNum];

	if (maximizing)
	{
		for (int i = 0; i < 9; i++)
		{
			if (darray.getArray()[i] == 0)
			{

			}
		}
	}

	return -2;
}

int bot::findMax(int arr[])
{
	int max = -99;
	int maxInd;
	for (int i = 0; i < 9; i++)
		if (max < arr[i])
		{
			max = arr[i];
			maxInd = i;
		}

	return maxInd;
}

int bot::findMin(int arr[])
{
	int min = 99;
	int minInd;
	for (int i = 0; i < 9; i++)
		if (min > arr[i])
		{
			min = arr[i];
			minInd = i;
		}

	return minInd;
}