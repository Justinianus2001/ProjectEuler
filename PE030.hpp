#include <bits/stdc++.h>
using namespace std;

int PE030(int num) {
	int res = 0, range = 1;
	function<int(int, int)> sumPow = [] (int num, int exp) {
		int res = 0;
		while (num) {
			res += pow(num % 10, exp);
			num /= 10;
		}
		return res;
	};
	while (range * pow(9, num) >= pow(10, range - 1)) {
		range ++;
	}
	range *= pow(9, num);
	for (int i = 2; i <= range; i ++) {
		if (sumPow(i, num) == i) {
			res += i;
		}
	}
	return res;
}