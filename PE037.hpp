#include <bits/stdc++.h>
using namespace std;

int PE037(int num) {
	int res = 0, cnt = 0;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 11; cnt < num; i += 2) {
		if (isPrime(i)) {
			int len = to_string(i).length();
			for (int j = 1; j < len; j ++) {
				if (!isPrime(i / (int)pow(10, j)) || !isPrime(i % (int)pow(10, len - j))) {
					goto END;
				}
			}
			res += i;
			cnt ++;
			END:;
		}
	}
	return res;
}