#include <bits/stdc++.h>
using namespace std;

int PE004(int num) {
	int res = 0, from = pow(10, num - 1), to = pow(10, num);
	function<bool(int)> isPalind = [] (int val) {
		int revVal = 0, temp = val;
		while (temp) {
			revVal = revVal * 10 + (temp % 10);
			temp /= 10;
		}
		return val == revVal;
	};
	for (int i = from; i < to; i ++) {
		for (int j = i + 1; j < to; j ++) {
			if (isPalind(i * j)) {
				res = max(res, i * j);
			}
		}
	}
	return res;
}