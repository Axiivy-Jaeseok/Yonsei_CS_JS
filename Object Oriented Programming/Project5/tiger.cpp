#include "tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger() {
	// random position
	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	while (grid[index_x - 1][index_y - 1] == 'O' || grid[index_x - 1][index_y - 1] == '*' || grid[index_x - 1][index_y - 1] == 'H' || grid[index_x - 1][index_y - 1] == 'R')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}

	// set the initial information
	set_x(index_x);
	set_y(index_y);
	check_rabbit = false;
	set_hp(2);
	count_bd = 0;
}

Tiger::Tiger(char pos[10][10])
{
	// random position
	int index_x = rand() % 10 + 1, index_y = rand() % 10 + 1;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) grid[i][j] = pos[i][j];

	// checking that position is available
	while (grid[index_x - 1][index_y - 1] == 'O' || grid[index_x - 1][index_y - 1] == '*' || grid[index_x - 1][index_y - 1] == 'H' || grid[index_x - 1][index_y - 1] == 'R')
	{
		index_x = rand() % 10 + 1;
		index_y = rand() % 10 + 1;
	}

	// set the initial information
	set_x(index_x);
	set_y(index_y);
	check_rabbit = false;
	set_hp(2);
	count_bd = 0;
}

Tiger::Tiger(int i_x, int i_y, char pos[10][10])
{
	// when the constructor for breed
	vector <string> breed_grid;
	int index_x = i_x;
	int index_y = i_y;

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++) grid[i][j] = pos[i][j];

	// check the position is available
	if (1 < index_x)
	{
		if (grid[index_x - 2][index_y - 1] == '-' || grid[index_x - 2][index_y - 1] == 'O')
			breed_grid.push_back("a");
	}
	if (index_x < 10)
	{
		if (grid[index_x][index_y - 1] == '-' || grid[index_x][index_y - 1] == 'O')
			breed_grid.push_back("d");
	}
	if (index_y < 10)
	{
		if (grid[index_x - 1][index_y] == '-' || grid[index_x - 1][index_y] == 'O')
			breed_grid.push_back("s");
	}
	if (1 < index_y)
	{
		if (grid[index_x - 1][index_y - 2] == '-' || grid[index_x - 1][index_y - 2] == 'O')
			breed_grid.push_back("w");
	}
	if (breed_grid.size() > 0)
	{
		int num_ran = rand() % breed_grid.size(); // breed_list의 갯수에서 time을 이용한 random을 사용해 array중 한개를 뽑는다.
		string direction = breed_grid[num_ran];
		if (direction == "w")
			index_y--;
		else if (direction == "s")
			index_y++;
		else if (direction == "a")
			index_x--;
		else if (direction == "d")
			index_x++;
		check_rabbit = false;
		check_breed = true;
		set_hp(2);
		count_bd = 0;
		set_x(index_x);
		set_y(index_y);
	}
	else
		check_breed = false;
}

void Tiger::move()
{
	// move the tiger as the direction
	if (move_grid.size() != 0)
	{
		int index = rand() % move_grid.size();
		string dir = move_grid[index];
		if (dir == "w") set_y(get_y() - 1);
		else if (dir == "s") set_y(get_y() + 1);
		else if (dir == "a") set_x(get_x() - 1);
		else if (dir == "d") set_x(get_x() + 1);
	}
	set_hp(get_hp() - 1);
	count_bd++;
}

void Tiger::check_move()
{
	// check that the position that tiger will go is available

	for (int a = 0; a < move_grid.size(); a++)
		move_grid.erase(move_grid.begin());
	vector<string> move_array;
	if (get_y() > 1)
		if (grid[get_x() - 1][get_y() - 2] == 'R') move_array.push_back("w");
	if (get_y() < 10)
		if (grid[get_x() - 1][get_y()] == 'R') move_array.push_back("s");
	if (get_x() < 10)
		if (grid[get_x()][get_y() - 1] == 'R') move_array.push_back("d");
	if (get_x() > 1)
		if (grid[get_x() - 2][get_y() - 1] == 'R') move_array.push_back("a");
	if (move_array.size() > 0) check_rabbit = true;

	else
	{
		if (1 < get_x())
			if (grid[get_x() - 2][get_y() - 1] == '-' || grid[get_x() - 2][get_y() - 1] == 'O') move_array.push_back("a");

		if (get_x() < 10)
			if (grid[get_x()][get_y() - 1] == '-' || grid[get_x()][get_y() - 1] == 'O') move_array.push_back("d");

		if (get_y() < 10)
			if (grid[get_x() - 1][get_y()] == '-' || grid[get_x() - 1][get_y()] == 'O') move_array.push_back("s");

		if (1 < get_y())
			if (grid[get_x() - 1][get_y() - 2] == '-' || grid[get_x() - 1][get_y() - 2] == 'O') move_array.push_back("w");
	}

	for (unsigned int qw = 0; qw < move_array.size(); qw++)
		move_grid.push_back(move_array[qw]);
}

void Tiger::griding(char grid[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) this->grid[i][j] = grid[i][j];
}

int Tiger::get_cr()
{
	return check_rabbit;
}

void Tiger::set_cr()
{
	check_rabbit = false;
}


int Tiger::get_bd()
{
	return count_bd;
}

void Tiger::set_bd()
{
	count_bd = 0;
}

bool Tiger::get_cb()
{
	return check_breed;
}