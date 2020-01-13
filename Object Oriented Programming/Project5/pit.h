#pragma once
#ifndef pit_h
#define pit_h

#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class Pit
{
public:
	Pit(); // default constructor
	Pit(char pos[10][10]); // constructor
	int get_x(); // get x cor
	int get_y(); // get y cor
private:
	int x, y;
	char grid[10][10];
};

#endif