#include <bits/stdc++.h>
using namespace std;

int PE050(int num) {
	int res = 0, mx = 0;
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
	vector<int> primes = sievePrime(num), prefix = primes;
	int len = primes.size();
	for (int i = 1; i < len; i ++) {
		prefix[i] += prefix[i - 1];
	}
	for (int to = 0; to < len; to ++) {
		for (int from = to - mx - 1; from >= 0 && prefix[to] - prefix[from] <= num; from --) {
			if (to - from > mx && binary_search(begin(primes), end(primes), prefix[to] - prefix[from])) {
				mx = to - from;
				res = prefix[to] - prefix[from];
			}
		}
	}
	return res;
}