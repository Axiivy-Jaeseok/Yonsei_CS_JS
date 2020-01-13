#include "critter.h"
#include "rabbit.h"
#include "hunter.h"
#include "grass.h"
#include "time.h"
#include "pit.h"
#include "tiger.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int get_num(string spec); // function declaration
int main()
{
	// declaration of variables
	int num_ra, num_ti, num_gr, num_pit, num_po, total, bd_ra, bd_ti, kill_ra, kill_ti, pit_ra, pit_ti, star_ra, star_ti, temp_ra, temp_ti;
	string dir_hun, str_ra, str_ti, str_gr, str_pit, str_po;
	char drink_po;
	char screen[10][10];
	bool hunter_flag = true;
	int runtime = 0;

	int count = 0;

	srand(time(0));
	Hunter hunter;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) screen[i][j] = '-';

	while (true)
	{
		// get the num of characters
		num_ra = get_num("rabbit");
		num_ti = get_num("tiger");
		num_gr = get_num("grasse");
		num_pit = get_num("pit");
		num_po = get_num("potion");
		cout << endl;

		total = num_ra + num_ti + num_gr + num_pit;

		// when the characters num is smaller than 100
		if (total < 100) break;
	}

	if (runtime == 0)
	{
		// initial setting
		bd_ra = num_ra; bd_ti = num_ti;
		kill_ra = 0; kill_ti = 0;
		pit_ra = 0; pit_ti = 0;
		star_ra = 0; star_ti = 0;
	}

	hunter.set_po(num_po);
	screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';

	// make a information of pit
	Pit* pit = new Pit[num_pit];

	for (int m = 0; m < num_pit; m++)
	{
		Pit obj_pit(screen);
		screen[obj_pit.get_x() - 1][obj_pit.get_y() - 1] = 'O'; \
			pit[m] = obj_pit;
	}

	// set the grass
	Grass * grass = new Grass[num_gr];
	int ** grass_position;
	grass_position = new int *[num_gr];
	for (int k = 0; k < num_gr; k++) grass_position[k] = new int[2];

	for (int l = 0; l < num_gr; l++)
	{
		Grass obj_gr(screen);
		screen[obj_gr.get_x() - 1][obj_gr.get_y() - 1] = '*';
		grass_position[l][0] = obj_gr.get_x();
		grass_position[l][1] = obj_gr.get_y();
		obj_gr.griding(screen);
		grass[l] = obj_gr;
	}

	// make a information of rabbit
	vector <Rabbit> rabbit;
	for (int r = 0; r < num_ra; r++) {
		Rabbit obj_ra(screen);
		screen[obj_ra.get_x() - 1][obj_ra.get_y() - 1] = 'R';
		obj_ra.griding(screen);
		rabbit.push_back(obj_ra);
	}

	// make a information of tiger
	vector <Tiger> tiger;
	for (int pp = 0; pp < num_ti; pp++) {
		Tiger obj_ti(screen);
		screen[obj_ti.get_x() - 1][obj_ti.get_y() - 1] = 'T';
		obj_ti.griding(screen);
		tiger.push_back(obj_ti);
	}

	// game start
	while (hunter_flag)
	{
		for (int t = 0; t < 10; t++)
			for (int w = 0; w < 10; w++) screen[t][w] = '-';


		screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';

		for (int p = 0; p < num_pit; p++)
			screen[pit[p].get_x() - 1][pit[p].get_y() - 1] = 'O';

		for (int q = 0; q < num_gr; q++)
			screen[grass[q].get_x() - 1][grass[q].get_y() - 1] = '*';

		for (int e = 0; e < num_gr; e++)
			grass[e].griding(screen);

		screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';

		for (int n = 0; n < num_ra; n++)
			screen[rabbit[n].get_x() - 1][rabbit[n].get_y() - 1] = 'R';

		for (int o = 0; o < num_ti; o++)
			screen[tiger[o].get_x() - 1][tiger[o].get_y() - 1] = 'T';

		for (int h = 0; h < num_ra; h++)
			rabbit[h].griding(screen);

		for (int v = 0; v < num_ti; v++)
			tiger[v].griding(screen);

		// show the information 
		cout << "Time step: " << runtime << endl;
		cout << "<Score:" << hunter.get_score() << ", HP:" << hunter.get_hp() << ", Potions:" << hunter.get_po() << ">" << endl << endl;

		// show the grid of game
		for (int mn = 0; mn < 10; mn++)
		{
			for (int mk = 0; mk < 10; mk++) cout << screen[mk][mn] << " ";
			cout << endl;
		}

		// get the information when 1 turns finished
		cout << endl;
		cout << "number of rabbits:               " << num_ra << "      <born:" << bd_ra << ", starve:" << star_ra << ", captured:" << kill_ra << ", fall:" << pit_ra << ">" << endl;
		cout << "number of tigers:                " << num_ti << "      <born:" << bd_ti << ", starve:" << star_ti << ", captured:" << kill_ti << ", fall:" << pit_ti << ">" << endl;
		cout << "number of grasses:               " << num_gr << endl;
		cout << "number of pits:                  " << num_pit << endl << endl;

		bd_ra = 0; bd_ti = 0;
		kill_ra = 0; kill_ti = 0;
		pit_ra = 0;	pit_ti = 0;
		star_ra = 0; star_ti = 0;

		// get the moving information
		while (true)
		{
			cout << "Input the moving direction( Up: 'w', Down: 's', Left: 'a', Right: 'd'): ";
			cin >> dir_hun;
			if (dir_hun == "w" || dir_hun == "s" || dir_hun == "a" || dir_hun == "d" || dir_hun == "wa" || dir_hun == "wd" || dir_hun == "sa" || dir_hun == "sd") break;
		}

		// check potion eating
		while (true)
		{
			cout << "Are you going to use potion( Yes: 'y', No: 'n') : ";
			cin >> drink_po;
			if (drink_po == 'y' || drink_po == 'n') break;
		}

		hunter.move(dir_hun);
		if (drink_po == 'y' && hunter.get_po() > 0)
			hunter.use_po();

		// when hunter kill rabbit
		if (screen[hunter.get_x() - 1][hunter.get_y() - 1] == 'R')
		{
			int rabbit_index;
			hunter.set_score(1);
			hunter.update_hp("rabbit");

			for (int ad = 0; ad < num_ra; ad++)
			{
				if (rabbit[ad].get_x() == hunter.get_x() && rabbit[ad].get_y() == hunter.get_y())
					rabbit_index = ad;
			}
			rabbit.erase(rabbit.begin() + rabbit_index);
			num_ra--;
			kill_ra++;
		}

		// when hunter kill tiger
		if (screen[hunter.get_x() - 1][hunter.get_y() - 1] == 'T')
		{
			int tiger_index;
			hunter.set_score(2);
			hunter.update_hp("tiger");
			for (int af = 0; af < num_ti; af++)
			{
				if (tiger[af].get_x() == hunter.get_x() && tiger[af].get_y() == hunter.get_y())
					tiger_index = af;
			}
			tiger.erase(tiger.begin() + tiger_index);
			num_ti--;
			kill_ti++;
		}

		// when hunter in pit
		for (int ah = 0; ah < num_pit; ah++)
		{
			if (pit[ah].get_x() == hunter.get_x() && pit[ah].get_y() == hunter.get_y())
				hunter.set_hp(0);
		}

		// when hunter die
		if (hunter.get_hp() == 0)
		{
			cout << "Your final score is " << hunter.get_score() << endl;
			cout << "End of the program" << endl;
			break;
		}

		temp_ra = num_ra;

		for (int sv = 0; sv < temp_ra; sv++)
		{
			rabbit[sv].check_move();
			rabbit[sv].move();
			for (int ck = 0; ck < 10; ck++)
			{
				for (int bk = 0; bk < 10; bk++)
					screen[ck][bk] = '-';
			}

			screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';
			for (int ef = 0; ef < num_gr; ef++)
				screen[grass[ef].get_x() - 1][grass[ef].get_y() - 1] = '*';

			screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';

			// add the pit
			for (int we = 0; we < num_pit; we++)
				screen[pit[we].get_x() - 1][pit[we].get_y() - 1] = 'O';

			for (int ds = 0; ds < sv; ds++)
				screen[rabbit[ds].get_x() - 1][rabbit[ds].get_y() - 1] = 'R';
			for (int kd = 0; kd < num_ra; kd++)
				rabbit[kd].griding(screen);
			for (int kk = 0; kk < num_ti; kk++)
				screen[tiger[kk].get_x() - 1][tiger[kk].get_y() - 1] = 'T';
			for (int ke = 0; ke < num_ti; ke++)
				tiger[ke].griding(screen);

			int grass_index;

			// when rabbit eat grass
			if (rabbit[sv].get_cg() == 1)
			{
				for (int da = 0; da < num_gr; da++)
				{
					if (grass_position[da][0] == rabbit[sv].get_x() && grass_position[da][1] == rabbit[sv].get_y())
					{
						grass_index = da;
						break;
					}
				}
				Grass temp_gr(screen);
				grass_position[grass_index][0] = temp_gr.get_x();
				grass_position[grass_index][1] = temp_gr.get_y();
				temp_gr.griding(screen);
				grass[grass_index] = temp_gr;
				rabbit[sv].set_cg();
				rabbit[sv].set_hp(3);
			}
			if (num_ra > 0)
			{
				if (rabbit[sv].get_hp() == 0)
				{
					rabbit.erase(rabbit.begin() + sv);
					num_ra--;
					temp_ra--;
					star_ra++;
					sv--;
					continue;
				}
				if (num_ra > 0)
				{
					if (screen[rabbit[sv].get_x() - 1][rabbit[sv].get_y() - 1] == 'O')
					{
						rabbit.erase(rabbit.begin() + sv);
						pit_ra++;
						num_ra--;
						temp_ra--;
						sv--;
						continue;
					}
				}
				if (num_ra > 0)
				{
					if (rabbit[sv].get_hp() > 0)
					{
						if (rabbit[sv].get_bd() == 3)
						{
							screen[rabbit[sv].get_x() - 1][rabbit[sv].get_y() - 1] = 'R';
							Rabbit temp_ra(rabbit[sv].get_x(), rabbit[sv].get_y(), screen);
							if (temp_ra.get_cb())
							{
								if (screen[temp_ra.get_x() - 1][temp_ra.get_y() - 1] == '0')
								{
									pit_ra++;
									rabbit[sv].set_bd();
								}
								else
								{
									num_ra++;
									screen[temp_ra.get_x() - 1][temp_ra.get_y() - 1] = 'R';
									temp_ra.griding(screen);
									rabbit.push_back(temp_ra);
									bd_ra++;
									rabbit[sv].set_bd();
								}
							}
						}
					}
				}
			}
		}
		temp_ti = num_ti;
		for (int ua = 0; ua < temp_ti; ua++)
		{
			int tiger_eat_index;
			tiger[ua].check_move();
			tiger[ua].move();
			for (int yc = 0; yc < 20; yc++)
			{
				for (int yb = 0; yb < 20; yb++)
					screen[yc][yb] = '-';
			}
			screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';
			for (int ka = 0; ka < num_gr; ka++)
				screen[grass[ka].get_x() - 1][grass[ka].get_y() - 1] = '*';

			screen[hunter.get_x() - 1][hunter.get_y() - 1] = 'H';

			for (int cq = 0; cq < num_pit; cq++)
				screen[pit[cq].get_x() - 1][pit[cq].get_y() - 1] = 'O';

			for (int y = 0; y < num_ra; y++)
				screen[rabbit[y].get_x() - 1][rabbit[y].get_y() - 1] = 'R';
			for (int kg = 0; kg < ua; kg++)
				screen[tiger[kg].get_x() - 1][tiger[kg].get_y() - 1] = 'T';

			for (int kf = 0; kf < num_ti; kf++)
				tiger[kf].griding(screen);

			if (tiger[ua].get_cr() == 1)
			{
				for (int yf = 0; yf < num_ra; yf++)
				{
					if (rabbit[yf].get_x() == tiger[ua].get_x() && rabbit[yf].get_y() == tiger[ua].get_y())
					{
						tiger_eat_index = yf;
						break;
					}
				}
				rabbit.erase(rabbit.begin() + tiger_eat_index);
				tiger[ua].set_cr();
				tiger[ua].set_hp(2);
				num_ra--;
				kill_ra++;
			}
			if (num_ti > 0)
			{
				if (tiger[ua].get_hp() == 0)
				{
					tiger.erase(tiger.begin() + ua);
					num_ti--;
					temp_ti--;
					star_ti++;
					ua--;
					continue;
				}
				if (num_ti > 0)
				{
					if (screen[tiger[ua].get_x() - 1][tiger[ua].get_y() - 1] == 'O')
					{
						tiger.erase(tiger.begin() + ua);
						pit_ti++;
						num_ti--;
						temp_ti--;
						ua--;
						continue;
					}
				}
				if (num_ti > 0)
				{
					if (tiger[ua].get_hp() > 0)
					{
						if (tiger[ua].get_bd() == 4)
						{
							Tiger temp_ti(tiger[ua].get_x(), tiger[ua].get_y(), screen);
							if (temp_ti.get_cb())
							{
								if (screen[temp_ti.get_x() - 1][temp_ti.get_y() - 1] == 'O')
								{
									pit_ti++;
									tiger[ua].set_bd();
								}
								else
								{
									num_ti++;
									screen[temp_ti.get_x() - 1][temp_ti.get_y() - 1] = 'T';
									temp_ti.griding(screen);
									tiger.push_back(temp_ti);
									bd_ti++;
									tiger[ua].set_bd();
								}
							}
						}
					}
				}
			}
		}
		runtime++;
	}
	return 0;
}

int get_num(string input) //error handling function and return int that change string to int
{
	bool error_flag;
	int num = 0;
	string str_num;

	while (true)
	{
		error_flag = false;
		cout << "Enter initial number of " << input << "s : ";
		cin >> str_num;

		for (int i = 0; i < str_num.size(); i++)
			if (!((int(str_num[i]) >= int('0')) && (int(str_num[i]) <= int('9')))) error_flag = true;

		if (error_flag == false) break;
	}

	for (int j = 0; j < str_num.size(); j++)
		num = num + (int(str_num[j]) - 48) * pow(10, str_num.size() - j - 1);

	return num;
}