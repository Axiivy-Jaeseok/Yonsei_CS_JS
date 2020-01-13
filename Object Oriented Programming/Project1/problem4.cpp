# include <iostream>

using namespace std;

int main()
{
	// 변수 선언
	int year, month, day, year_100, year_200, year_300, month_100, month_200, month_300, day_100, day_200, day_300;

	// 반복문 변수 선언
	int i = 0;

	// 사용자 입력
	cin >> year >> month >> day;

	// 반복문 들어가기 (300번 day를 더하는 과정 거침)
	while (i < 300) {
		if (i == 99) {

	// 100일을 더하게 되면 그 년도, 월일 저장
			year_100 = year;
			month_100 = month;
			day_100 = day;
		}

		if (i == 199) {
	// 200일을 더하게 되면 그 년도, 월일 저장
			year_200 = year;
			month_200 = month;
			day_200 = day;
		}

		if (i == 299) {
	// 300일을 더하게 되면 그 년도, 월일 저장
			year_300 = year;
			month_300 = month;
			day_300 = day;
		}


	// 일을 더하는 과정
		day += 1;

	// 1,3,5,7,8,10,12월이면 32일이 되면 1달을 증가하고 일을 1로 바꿈.
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day == 32) {
				month += 1;
				day = 1;
			}
		}

	// 4,6,9,11월이면 31일이 되면 1달을 증가하고 일을 1로 바꿈.
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 31) {
				month += 1;
				day = 1;
			}
		}

	// 2월이면 윤년이면 30일이 되면 1달을 증가하고 일을 1로 바꾸고, 아니면 29일이 되면 같은 과정을 거침.
		if (month == 2) {
			if (year % 4 == 0) {
				if (year % 100 == 0) {
					if (year % 400 == 0) {
						if (day == 30) {
							month += 1;
							day = 1;
						}
					}
					else {
						if (day == 29) {
							month += 1;
							day = 1;
						}
					}
				}
				else {
					if (day == 30) {
						month += 1;
						day = 1;
					}
				}
			}
			else {
				if (day == 29) {
					month += 1;
					day = 1;
				}
			}
		}

	// 13월이 되면 년을 1을 증가시키고 월을 1로 바꿈.
		if (month == 13) {
			year += 1;
			month = 1;
		}
		i++;
	}

	// 결과 출력하는 과정.
	if (month_100 < 10 && day_100 < 10) cout << "100: " << year_100 << " 0" << month_100 << " 0" << day_100 << endl;
	if (month_100 < 10 && day_100 >= 10) cout << "100: " << year_100 << " 0" << month_100 << " " << day_100 << endl;
	if (month_100 >= 10 && day_100 < 10) cout << "100: " << year_100 << " " << month_100 << " 0" << day_100 << endl;
	if (month_100 >= 10 && day_100 >= 10) cout << "100: " << year_100 << " " << month_100 << " " << day_100 << endl;

	if (month_200 < 10 && day_200 < 10) cout << "200: " << year_200 << " 0" << month_200 << " 0" << day_200 << endl;
	if (month_200 < 10 && day_200 >= 10) cout << "200: " << year_200 << " 0" << month_200 << " " << day_200 << endl;
	if (month_200 >= 10 && day_200 < 10) cout << "200: " << year_200 << " " << month_200 << " 0" << day_200 << endl;
	if (month_200 >= 10 && day_200 >= 10) cout << "200: " << year_200 << " " << month_200 << " " << day_200 << endl;

	if (month_300 < 10 && day_300 < 10) cout << "300: " << year_300 << " 0" << month_300 << " 0" << day_300 << endl;
	if (month_300 < 10 && day_300 >= 10) cout << "300: " << year_300 << " 0" << month_300 << " " << day_300 << endl;
	if (month_300 >= 10 && day_300 < 10) cout << "300: " << year_300 << " " << month_300 << " 0" << day_300 << endl;
	if (month_300 >= 10 && day_300 >= 10) cout << "300: " << year_300 << " " << month_300 << " " << day_300 << endl;


	return 0;
	
}