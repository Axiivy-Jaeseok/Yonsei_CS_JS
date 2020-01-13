#include <iostream>
#include <string>

using namespace std;

void print_seat_state(int f_class, int b_class, int e_class) {

// show the number of left sets
	cout << "##########current vacant seats##########" << endl;
	cout << "first class: " << 5 - f_class << '/' << 5 << endl;
	cout << "business class: " << 25 - b_class << '/' << 25 << endl;
	cout << "eoconomy class: " << 50 - e_class << '/' << 50 << endl;

// print X and O that the seat of first class
	cout << "#############first class###############" << endl;
	for (int i = 0; i < f_class; i++) cout << "X";
	for (int i = 0; i < 5 - f_class; i++) cout << "O";
	cout << endl;

// print X and O that the seat of business class
	cout << "#############business class###########" << endl;
	for (int j = 0; j < b_class; j++) {
		cout << "X";
		if (j % 5 == 4) cout << endl;
	}
	for (int k = 0; k < 5 - (b_class % 5); k++) cout << "O";
	cout << endl;
	for (int l = 0; l < 25 - b_class - (5 - (b_class % 5)); l++) {
		cout << "O";
		if (l % 5 == 4) cout << endl;
	}

// print X and O that the seat of economy class
	cout << "#############economy class############" << endl;
	for (int m = 0; m < e_class; m++) {
		cout << "X";
		if (m % 5 == 4) cout << endl;
	}
	for (int n = 0; n < 5 - (e_class % 5); n++) cout << "O";
	cout << endl;
	for (int p = 0; p < 50 - e_class - (5 - (e_class % 5)); p++) {
		cout << "O";
		if (p % 5 == 4) cout << endl;
	}
}

void add_passenger(int& f_class, int& b_class, int& e_class) {

// define variable
	char grade;
	int num;

// user input grade and num
	cout << "Which type seat do you want add?(first class: 1, business_class: 2, economy_class: 3):";
	cin >> grade;
	cout << "How many passenger would you like to add?:";
	cin >> num;


// get the grade and compare that the num+reserved seat is bigger than available seat
	switch (grade) {
	case '1':
		if (num + f_class <= 5) {
			cout << "Add complete!" << endl;
			f_class += num;
		}
		else {
			cout << "full seat!" << endl;
		}
		break;
	case '2':
		if (num + b_class <= 25) {
			cout << "Add complete!" << endl;
			b_class += num;
		}
		else {
			cout << "full seat!" << endl;
		}
		break;
	case '3':
		if (num + e_class <= 50) {
			cout << "Add complete!" << endl;
			e_class += num;
		}
		else {
			cout << "full seat!" << endl;
		}
		break;
	}

}

void delete_passenger(int& f_class, int& b_class, int& e_class) {
// define variable
	char grade;
	int num;

// user input grade and num
	cout << "Which type seat do you want delete?(first class: 1, business_class: 2, economy_class: 3):";
	cin >> grade;
	cout << "How many passenger would you like to delete?:";
	cin >> num;

// get the grade and compare that the reserved seat-num is smaller than zero
	switch (grade) {
	case '1':
		if (f_class - num >= 0) {
			cout << "Delete complete!" << endl;
			f_class -= num;
		}
		else {
			cout << "Wrong Input!" << endl;
		}
		break;
	case '2':
		if (b_class - num >= 0) {
			cout << "Delete complete!" << endl;
			b_class -= num;
		}
		else {
			cout << "Wrong Input!" << endl;
		}
		break;
	case '3':
		if (e_class - num >= 0) {
			cout << "Delete complete!" << endl;
			e_class -= num;
		}
		else {
			cout << "Wrong Input!"<< endl;
		}
		break;
	}
}


void welcome() {
// show the welcome function
	cout << "#######################################\n#######Flight Reservation System#######\n#######################################\n#########1. add passenger##############\n\
#########2. delete passenger###########\n#########3. print seat state###########\n#########4. exit#######################\n#######################################" << endl;
}

int main() {

	int first_class = 0; //MAX: 5
	int business_class = 0; // MAX: 25
	int economy_class = 0; // MAX: 50

	while (true) {
		welcome();
		char menu;
		cin >> menu;
		switch (menu) {
		case '1':
			add_passenger(first_class, business_class, economy_class);
			break;
		case '2':
			delete_passenger(first_class, business_class, economy_class);
			break;
		case '3':
			print_seat_state(first_class, business_class, economy_class);
			break;
		case '4':
			cout << "end the program" << endl;
			return 0;
		default:
			cout << "Wrong Input!" << endl;
		}

	}


}