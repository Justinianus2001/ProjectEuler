#include <bits/stdc++.h>
using namespace std;

int PE007(int num) {
	int res = 0;
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 2; num > 0; i += 1 + (i != 2)) {
		if (isPrime(i)) {
			num --;
			res = i;
		}
	}
	return res;
}