#include <bits/stdc++.h>
using namespace std;

int PE027(int num) {
	int res = 0, mx = 0;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int a = -num + 1; a < num; a ++) {
		for (int b = -num; b <= num; b ++) {
			int n = 0;
			while (true) {
				int val = n * n + a * n + b;
				if (val < 2 || !isPrime(val)) {
					break;
				}
				n ++;
			}
			if (n > mx) {
				mx = n;
				res = a * b;
			}
		}
	}
	return res;
}