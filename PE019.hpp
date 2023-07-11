#include <bits/stdc++.h>
using namespace std;

int PE019(int d1, int m1, int y1, int d2, int m2, int y2) {
	int res = 0, d = 1, m = 1, y = 1900, date = 2;
	bool cnt = false;
	function<bool(int)> isLeapYear = [] (int year) {
		return (!(year % 4) && year % 100) || !(year % 400);
	};
	function<int(int, int)> getDays = [&] (int month, int year) {
		vector<int> days = {0, 31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		return days[month];
	};
	do {
		if (d == d1 && m == m1 && y == y1) {
			cnt = true;
		}
		res += d == 1 && date == 1 && cnt;
		d ++;
		if (d > getDays(m, y)) {
			d = 1;
			m ++;
		}
		if (m > 12) {
			y ++;
			m = 1;
		}
		date = (date % 7) + 1;
	} while (d != d2 || m != m2 || y != y2);
	return res;
}