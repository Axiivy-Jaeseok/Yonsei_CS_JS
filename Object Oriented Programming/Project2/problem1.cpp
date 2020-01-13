#include <iostream>

using namespace std;

int main() {
// define variable
	char num[50];
	int i, j, k, count, multi;
	int checking_1 = 0;
	__int64 output_num = 0;
	__int64 pow;
	int l = 1;

// user input
	cin >> count;
	for (i = 0; i <= count; i++) {
		cin >> num[i];

// check the number of 1
		if (num[i] == '1') checking_1 += 1;
	}

// compare the number of 1 between checking_1 and (e or o)
	if (checking_1 % 2 == 0 && num[i-1] == 'o') num[i-1] = '0';
	else if (checking_1 % 2 == 1 && num[i-1] == 'e') num[i-1] = '1';

// translate the number to decimal number
	for (j=i-1; j >= 0; j--) {
		pow = 1;
		for (k=0; k<l-1; k++) pow *= 2;
		if (num[j] == '1') multi = 1;
		else multi = 0;
		output_num = output_num + pow * multi;
		l++;
	}

// output
	cout << output_num << endl;

	return 0;
}