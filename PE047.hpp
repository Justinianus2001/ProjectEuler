#include <bits/stdc++.h>
using namespace std;

int PE047(int num) {
	int cur = 0;
	function<int(int)> getDifDiv = [] (int num) {
		int res = 0;
		for (int i = 2; i * i <= num; i += 1 + (i != 2)) {
			if (!(num % i)) {
				res ++;
				while (!(num % i)) {
					num /= i;
				}
			}
		}
		res += num != 1;
		return res;
	};
	for (int i = 2; ; i ++) {
		if (getDifDiv(i) == num) {
			cur ++;
			if (cur == num) {
				return i - num + 1;
			}
		} else {
			cur = 0;
		}
	}
	return -1;
}