#include <bits/stdc++.h>
using namespace std;

int PE041() {
	int res = 0;
	string str = "123456789";
	function<bool(int)> isPrime = [] (int val) {
		for (int i = 2; i * i <= val; i += 1 + (i != 2)) {
			if (!(val % i)) {
				return false;
			}
		}
		return val > 1;
	};
	for (int i = 1; i < 10; i ++) {
		string s = str.substr(0, i);
		do {
			int num = stoi(s);
			if (isPrime(num)) {
				res = max(res, num);
			}
		} while (next_permutation(begin(s), end(s)));
	}
	return res;
}