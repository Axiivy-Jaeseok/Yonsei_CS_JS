#include <iostream>

using namespace std;

int main() {
// define the variables
	int num;
	int a_index = 0; int b_index = 0;
	int a_score = 0; int b_score = 0;

	int a_nlist[10000], b_nlist[10000];

// get the num
	cin >> num;

// user input the value list
	for(int i = 0; i < num; i++) cin >> a_nlist[i];
	for(int i = 0; i < num; i++) cin >> b_nlist[i];

// count the score and compare the value
	while (a_index < num && b_index < num) {
		if (a_nlist[a_index] > b_nlist[b_index]) {
			a_score += 1;
			a_nlist[a_index] = a_nlist[a_index] - b_nlist[b_index];
			b_index++;
		}
		else if (a_nlist[a_index] == b_nlist[b_index]) {
			a_index++;
			b_index++;
		}
		else {
			b_score += 1;
			b_nlist[b_index] = b_nlist[b_index] - a_nlist[a_index];
			a_index++;
		}
	}

// output
	cout << a_score << ' ' << b_score << endl;

	return 0;
}