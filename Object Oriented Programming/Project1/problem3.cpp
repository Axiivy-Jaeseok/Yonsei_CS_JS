# include <iostream>

using namespace std;

int main()
{
	// 변수 선언
	// 10^18을 수용하기 위해서는 정수 변수의 크기가
	// 8바이트 이상이어야 하므로 __int64 자료형 변수 선언
	__int64 num;

	// 합 계산 변수 선언
	int sum = 0;

	// 사용자 입력
	cin >> num;

	// 입력된 수를 10으로 나눈 나머지를 sum 하고
	// num을 다시 10으로 나눠서 num >= 10까지 반복
	while (num >= 10)
	{
		sum = sum + (num % 10);
		num = (num / 10);
	}

	// 나머지 남은 수를 더하는 과정
	sum += num;

	// 결과 출력
	cout << sum << endl;
}