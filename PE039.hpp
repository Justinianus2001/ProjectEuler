#include <bits/stdc++.h>
using namespace std;

int PE039(int num) {
	int res = 0, mx = 0;
	vector<int> cnt(num + 1);
	for (int m = 2; m * m <= num; m ++) {
		for (int n = 1 + (m & 1); n < m; n ++) {
			if (__gcd(n, m) == 1) {
				int s = m * (m + n) * 2;
				for (int mul = 1; s * mul <= num; mul ++) {
					cnt[s * mul] ++;
				}
			}
		}
	}
	for (int i = 12; i <= num; i ++) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			res = i;
		}
	}
	return res;
}