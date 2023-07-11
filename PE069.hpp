#include <bits/stdc++.h>
using namespace std;

int PE069(int num) {
	int res = 1;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 2; res * i <= num; i ++) {
		if (isPrime(i)) {
			res *= i;
		}
	}
	return res;
}