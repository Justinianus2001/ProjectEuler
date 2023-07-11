#include <bits/stdc++.h>
using namespace std;

int PE077(int num) {
	vector<int> dp(num << 1 | 1);
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
	vector<int> primes = sievePrime(num << 1);
	dp[0] = 1;
	for (int prime: primes) {
		for (int i = prime; i <= num; i ++) {
			dp[i] += dp[i - prime];
		}
	}
	for (int i = 1; i <= num << 1; i ++) {
		if (dp[i] > num) {
			return i;
		}
	}
	return -1;
}