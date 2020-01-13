#include "critter.h"

using namespace std;

// default constructor
Critter::Critter() {
	x = 0, y = 0, HP = 0;
}

// return x cor
int Critter::get_x() {
	return x;
}

// return y cor
int Critter::get_y() {
	return y;
}

// return hp
int Critter::get_hp() {
	return HP;
}

// set the hp as input
void Critter::set_hp(int hp)
{
	HP = hp;
}

// set the x cor
void Critter::set_x(int x) {
	this->x = x;
}

// set the y cor
void Critter::set_y(int y) {
	this->y = y;
}