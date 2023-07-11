#include <bits/stdc++.h>
using namespace std;

long long PE048(int num, int last) {
	long long res = 0, powLast = pow(10, last);
	function<long long(long long, long long, long long)> mulMod = [] (long long a, long long b, long long mod) {
		long long res = 0;
		while (b) {
			if (b & 1) {
				res = (res + a) % mod;
			}
			a = (a << 1) % mod;
			b >>= 1;
		}
		return res;
	};
	function<long long(long long, long long, long long)> powMod = [&] (long long base, long long exp, long long mod) {
		long long res = 1;
		while (exp) {
			if (exp & 1) {
				res = mulMod(res, base, mod);
			}
			base = mulMod(base, base, mod);
			exp >>= 1;
		}
		return res;
	};
	for (int i = 1; i <= num; i ++) {
		res = (res + powMod(i, i, powLast)) % powLast;
	}
	return res;
}