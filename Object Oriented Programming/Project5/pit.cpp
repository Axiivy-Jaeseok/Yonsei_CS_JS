#include "pit.h"

Pit::Pit()
{
	// random cor
	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	while (grid[index_x - 1][index_y - 1] == 'H')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}
	x = index_x;
	y = index_y;
}

Pit::Pit(char pos[10][10])
{
	// random cor
	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) grid[i][j] = pos[i][j];

	while (grid[index_x - 1][index_y - 1] == 'H' || grid[index_x - 1][index_y - 1] == '*')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}
	// set the initial position
	x = index_x;
	y = index_y;
}

int Pit::get_x()
{
	return x;
}

int Pit::get_y()
{
	return y;
}