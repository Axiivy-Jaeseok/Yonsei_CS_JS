#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// 변수 선언
	double a, b, c, x1, x2, d;

	// 사용자 입력
	cin >> a >> b >> c;;

	// 판별식 계산
	d = b * b - 4 * a*c;

	// 판별식이 0보다 크면 두 실근이 존재하므로 두 실근값
	// 계산 후 대소비교하여 출력
	if (d > 0) {
		x1 = ((-b) + sqrt(d)) / (2 * a);
		x2 = ((-b) - sqrt(d)) / (2 * a);

		if (x1 < x2) cout << x1 << ', ' << x2 << endl;
		else cout << x2 << ", " << x1 << endl;
	}
	
	// 판별식이 0이면 중근이므로 하나의 실근만 출력
	else if (d == 0) {
		x1 = (-b) / (2 * a);
		cout << x1 << endl;
	}

	// 판별식이 0보다 작으면 실근이 없으므로 실근 없다고 출력
	else cout << "No real roots" << endl;

	return 0;
}