#include <bits/stdc++.h>
using namespace std;

int PE035(int num) {
	int res = 0;
	unordered_map<int, bool> ok;
	function<vector<int>(int)> sievePrime = [&] (int num) {
		vector<int> res;
		vector<bool> sieve(num);
		for (long long i = 2; i < num; i += 1 + (i != 2)) {
			if (!sieve[i]) {
				res.push_back(i);
				for (long long j = i * i; j < num; j += i) {
					sieve[j] = true;
				}
			}
		}
		return res;
	};
	vector<int> primes = sievePrime(num);
	for (int prime: primes) {
		if (ok[prime]) {
			res ++;
		} else {
			int len = to_string(prime).length(), val = prime;
			for (int i = 1; i < len; i ++) {
				val = (val % (int)pow(10, len - 1)) * 10 + val / (int)pow(10, len - 1);
				if (!binary_search(begin(primes), end(primes), val)) {
					goto END;
				}
			}
			res ++;
			for (int i = 1; i < len; i ++) {
				val = (val % (int)pow(10, len - 1)) * 10 + val / (int)pow(10, len - 1);
				ok[val] = true;
			}
			END:;
		}
	}
	return res;
}