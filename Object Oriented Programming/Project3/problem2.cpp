#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// class declaration
class Mcdonalds {
private:
	string account[100][2];
	int ord_history[100][10];
	int acc_size = 0;
	string menu_name[9];
	int price[9];

public:
	void starts_menu();
	void sign_up();
	void show_menu();
	void order();
	void order_condition();
	void refund();
	void call_menu_name();
	void set_array_zero();
};

void Mcdonalds::set_array_zero() {
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 10; j++)
			ord_history[i][j] = 0;
}

void Mcdonalds::call_menu_name() {
	menu_name[1] = "Hamburger";
	menu_name[2] = "Cheeseburger";
	menu_name[3] = "Big Mac";
	menu_name[4] = "Double Quarter Cheese";
	menu_name[5] = "Fries";
	menu_name[6] = "Chicken McNuggets";
	menu_name[7] = "Quarter Pounder Cheese";
	menu_name[8] = "Coke";

	price[1] = 1000;
	price[2] = 1500;
	price[3] = 3000;
	price[4] = 5000;
	price[5] = 1500;
	price[6] = 2000;
	price[7] = 4000;
	price[8] = 1500;
}

void Mcdonalds::starts_menu() {

	// show the main menu
	cout << "-----------------------------------" << endl;
	cout << "-----Mcdonalds Delivery System-----" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "1. Sign up\n2. Show Menu\n3. Order\n";
	cout << "4. Order condition\n5. Refund\n6. Exit\n";
	cout << "Select -> ";
}

void Mcdonalds::sign_up() {
	string id;

	while (true) {
		bool check_flag = true;

		// get the id
		cout << "Input your ID(0-to main menu) : ";
		cin >> id;

		if (id == "0") return;

		if (acc_size == 0) break;

		// confirm that id already exist in account array
		else {
			for (int j = 0; j < acc_size; j++)
				if (account[j][0] == id) {
					check_flag = false;
					cout << "Duplicated user" << endl;
				}
		}

		if (check_flag) break;
	}

	// get the password and initial money
	cout << "Input your password : ";
	cin >> account[acc_size][1];
	cout << "Input your Initial Money : ";
	cin >> ord_history[acc_size][0];
	account[acc_size][0] = id;
	cout << "Welcome, " << account[acc_size][0] << endl << endl;
	acc_size++;
}

void Mcdonalds::show_menu() {

	// show the mcdonalds menu
	cout << "----------Mcdonalds Menu ----------" << endl;
	cout << "1. Hamburger                  - 1000" << endl;
	cout << "2. Cheeseburger               - 1500" << endl;
	cout << "3. Big Mac                    - 3000" << endl;
	cout << "4. Double Quarter Cheese      - 5000" << endl;
	cout << "5. Fries                      - 1500" << endl;
	cout << "6. Chicken McNuggets          - 2000" << endl;
	cout << "7. Quarter Pounder Cheese     - 4000" << endl;
	cout << "8. Coke                       - 1500" << endl << endl;

}


void Mcdonalds::order() {
	int menu, num;

	// variable definition
	string id, pw;
	bool check_id = false;
	bool check_pw = false;
	int id_num;

	// get the id from user
	while (true) {
		cout << "Input your ID(0-to main menu) : ";
		cin >> id;

		// if user input zero, back to the main-menu
		if (id == "0") return;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][0] == id) {
				id_num = j;
				check_id = true;
				break;
			}
		}
		if (check_id == true) break;

		cout << "There's no ID" << endl;
	}

	// get the password from user
	while (true) {
		cout << "Input your password : ";
		cin >> pw;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][1] == pw) {
				check_pw = true;
				break;
			}
		}
		if (check_pw == true) break;

		cout << "You input the wrong password!" << endl;
	}

	while (ord_history[id_num][0] >= 0) {
		cout << "Select menu number(0-to main menu) : ";
		cin >> menu;

		if (menu == 0) {
			break;
		}

		cout << "How many" << " '" << menu_name[menu] << "' " << "do you want : ";
		cin >> num;
		cout << endl;

		if (price[menu] * num > ord_history[id_num][0]) cout << "Over budget" << endl;
		else {
			ord_history[id_num][menu] = num;
			ord_history[id_num][0] -= num * price[menu];
		}
	}

	int w = 1;
	for (int k = 1; k < 9; k++) {
		if (ord_history[id_num][k] != 0) {
			cout << w << " '" << menu_name[k] << "' :" << ord_history[id_num][k] << endl;
			w++;
		}
	}
	int total_money = 0;
	for (int k = 1; k < 9; k++) {
		if (ord_history[id_num][k] != 0) {
			total_money += ord_history[id_num][k] * price[k];
		}
	}

	cout << "Your total purchase amout is " << total_money << endl;
	cout << "The balance is " << ord_history[id_num][0] << endl;
	cout << "Thanks" << endl << endl;

}

void Mcdonalds::order_condition() {

	// variable definition
	string id, pw;
	bool check_id = false;
	bool check_pw = false;
	int id_num;

	// get the id from user
	while (true) {
		cout << "Input your ID(0-to main menu) : ";
		cin >> id;

		// if user input zero, back to the main-menu
		if (id == "0") return;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][0] == id) {
				id_num = j;
				check_id = true;
				break;
			}
		}
		if (check_id == true) break;
		cout << "There's no ID" << endl;
	}

	// get the password from user
	while (true) {
		cout << "Input your password : ";
		cin >> pw;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][1] == pw) {
				check_pw = true;
				break;
			}
		}
		if (check_pw == true) break;
		cout << "You input the wrong password!" << endl;
	}

	int w = 1;
	for (int k = 1; k < 9; k++) {
		if (ord_history[id_num][k] != 0) {
			cout << w << " '" << menu_name[k] << "' :" << ord_history[id_num][k] << endl;
			w++;
		}
	}
	int total_money = 0;
	for (int k = 1; k < 9; k++) {
		if (ord_history[id_num][k] != 0) {
			total_money += ord_history[id_num][k] * price[k];
		}
	}

	cout << "Your total purchase amout is " << total_money << endl;
	cout << "The balance is " << ord_history[id_num][0] << endl;
	cout << "Thanks" << endl << endl;
}

void Mcdonalds::refund() {
	int refund_num;
	int refund_money;

	// variable definition
	string id, pw;
	bool check_id = false;
	bool check_pw = false;
	int id_num;

	// get the id from user
	while (true) {
		cout << "Input your ID(0-to main menu) : ";
		cin >> id;

	// if user input zero, back to the main-menu
		if (id == "0") return;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][0] == id) {
				id_num = j;
				check_id = true;
				break;
			}
		}
		if (check_id == true) break;
		cout << "There's no ID" << endl;
	}

	// get the password from user
	while (true) {
		cout << "Input your password : ";
		cin >> pw;

		for (int j = 0; j < acc_size; j++) {
			if (account[j][1] == pw) {
				check_pw = true;
				break;
			}
		}
		if (check_pw == true) break;

		cout << "You input the wrong password!" << endl;
	}

	while (true) {

		int w = 1;
		for (int k = 1; k < 9; k++) {
			if (ord_history[id_num][k] != 0) {
				cout << w << " '" << menu_name[k] << "' :" << ord_history[id_num][k] << endl;
				w++;
			}
		}
		int total_money = 0;
		for (int k = 1; k < 9; k++) {
			if (ord_history[id_num][k] != 0) {
				total_money += ord_history[id_num][k] * price[k];
			}
		}

		cout << "Your total purchase amout is " << total_money << endl;
		cout << "The balance is " << ord_history[id_num][0] << endl;

		while (true) {
			cout << "Choose number(0 - to main menu) : ";
			cin >> refund_num;

			if (refund_num == 0) return;
			if (refund_num > 0 && refund_num <= w) {
				cout << "Successfully refunded" << endl << endl;
				break;

			}

			cout << "Wrong Input!" << endl;
		}

		int u = 0;
		for (int k = 1; k < 9; k++) {
			if (ord_history[id_num][k] != 0) {
				u++;
				if (u == refund_num) {
					refund_money = ord_history[id_num][k] * price[k];
					ord_history[id_num][k] = 0;
					ord_history[id_num][0] += refund_money;
				}
			}
		}
	}
	cout << "Your total purchase amout is " << refund_money << endl;
	cout << "The balance is " << ord_history[id_num][0] << endl;

}

int main() {
	Mcdonalds MC;
	char c;

	MC.call_menu_name();
	MC.set_array_zero();

	while (true) {
		MC.starts_menu();

		cin >> c;
		switch (c) {
		case '1':
			MC.sign_up();
			break;
		case '2':
			MC.show_menu();
			break;
		case '3':
			MC.order();
			break;
		case '4':
			MC.order_condition();
			break;
		case '5':
			MC.refund();
			break;
		case '0':
			return 0;

		}
	}

	return 0;
}