#include <iostream>

using namespace std;

int max_m(int** mat, int n) {
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //

	// set the ret as mat[0][0]
	ret = mat[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
	// finding the max value of mat
			if (ret < mat[i][j]) ret = mat[i][j];

	// ****************************** //

	return ret;
}

int min_m(int** mat, int n) {
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //

	// set the ret as mat[0][0]
	ret = mat[0][0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// finding the min value of mat
			if (ret > mat[i][j]) ret = mat[i][j];

	// ****************************** //

	return ret;
}

int sum_m(int** mat, int n) {
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //

	// set the ret as zero
	ret = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			// sum of all values in mat
			ret += mat[i][j];

	// ****************************** //

	return ret;
}

int** transpose_m(int** mat, int n) {
	int** ret;
	ret = new int*[n];
	for (int i = 0; i < n; i++)
		ret[i] = new int[n];

	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: the matrix you have to store value of your answer. you can regard it as ret[n][n] in your function
	*/

	// ****** insert your code ****** //

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
	// transpose the matrix
			ret[i][j] = mat[j][i];

	// ****************************** //

	return ret;
}

int** mul_m(int** mat1, int** mat2, int n) {
	int** ret;
	ret = new int*[n];
	for (int i = 0; i < n; i++)
		ret[i] = new int[n];

	/*
	Information of variables:
		mat1: the first matrix. you can regard it as mat1[n][n] in your function.
		mat2: the second matrix. you can regard it as mat2[n][n] in your function.
		ret: the matrix you have to store value of your answer. you can regard it as ret[n][n] in your function
	*/

	// ****** insert your code ****** //

	// define sum
	int sum;
	// calculate the multiple of mat1 and mat2, input the value of to ret
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum = 0;
			for (int k = 0; k < n; k++) {
				sum += (mat1[j][k] * mat2[k][i]);
			}
			ret[j][i] = sum;
		}
	}

	// ****************************** //

	return ret;
}


//*********************************************************//
//************ DON'T TOUCH ANYTHING BELOW HERE ************//
//*********************************************************//

void print_matrix(int** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	int n;
	int** mat1;
	int** mat2;
	int** sol;

	// take inputs
	cout << "*inputs are two NxN matrices*" << endl;
	cout << "n: ";
	cin >> n;

	// allocate memory to pointers
	mat1 = new int*[n];
	mat2 = new int*[n];

	for (int i = 0; i < n; i++) {
		mat1[i] = new int[n];
		mat2[i] = new int[n];
	}

	// take matrice
	cout << "matrix 1: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat1[i][j];

	cout << "matrix 2: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mat2[i][j];

	// max value of a matrix
	cout << "max of matrix 1: " << max_m(mat1, n) << endl;
	cout << "max of matrix 2: " << max_m(mat2, n) << endl;
	// min value of a matrix
	cout << "min of matrix 1: " << min_m(mat1, n) << endl;
	cout << "min of matrix 2: " << min_m(mat2, n) << endl;
	// sum of a matrix
	cout << "sum of matrix 1: " << sum_m(mat1, n) << endl;
	cout << "sum of matrix 2: " << sum_m(mat2, n) << endl;
	// matrix transposition
	cout << "transposed matrix 1: " << endl;
	print_matrix(transpose_m(mat1, n), n);
	cout << "transposed matrix 2: " << endl;
	print_matrix(transpose_m(mat2, n), n);
	// matrix multiplication
	cout << "multiplication of matrices: " << endl;
	sol = mul_m(mat1, mat2, n);
	print_matrix(sol, n);

	return 0;
}