#include <string>
#include "hunter.h"

using namespace std;

Hunter::Hunter()
{
	// random position
	int index_x = rand() % 10+1, index_y = rand() % 10+1;
	set_x(index_x);
	set_y(index_y);
	set_hp(5);
	score = 0;
}

void Hunter::move(string dir)
{
	// moving as the direction

	if (dir == "w") {
		if (check_move("w")) set_y(get_y() - 1);
	}
	else if (dir == "s")
	{
		if (check_move("s")) set_y(get_y() + 1);
	}
	else if (dir == "a")
	{
		if (check_move("a")) set_x(get_x() - 1);
	}
	else if (dir == "d")
	{
		if (check_move("d")) set_x(get_x() + 1);
	}
	else if (dir == "wa")
	{
		if (check_move("wa"))
		{
			set_y(get_y() - 1); set_x(get_x() - 1);
		}
	}
	else if (dir == "wd")
	{
		if (check_move("wd"))
		{
			set_y(get_y() - 1); set_x(get_x() + 1);
		}
	}
	else if (dir == "sa")
	{
		if (check_move("sa"))
		{
			set_y(get_y() + 1); set_x(get_x() - 1);
		}
	}
	else if (dir == "sd")
	{
		if (check_move("sd"))
		{
			set_y(get_y() + 1); set_x(get_x() + 1);
		}
	}

	set_hp(get_hp() - 1);
}

bool Hunter::check_move(string dir)
{
	// check the moving is available
	bool flag = true;

	if (dir == "w")
	{
		if (get_y() == 1)
			flag = false;
	}
	else if (dir == "s")
	{
		if (get_y() == 10)
			flag = false;
	}
	else if (dir == "a")
	{
		if (get_x() == 1)
			flag = false;
	}
	else if (dir == "d")
	{
		if (get_x() == 10)
			flag = false;
	}
	else if (dir == "wa")
	{
		if (get_x() == 1 || get_x() == 1)
			flag = false;
	}
	else if (dir == "wd")
	{
		if (get_x() == 10 || get_y() == 1)
			flag = false;
	}
	else if (dir == "sa")
	{
		if (get_x() == 1 || get_y() == 10)
			flag = false;
	}
	else if (dir == "sd")
	{
		if (get_x() == 10 || get_y() == 10)
			flag = false;
	}
	return flag;
}

void Hunter::use_po()
{
	// hp is going to 5 and potion get -1
	set_hp(5);
	po_num--;
}

void Hunter::set_po(int num)
{
	po_num = num;
}

int Hunter::get_po()
{
	return po_num;
}

int Hunter::get_score()
{
	return score;
}

void Hunter::set_score(int num)
{
	// update the score
	score = score + num;
}

void Hunter::update_hp(string type)
{
	// when kill rabbit
	if (type == "rabbit") {
		if (get_hp() < 4) set_hp(get_hp() + 2);
		else set_hp(5);
	}
	// when kill tiger
	if (type == "tiger") set_hp(5);
}
