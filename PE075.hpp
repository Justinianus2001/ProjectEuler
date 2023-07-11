#include <bits/stdc++.h>
using namespace std;

int PE075(int num) {
	int res = 0;
	vector<int> cnt(num + 1);
	for (int m = 2; m * m <= num; m ++) {
		for (int n = 1; n < m; n ++) {
			if ((m + n) & 1 && __gcd(m, n) == 1) {
				int a = m * m - n * n, b = m * n * 2, c = m * m + n * n, sum = a + b + c;
				for (int mul = 1; sum * mul <= num; mul ++) {
					cnt[sum * mul] ++;
				}
			}
		}
	}
	for (int i = 12; i <= num; i ++) {
		res += cnt[i] == 1;
	}
	return res;
}