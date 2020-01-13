#include <iostream>

using namespace std;

float min(float* value);
float max(float* value);
float avg(float* value);
float sum(float* value);


int main() {
// define variable
	float input[10];
	float min_out, max_out, avg_out, sum_out;

// set the cout as print the hundreth
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

// user input the 10 values
	for (int i = 0; i < 10; i++) cin >> input[i];

// call the function
	min_out = min(input);
	max_out = max(input);
	avg_out = avg(input);
	sum_out = sum(input);

// output
	cout << "min: " << min_out << endl;
	cout << "max: " << max_out << endl;
	cout << "avg: " << avg_out << endl;
	cout << "sum: " << sum_out << endl;

	return 0;
}

float min(float* value) {
	float min_v;
	min_v = value[0];

// find the min value
	for (int i = 0; i < 10; i++) 
		if (min_v >= value[i]) min_v = value[i];

	return min_v;
}

float max(float* value) {
	float max_v;
	max_v = value[0];

// fine the max value
	for (int i = 0; i < 10; i++)
		if (max_v <= value[i]) max_v = value[i];

	return max_v;
}

float avg(float* value) {
	float total = 0;

// sum the total value
	for (int i = 0; i < 10; i++)
		total += value[i];

// devide as 10 
	return (total/10);
}

float sum(float* value) {
	float sum = 0;

// sum the total value
	for (int i = 0; i < 10; i++)
		sum += value[i];

	return sum;
}