#include <iostream>
#include <cstring>

using namespace std;

class Calculator {
public:
	Calculator();
	Calculator(int num, char type);
	void setNum(char arr[], int size, char type);
	friend const Calculator operator+(const Calculator& ref1, const Calculator& ref2);
	friend const Calculator operator-(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator>(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator<(const Calculator& ref1, const Calculator& ref2);
	friend const bool operator==(const Calculator& ref1, const Calculator& ref2);
	friend ostream& operator <<(ostream& outputStream, const Calculator& ref);
	int getNum();

private:
	int num;
	char type;
};

int main() {
	char op_num;
	bool flag1, flag2, flag3, flag4;
	Calculator Cal1, Cal2;
	char type;
	char arr1[7], arr2[7];

	while (true) {

		// show menu
		cout << "================Menu==============="<<endl;
		cout << "1:Program start 0:program End" << endl;
		cout << "Menu Option: ";

		cin >> op_num;

		if (op_num == '0') {
			cout << "Exit the program" << endl;
			break;
		}

		else if (op_num != '1') {
			cout << "Wrong Input!" << endl;
			continue;
		}

		else {

			// get the number
			cout << "Welcome to Calculator!" << endl;
			cout << "Select the Calculator(Octal calculator(O) Hexadecimal calculator(H)) : ";
			cin >> type;
			cout << endl;

			if (type == 'O') {

				while (true) {
					flag1 = true;

					cout << "Input num1 : ";
					cin >> arr1;

					for (int i = 0; i < strlen(arr1); i++) {
						if (arr1[i] >= '8'&& arr1[i] <= '0') {
							cout << "Wrong Input!" << endl;
							flag1 = false;
							break;
						}
					}
					if (flag1 == false) continue;
					else break;
				}

				while (true) {
					flag2 = true;

					cout << "Input num1 : ";
					cin >> arr2;

					for (int i = 0; i < strlen(arr2); i++) {
						if (arr2[i] >= '8' && arr2[i] <= '0') {
							cout << "Wrong Input!" << endl;
							flag2 = false;
							break;
						}
					}
					if (flag2 == false) continue;
					else break;
				}
			}

			if (type == 'H') {

				while (true) {
					flag1 = true;

					cout << "Input num1 : ";
					cin >> arr1;

					for (int i = 0; i < strlen(arr1); i++) {
						if ((arr1[i] >= '0' && arr1[i] <= '9') || (arr1[i] >= 'A' && arr1[i] <= 'F') || (arr1[i] >= 'a' && arr1[i] <= 'f'));
						else {
							cout << "Wrong Input!" << endl;
							flag1 = false;
							break;
						}
					}
					if (flag1 == false) continue;
					else break;
				}

				while (true) {
					flag2 = true;

					cout << "Input num2 : ";
					cin >> arr2;

					for (int i = 0; i < strlen(arr2); i++) {
						if ((arr2[i] >= '0' && arr2[i] <= '9') || (arr2[i] >= 'A' && arr2[i] <= 'F') || (arr2[i] >= 'a' && arr2[i] <= 'f'));
						else {
							cout << "Wrong Input!" << endl;
							flag1 = false;
							break;
						}
					}
					if (flag2 == false) continue;
					else break;
				}
			}
		
			// set the number as decimal
			Cal1.setNum(arr1, strlen(arr1), type);
			Cal2.setNum(arr2, strlen(arr2), type);


			// output the result
			cout << endl << "1. num1 + num2 : " << Cal1 + Cal2 << endl;
			cout << "2. num1 - num2 : " << Cal1 - Cal2 << endl;
			cout << "3. num1 == num2 : " << ((Cal1 == Cal2)?"true":"false") << endl;
			cout << "4. num1 > num2 : " << ((Cal1 > Cal2)?"true":"false") << endl;
			cout << "5. num1 < num2 : " << ((Cal1 < Cal2)?"true":"false") << endl;
			cout << "6. num1: " << dec << Cal1.getNum() << " num2: " << dec << Cal2.getNum() << endl;
		
		}
	}

	return 0;
}


Calculator::Calculator() {

	//default constructor

};

Calculator::Calculator(int num, char type) {

	// specific constructor
	this->num = num;
	this->type = type;
}

int Calculator::getNum() {
	// get the num
	return num;
}

void Calculator::setNum(char arr[], int size, char type) {
	int dec_num = 0;
	int dec_list[6];
	int pow = 1;

	// transfer oct, hex to decimal

	for (int m = size-1; m >=0; m--) {
		switch (arr[m]) {
		case'1': dec_list[m] = 1;
			break;
		case'2': dec_list[m] = 2;
			break;
		case'3': dec_list[m] = 3;
			break;
		case'4': dec_list[m] = 4;
			break;
		case'5': dec_list[m] = 5;
			break;
		case'6': dec_list[m] = 6;
			break;
		case'7': dec_list[m] = 7;
			break;
		case'8': dec_list[m] = 8;
			break;
		case'9': dec_list[m] = 9;
			break;
		case'0': dec_list[m] = 0;
			break;
		case 'a':
		case'A': dec_list[m] = 10;
			break;
		case 'b':
		case'B': dec_list[m] = 11;
			break;
		case 'c':
		case'C': dec_list[m] = 12;
			break;
		case 'd':
		case'D': dec_list[m] = 13;
			break;
		case 'e':
		case'E': dec_list[m] = 14;
			break;
		case 'f':
		case'F': dec_list[m] = 15;
		}
	}

	if (type == 'O') {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				pow *= 8;
			}
			dec_num += pow * dec_list[size - 1 - i];
		}
	}

	else if (type == 'H') {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < i; j++) {
				pow *= 16;
			}
			dec_num += pow * dec_list[size - 1 - i];
		}
	}

	num = dec_num;
	this->type = type;
}

ostream& operator <<(ostream& outputStream, const Calculator& ref) {

	// devide the case to O and H
	if(ref.type == 'O') outputStream << oct;
	else if (ref.type == 'H') outputStream << hex;

	outputStream << ref.num;

	return outputStream;
}

const Calculator operator+(const Calculator& ref1, const Calculator& ref2) {
	// + operator overloading
	int return_num;
	if (ref1.type == 'H' && ref2.type == 'H') {
		return_num = ref1.num + ref2.num;

		return Calculator(return_num, 'H');
	}

	if (ref1.type == 'O' && ref2.type == 'O') {
		return_num = ref1.num + ref2.num;

		return Calculator(return_num, 'O');
	}
}

const Calculator operator-(const Calculator& ref1, const Calculator& ref2) {
	// - operator overloading
	int return_num;
	if (ref1.type == 'H' && ref2.type == 'H') {
		return_num = ref1.num - ref2.num;
		// get the 16 complement
		if (return_num < 0) return_num = 16777216 + return_num;

		return Calculator(return_num, 'H');
	}

	if (ref1.type == 'O' && ref2.type == 'O') {
		return_num = ref1.num - ref2.num;
		// get the 8 complement
		if (return_num < 0) return_num = 262144 + return_num;
		return Calculator(return_num, 'O');
	}
}

const bool operator>(const Calculator& ref1, const Calculator& ref2) {
	// compare num1 and num2
	return (ref1.num > ref2.num);
}

const bool operator<(const Calculator& ref1, const Calculator& ref2) {
	// compare num1 and num2
	return (ref1.num < ref2.num);
}

const bool operator==(const Calculator& ref1, const Calculator& ref2) {
	// check that whether the num1 and num2 is same
	return (ref1.num == ref2.num);
}