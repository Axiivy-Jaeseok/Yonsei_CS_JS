#pragma once
#ifndef rabbit_h
#define rabbit_h

#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "critter.h"

class Rabbit : public Critter {
public:
	Rabbit(); // default constructor
	Rabbit(char pos[10][10]); // constructor
	Rabbit(int i_x, int i_y, char pos[10][10]); // constructor
	void move(); // move rabbit
	void check_move(); // check that moving is available
	void griding(char grid[10][10]); //griding
	int get_cg(); // get the check grass
	void set_cg(); // set the check grass
	int get_bd(); // get the num of breed
	void set_bd(); // set the num of breed
	bool get_cb(); // get the check breed

private:
	char grid[10][10];
	int count_bd;
	bool check_grass, check_breed;
	vector<string> move_grid;
};

#endif

