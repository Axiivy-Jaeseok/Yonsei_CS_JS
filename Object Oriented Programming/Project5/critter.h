#pragma once
#ifndef critter_h
#define critter_h

using namespace std;

class Critter {
public:
	Critter(); // constructor
	int get_x(); // return x cordinate
	void set_x(int x); // set x cor
	int get_y(); // return y cordinate
	void set_y(int y); // set y cor
	int get_hp(); // return the hp
	void set_hp(int hp); // set the hp
private:
	int x, y;
	int HP;
};

#endif
