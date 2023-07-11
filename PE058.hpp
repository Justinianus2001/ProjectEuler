#include <bits/stdc++.h>
using namespace std;

int PE058(int num) {
	int prime = 0, sum = 1;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 1, step = 2; ; step += 2) {
		for (int j = 0; j < 4; j ++) {
			i += step;
			sum ++;
			prime += isPrime(i);
		}
		if ((double)prime / sum * 100 < num) {
			return step + 1;
		}
	}
	return -1;
}