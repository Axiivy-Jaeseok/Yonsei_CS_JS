#pragma once
#ifndef grass_h
#define grass_h

#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class Grass
{
public:
	Grass(); //default constructor
	Grass(char pos[10][10]); //constructor
	void griding(char grid[10][10]); //griding
	int get_x(); //get the x cor
	int get_y(); // get the y cor
private:
	int x, y;
	char grid[10][10];
};

#endif