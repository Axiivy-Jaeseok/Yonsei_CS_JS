# include <iostream>
# include <cmath>

using namespace std;

int main()
{
	// 변수 선언
	int num, max;

	// 사용자 입력
	cin >> num;

	// 최대로 한줄에 출력해야하는 별의 수 계산
	max = (int)sqrt((double)(2 * num - 1));

	// max == 행의 수 이므로 행의 반목이 max/2와 같아질 때까지
	// 반복 후 별과 우물정자 출력
	for (int i = 0; i <= (max / 2); i++) {
		for (int j = 0; j < max / 2 - i; j++) cout << "#";
		for (int k = 0; k < 2 * i + 1; k++) cout << "*";
		for (int l = 0; l < max / 2 - i; l++) cout << "#";
		cout << endl;
	}
	
	// max+1 행부터 다시 i의 값을 감소시키며 i가 0보다 크거나
	// 같을 때까지 별과 우물정자 출력
	for (int i = (max/2)-1; i >= 0; i--) {
		for (int j = 0; j < max / 2 - i; j++) cout << "#";
		for (int k = 0; k < 2 * i + 1; k++) cout << "*";
		for (int l = 0; l < max / 2 - i; l++) cout << "#";
		cout << endl;
	}

	return 0;

}