#include <bits/stdc++.h>
using namespace std;

long long PE010(long long num) {
	long long res = 0;
	vector<bool> sieve(num, false);
	for (long long i = 2; i < num; i ++) {
		if (!sieve[i]) {
			res += i;
			for (long long j = i * i; j < num; j += i) {
				sieve[j] = true;
			}
		}
	}
	return res;
}