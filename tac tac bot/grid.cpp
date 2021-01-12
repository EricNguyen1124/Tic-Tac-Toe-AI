#include "grid.h"
#include <iostream>
using namespace std;

grid::grid()
{
	for (int i = 0; i < 9; i++)
		values[i] = 0;
}

grid::grid(int val[])
{
	for (int i = 0; i < 9; i++)
		values[i] = val[i];
}

void grid::print()
{
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 != 0)
			cout << "|";

		if (values[i] == 1)
			cout << " X ";
		else if (values[i] == 2)
			cout << " O ";
		else
			cout << "   ";

		if ((i + 1) % 3 == 0 && i < 7)
		{
			cout << endl;
			cout << " __________" << endl;
			cout << endl;
		}
	}
	cout << endl << endl;
}

int grid::check()
{
	bool noDraw = false;

	int temp[3] = { check_hor(), check_ver(), check_dia()};
	for (int i = 0; i < 3; i++)
		if (temp[i] != -2)
			return temp[i];

	for (int i = 0; i < 9; i++)
	{
		if (values[i] == 0)
		{
			noDraw = true;
		}
	}

	if (!noDraw)
		return 0;

	return -2;
}

int grid::check_hor()
{
	bool same = false;
	bool horNoMatch;
	int first;
	int winner = -2;

	for (int i = 0; i < 3; i++)
	{
		horNoMatch = false;
		first = values[i * 3];
		if (first == 0)
			continue;
		for (int j = 0; j < 3; j++)
		{	
			if (first != values[(i * 3) + j])
				horNoMatch = true;
		}

		if (horNoMatch == false)
		{
			same = true;
			winner = first;
		}
			
	}
	return winner;
}

int grid::check_ver()
{
	bool same = false;
	bool verNoMatch;
	int first;
	int winner = -2;

	for (int i = 0; i < 3; i++)
	{
		verNoMatch = false;
		first = values[i];
		if (first == 0)
			continue;
		for (int j = 0; j < 3; j++)
		{
			if (first != values[i + (j * 3)])
				verNoMatch = true;
		}

		if (verNoMatch == false)
		{
			same = true;
			winner = first;
		}
			
	}
	return winner;
}

int grid::check_dia()
{
	bool same = false;
	int first;
	int winner = -2;

	first = values[0];
	if (first != 0)
	{
		if (first == values[4] && first == values[8])
		{
			same = true;
			winner = first;
		}
	}
	
	first = values[2];
	if (first != 0)
	{
		if (first == values[4] && first == values[6])
		{
			same = true;
			winner = first;
		}
			
	}
	return winner;
}

bool grid::fill_value(int player, int pos)
{
	if (values[pos] == 0)
	{
		values[pos] = player;
		return true;
	}
	return false;
}

int* grid::getArray()
{
	return values;
}

void grid::copy_array(int arr[])
{
	for (int i = 0; i < 9; i++)
		values[i] = arr[i];
}