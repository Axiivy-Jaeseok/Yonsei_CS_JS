#pragma once
#ifndef hunter_h
#define hunter_h

#include <string>
#include <cmath>
#include <cstdlib>
#include "critter.h"

using namespace std;

class Hunter : public Critter {
public:
	Hunter(); // default constructor
	void move(string direction); // constructor
	void use_po(); // using potion
	void set_po(int num); // set the poition num
	int get_po(); // get the num of potion
	int get_score(); // get the score
	void set_score(int num); // set the score
	void update_hp(string type); // update the hp when hunter kill rabbit or tiger
	bool check_move(string dir); // check the moving is available

private:
	int score, po_num;
};

#endif
