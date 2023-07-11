#include <bits/stdc++.h>
using namespace std;

int PE087(int num) {
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
	vector<int> primes = sievePrime(sqrt(num));
	for (int prime1: primes) {
		int val1 = prime1 * prime1;
		for (int prime2: primes) {
			int val2 = val1 + prime2 * prime2 * prime2;
			if (val2 < num) {
				for (int prime3: primes) {
					int val3 = val2 + prime3 * prime3 * prime3 * prime3;
					if (val3 < num) {
						ok[val3] = true;
					} else {
						break;
					}
				}
			} else {
				break;
			}
		}
	}
	return ok.size();
}