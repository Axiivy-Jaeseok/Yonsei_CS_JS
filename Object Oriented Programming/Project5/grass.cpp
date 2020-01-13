#include "grass.h"

Grass::Grass()
{
	// random cor
	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	while (grid[index_x - 1][index_y - 1] == 'O' || grid[index_x - 1][index_y - 1] == '*' || grid[index_x - 1][index_y - 1] == 'R')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}
	x = index_x;
	y = index_y;
}


Grass::Grass(char pos[10][10])
{
	// random cor
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) grid[i][j] = pos[i][j];

	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	while (grid[index_x - 1][index_y - 1] == 'O' || grid[index_x - 1][index_y - 1] == '*' || grid[index_x - 1][index_y - 1] == 'R')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}
	
	// set the position
	x = index_x;
	y = index_y;
}

void Grass::griding(char grid[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) this->grid[i][j] = grid[i][j];
}

int Grass::get_x()
{
	return x;
}

int Grass::get_y()
{
	return y;
}