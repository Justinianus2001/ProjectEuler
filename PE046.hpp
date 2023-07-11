#include <bits/stdc++.h>
using namespace std;

int PE046() {
	vector<int> primes = {2};
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 3; ; i += 2) {
		if (isPrime(i)) {
			primes.push_back(i);
		} else {
			for (int prime: primes) {
				int val = sqrt((i - prime) >> 1);
				if (val * val * 2 + prime == i) {
					goto END;
				}
			}
			return i;
			END:;
		}
	}
	return -1;
}