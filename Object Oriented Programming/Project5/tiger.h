#pragma once
#ifndef tiger_h
#define tiger_h

#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include "critter.h"

using namespace std;

// It's almost similar with the rabbit
class Tiger : public Critter{
public:
	Tiger(); // default constructor
	Tiger(char pos[10][10]); // constructor
	Tiger(int i_x, int i_y, char pos[10][10]);
	void move(); // move tiger
	void check_move(); // check that moving is available
	void griding(char grid[10][10]); //griding
	int get_cr(); // get the check rabbit
	void set_cr(); // set the check rabbit
	int get_bd(); // get the num of breed
	void set_bd(); // set the num of breed as 0
	bool get_cb(); // get the check breed

private:
	char grid[10][10];
	int count_bd;
	bool check_breed, check_rabbit;
	vector<string> move_grid;
};

#endif
