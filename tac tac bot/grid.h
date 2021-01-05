#ifndef GRID_H
#define GRID_H

class grid
{
private:
	int values[9]; //Array of nine integers, 0 is blank, 1 is X, 2 is O
public:
	grid();
	grid(int val[]);
	void print();
	bool check(); //Calls on check_hor, check_ver, check_dia to see if grid has any 3 in a row
	bool check_hor(); //Checks all rows for 3 matching values
	bool check_ver(); //Checks all columns for 3 matching values
	bool check_dia(); //Checks all diagonals for 3 matching values
	bool fill_value(int player, int pos); //Fills in a square
};

#endif // !GRID_H
